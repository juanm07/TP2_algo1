//
// Este archivo contiene las declaraciones de las funciones (no el código).
// Tienen que coincidir exactamente con el código que se encuentra en ejercicios.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

int minasAdyacentes(tablero& t, pos p); //Complejidad: O(1) constante
void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b); //Complejidad: O(n)
bool perdio(tablero& t, jugadas& j); //Complejidad: O(n)
bool gano(tablero& t, jugadas& j);
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j);
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p);

