// Este archivo contiene las declaraciones de las funciones (no el código).

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

int minasAdyacentes(tablero& t, pos p); //Complejidad: O(1) constante
void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b); //Complejidad: O(|b|)
bool perdio(tablero& t, jugadas& j); //Complejidad: O(|j|)
bool gano(tablero& t, jugadas& j); //Complejidad: O(|j|^2 + |t|^2)
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j); //Complejidad: O(|t|*(|b|+|j|))
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p);//Complejidad: O(|t|^2(|b|+|j|))

