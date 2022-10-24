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
    int res = 0;
    for(int i = -1; i<2;i++){
        for(int j = -1;j<2;j++){
            pos posicion_actual = {(p.first)- i,(p.second)-j};
            //bool casilla = t[posicion_actual.first][posicion_actual.second];
            if(esAdyacenteValida(posicion_actual,t)&& t[posicion_actual.first][posicion_actual.second] && (i != 0 || j!=0)){
                res++;
            }
        }
    }
    return res;
}

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {

    if(perteneceABanderitas(p,b)){
        removerBanderita(p,b);
    }
    else{
        b.push_back(p);
    }
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool perdio(tablero& t, jugadas& j) {
    // ...
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool gano(tablero& t, jugadas& j) {
    // ...
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {

}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    // ...
}

TEST(minasAdyacentesTEST, esquina_1){
    tablero t = {
            {cMINA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cMINA},
            {cVACIA,cMINA,cVACIA}
    };
    pos p = {1,0};
    int res = minasAdyacentes(t,p);
    ASSERT_EQ(res, 2);
}

TEST(minasAdyacentesTEST, esquina_2){
    tablero t = {
            {cMINA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cMINA},
            {cVACIA,cMINA,cVACIA}
    };
    pos p = {0,0};
    int res = minasAdyacentes(t,p);
    ASSERT_EQ(res, 0);
}

TEST(minasAdyacentesTEST, medio){
    tablero t = {
            {cMINA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cMINA},
            {cVACIA,cMINA,cVACIA}
    };
    pos p = {1,1};
    int res = minasAdyacentes(t,p);
    ASSERT_EQ(res, 3);
}

