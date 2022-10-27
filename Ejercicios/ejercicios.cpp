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
    //Complejidad: O(1) constante
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
    //Complejidad: O(n)
    int res = 0;
    for(int i=0; i<b.size();i++){
        if(b[i]== p){
            intercambiarValoresVector(b[i],b[b.size()-1]);
            b.pop_back();
            res++;
        }
    }
    if(res==0){
        b.push_back(p);
    }
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool perdio(tablero& t, jugadas& j) {
    //Complejidad: O(n)
    if(seJugoUnaMina(t,j)){
        return true;
    }
    else{
        return false;
    }
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool gano(tablero& t, jugadas& j) {
    //Complejidad O(n^2) ?
    return juegoGanado(posicionesSinMinas(t), j);
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    //Complejidad: O(n^8)
    if(casillaValida(p,t,b,j)){
        descubreAutomatico(p,t,b,j);
    }else{
        j.push_back(jugada(p, minasAdyacentes(t, p)));
    }
}
/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/

bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    //Complejidad: O(n^3)
    if(!perteneceAJugadas(p, j) && !perteneceABanderitas(p, b) && esAdyacente121(p, j)){
        return true;
    }
    return false;
}

