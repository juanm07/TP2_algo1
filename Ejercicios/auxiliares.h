
//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/
bool perteneceABanderitas(pos p, banderitas& b);
void intercambiarValoresVector(pos& x, pos& y);
void removerBanderita(pos p, banderitas& b);


/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/
bool esAdyacenteValida(pos p, tablero& t);
bool coordenadaValida(int c, int n);

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool seJugoUnaMina(tablero& t, jugadas& j);

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
bool existeCaminoValido(tablero& t,banderitas& b,pos posJugada,jugadas& j);
bool hayCaminoLibre(tablero& t, banderitas& b, pos posInicial, jugadas& j);
bool existeAdyacenteValida(tablero& t, banderitas& b, pos p, jugadas& j);
bool noEsMina(tablero& t, pos p);
bool esCasillaDeCamino(tablero& t, banderitas& b, pos p, jugadas& j);
bool posEstaEnJugadas(pos p, jugadas& j);
jugadas caminoLibre(tablero& t, banderitas& b, pos p, jugadas& j);
bool esFinalDeCamino(tablero& t, banderitas& b, pos p, jugadas& j);
