
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
/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/
bool esAdyacenteValida(pos p, tablero& t);
bool coordenadaValida(int c, int n);

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool seJugoUnaMina(tablero& t, jugadas& j);

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool juegoGanado(vector<pair<int,int>> p,jugadas& j);
bool perteneceAJugadas(pos p, jugadas& j);
vector<pair<int,int>> posicionesSinMinas (tablero& t);

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
vector<pos> posicionesFinalesDeCamino(pos p,tablero& t,banderitas& b,jugadas& j);
void finalDeCamino(tablero& t, banderitas& b, pos p, jugadas& j);
vector<pos> posicionesAdyacentesSinMinas(pos p,tablero& t,banderitas& b,jugadas& j);
bool casillaValida(pos p, tablero& t, banderitas& b, jugadas& j);
bool esUnaMina(pos p, tablero& t);
void descubreAutomatico(pos p, tablero& t, banderitas& b, jugadas& j);
=======

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool hayPosicionSugerible(jugadas& j, banderitas& b, tablero& t);  
bool esAdyacente121(pos p, jugadas& j);
bool es121Horizontal(pos p, jugadas& j);
bool es121Vertical(pos p, jugadas& j);
bool seJugo(jugada j0, jugadas& j);
