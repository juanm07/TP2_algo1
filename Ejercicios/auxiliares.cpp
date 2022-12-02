//
// Este archivo contiene las definiciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con las 
// declaraciones de auxiliares.h
//

#include <iostream>

#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"
using namespace std;

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/
bool esAdyacenteValida(pos p, tablero& t){
    /*
    Complejidad O(1)
    La cantidad de operaciones elementales no depende del tamaño de t, ni de la posicion que ingrese, por lo que dicha cantidad siempre sera la misma
    y por lo tanto, tendrá una complejidad de peor caso, lineal.
    */
    int largo_tablero = t.size();
    bool res = false;
    if(coordenadaValida(p.first,largo_tablero) && coordenadaValida(p.second,largo_tablero)){
        res = true;
    }
    return res;
}

bool coordenadaValida(int c, int n){
    //Complejidad O(1)
    return (0<= c && c<n); //Serian 3 operaciones elementales ("0<=c", "&&", "c<n")
}




/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

bool perteneceABanderitas(pos p, banderitas& b){
    //Complejidad O(n)
    bool res = false;
    for(int i=0; i<b.size();i++){
        if(b[i]== p){
            res = true;
        }
    }
    return res;
}

void intercambiarValoresVector(pos& x, pos& y){
    //Complejidad O(1)
    pos temp = x;
    x = y;
    y = temp;
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/

bool seJugoUnaMina(tablero& t, jugadas& j){
    //Complejidad O(n)
    //Si n es el tamaño del vector j, en el peor caso realizo n operaciones.
    for(int i = 0; i<j.size();i++){
        pos posicionJugada = j[i].first;
        if(t[posicionJugada.first][posicionJugada.second]){
            return true;
        }
    }
    return false;
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool juegoGanado(vector<pos> p, jugadas& j){
    //Complejidad O(|p|*|j|) por perteneceAJugadas
    int res = 0;
    if(p.size() == j.size()){
        for(int i = 0; i < p.size(); i++){
            if(perteneceAJugadas(p[i], j)){
                res++;
            }
        }
    }
    return res == p.size();
}

bool perteneceAJugadas(pos p, jugadas& j){
    /*
    Complejidad O(|j|)
    La cantidad de operaciones elementales de la funcion depende de longitud de jugadas. En el peor caso, el while va a iterar |j| veces.
    Por lo tanto, la complejidad va a depender de |j|.
    */
    bool res = false;
    int i = 0;
    while(i<j.size() && !res){
        if(j[i].first == p){
            res = true;
        }
        i++;
    }
    return res;
}

vector<pos> posicionesSinMinas (tablero& t){
    /*
    Complejidad O(|t|^2)
    La cantidad de iteraciones que realiza el primer "for" depende de |t|, por lo que en el peor caso se va a ejecutar |t| veces. 
    El segundo "for" se va a ejecutar |t| veces multiplicado por |t|, ya que es un "for" anidado dentro de otro. Esto hace que la 
    complejidad total del programa sea |t|*|t|. La funcion push_back tiene complejidad O(1) (amortizado, por un tema de memoria) pero
    esto no afecta a la complejidad asintotica.
    
    */
    vector<pos> res = { };
    for(int i = 0; i < t.size(); i++) {
        for (int k = 0; k < t.size(); k++) {
            if(!t[i][k]){
                res.push_back(pos(i,k)); //O(1) amortizado
            }
        }
    }
    return res;
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void descubreAutomatico(pos p, tablero& t, banderitas& b, jugadas& j){
    //Complejidad de una sola ejecución: O(n^2) 
    // La cantidad de ejecuciones es equivalente a la cantidad de casilleros con minasAdyacentes=0. 
    // Caso base: Cuando no hay posiciones adyacentes con minasAdyacentes=0, es decir, cuando posAdy es un vector vacío.
    vector <pos> posAdy = posicionesAdyacentesSinMinas(p, t, b, j); //O(|b|+|j|)
    for(int i = 0; i < posAdy.size(); i++){
        if(!perteneceAJugadas(posAdy[i], j)){ //perteneceAjugadas tiene complejidad O(|j|). Esto segun lo interpretamos. 
            j.push_back(jugada(posAdy[i], 0));
            finalDeCamino(t, b, posAdy[i] , j); /// Si la posición tiene una adyacente con minasAdyacentes>0, se la considera final de camino y se la añade a jugadas.
            descubreAutomatico(posAdy[i], t, b, j);
        }
    }
}

vector<pos> posicionesAdyacentesSinMinas(pos p,tablero& t,banderitas& b,jugadas& j){
    /*
    Complejidad: O(|b|+|j|)
    Por casillaValida que tiene complejidad |b|+|j|, y la cantidad operaciones solo va a depender de |b| y |j| (los "for" se ejecutan una
    cantidad determinada de veces)
    */
    vector <pos> res;
    for(int i = -1; i<2;i++){
        for(int k = -1; k<2;k++){
            pos posActual = pos(p.first - i, p.second - k );
            if(casillaValida(posActual,t,b,j) && (i!=0 || k!=0) && minasAdyacentes(t, posActual)==0){
                res.push_back(posActual); //Complejidad O(1) amortizado
            }
        }
    }
    return res;
}

void finalDeCamino(tablero& t, banderitas& b, pos p, jugadas& j){
    //Complejidad: O(n^2)
    vector<pos> posFinales = posicionesFinalesDeCamino(p, t, b, j);
    for(int i = 0; i < posFinales.size(); i++){
        j.push_back(jugada(posFinales[i], minasAdyacentes(t, posFinales[i])));
    }
}

vector<pos> posicionesFinalesDeCamino(pos p,tablero& t,banderitas& b,jugadas& j){
    /*
    Complejidad: O(|b|+|j|)
    La justifiacion es similar a la de posicionesAdyacentesSinMinas
    */
    vector <pos> res = { };
    for(int i = -1; i<2;i++){
        for(int k = -1; k<2;k++){
            pos posActual = pos(p.first - i, p.second - k );
            if(casillaValida(posActual,t,b,j) && minasAdyacentes(t, posActual)>0 && (i!=0 || k!=0)){
                res.push_back(posActual); //Complejidad O(1) amortizado
            }
        }
    }
    return res;
}

bool esUnaMina(pos p, tablero& t){
    //Complejidad: O(1)
    return t[p.first][p.second];
}

bool casillaValida(pos p, tablero& t, banderitas& b, jugadas& j){
    /*
    Complejidad: O(|b|+|j|)
    perteneceAJugadas tiene complejidad de peor caso |j| (explicado en la funcion) y perteneceABanderitas complejidad |b|.
    Entonces, en el peor caso, cada vez que se llama a esta funcion, se va a ejecutar perteneceAJugadas y perteneceABanderitas por lo que sus 
    complejidades se van a sumar. Vale aclarar, que como las complejidades de esAdyacenteValida y esUnaMina son constantes, no van a afectar a 
    la complejidad de peor caso (a nivel asintotico).
    
    */
    return (esAdyacenteValida(p, t) && !perteneceAJugadas(p, j) && !perteneceABanderitas(p, b) && !esUnaMina(p, t));
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool esAdyacente121(pos p, jugadas& j){
    /*
    Complejidad: O(n)
    Todas las auxiliares que evalua el if tienen complejidad lineal
    */
    if( es121Horizontal(pos(p.first - 1, p.second), j) || es121Horizontal(pos(p.first + 1, p.second), j) ||
        es121Vertical(pos(p.first, p.second - 1), j) || es121Vertical(pos(p.first, p.second + 1), j)){
        return true;
    }
    return false;
}

bool es121Horizontal(pos p, jugadas& j){
    //Complejidad: O(n)
    if(seJugo(jugada(pos(p.first, p.second -1 ), 1), j) &&
       seJugo(jugada(p, 2), j) &&
       seJugo(jugada(pos(p.first, p.second + 1 ), 1), j)){
        return true;
    }
    return false;
}

bool es121Vertical(pos p, jugadas& j){
    //Complejidad: O(n)
    if(seJugo(jugada(pos(p.first - 1, p.second), 1), j) &&
       seJugo(jugada(p, 2), j) &&
       seJugo(jugada(pos(p.first + 1, p.second), 1), j)){
        return true;
    }
    return false;
}

bool seJugo(jugada j0, jugadas& j){
    //Complejidad: O(n)
    for(int i=0; i < j.size(); i++){
        if(j[i] == j0){
            return true;
        }
    }
    return false;
}
