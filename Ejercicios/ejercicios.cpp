//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <stdio.h>
#include <iostream>


#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/

int minasAdyacentes(tablero& t, pos p) {
    /*
    Complejidad: O(1) constante
    Es constante ya que la cantidad de operaciones elementales es siempre la misma y no depende del tamaño del tablero. Esto se ve en los bucles "for"
    porque ambos van desde el -1 hasta el 2 (sin tener en cuenta el tamaño del tablero).
 */
    int res = 0;
    for(int i = -1; i<2;i++){
        for(int j = -1;j<2;j++){
            pos posicion_actual = {(p.first)- i,(p.second)-j};
            if(esAdyacenteValida(posicion_actual,t)&& t[posicion_actual.first][posicion_actual.second] && (i != 0 || j!=0)){
                res++;
            }
        }
    }
    return res;
}

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    /*
    Complejidad: O(|b|)
    En el peor caso realizo |b| operaciones. Porque mi programa va a hacer busqueda lineal (con el "for") sobre el vector
    banderitas, en busca de la posicion p. Suponiendo que p no está en el vector, tendria que recorrerlo hasta el final (peor caso, |b|).
    Lo anterior es casi equivalente al caso donde p está en la ultima posicion del vector b.
    */
    int res = 0;
    for(int i=0; i<b.size();i++){
        if(b[i]== p){
            intercambiarValoresVector(b[i],b[b.size()-1]);
            b.pop_back();
            res++;
        }
    }
    if(res==0){
        b.push_back(p); //O(1) amortizado
    }
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool perdio(tablero& t, jugadas& j) {
    /*
    Complejidad: O(|j|)
    seJugoUnaMina en el peor caso tiene complejidad |j|. Esta es la unica funcion que llamo en perdio, por lo que su complejidad de peor caso
    es la de seJugoUnaMina.
    */
    if(seJugoUnaMina(t,j)){
        return true;
    }
    else{
        return false;
    }
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool gano(tablero& t, jugadas& j) {
    /*
    Complejidad O(|j|^2 + |t|^2)
    
    */
    return juegoGanado(posicionesSinMinas(t), j);
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    /*
    Complejidad: O(|t|*(|b|+|j|)) (tomando la complejidad del caso recursivo en descubreAutomatico)
    El peor caso seria que la guarda del if evalue como verdadera, con casillaValida siendo O(|j|+|b|). Entonces a esta comoplejidad
    se le sumaría la de descubreAutomatico que es aproximadamente O(|t|*(|b|+|j|)). Pero como |t|*(|b|+|j|) >= |j|+|b| (por tablero valido)
    la complejidad final se puede acotar por la de descubreAutomatico.
    
    */
    if(casillaValida(p,t,b,j)&& minasAdyacentes(t, p)==0){
        j.push_back(jugada(p, minasAdyacentes(t, p)));
        descubreAutomatico(p,t,b,j);
    }else{
        j.push_back(jugada(p, minasAdyacentes(t, p)));
    }
}
/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/

bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
   /*
   Complejidad: O(|t|^2(|b|+|j|))
   Aclaracion, el tablero es cuadrado entonces |t|=|t[i]| para todo i valido. 
   La cantidad de iteraciones del primer "for" depende de |t|, a su vez el segundo "for" se va a ejecutar, en el peor caso, |t|*|t| veces 
   (ya que esta anidado en el primer "for"). Viendo la complejidad del segundo "for", las funciones perteneceAJugadas, esAdyacente121
   y perteneceABanderitas tienen complejidad de peor caso O(|j|), O(|j|) y O(|b|) respectivamente. Entonces, la complejidad de peor caso va a ser 
   (2|j|+|b|) * |t|, que seria equivalente (aproximadamente) a (|j|+|b|) * |t|.
   De ahi que la complejidad final sea de |t|^2(|b|+|j|)
   */
    for(int i = 0;i<t.size();i++){
        for(int k=0;k<t[i].size();k++){
            p = {i,k};
            if(!perteneceAJugadas(p, j) && !perteneceABanderitas(p, b) && esAdyacente121(p, j)){
                return true;
            }
        }
    }
    p = { };
    return false;
}

