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
    int largo_tablero = t.size();
    if(coordenadaValida(p.first,largo_tablero) && coordenadaValida(p.second,largo_tablero)){
        return true;
    }
    return false;
}

bool coordenadaValida(int c, int n){
    return (0<= c && c<n);
}




/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

bool perteneceABanderitas(pos p, banderitas& b){
    for(int i=0; i<b.size();i++){
        if(b[i]== p){
            return true;
        }
    }
    return false;
}

void removerBanderita(pos p, banderitas& b){
    for(int i = 0; i<b.size();i++){
        if(b[i]==p){
            intercambiarValoresVector(b[i],b[b.size()-1]);
            b.pop_back();
        }
    }
}

void intercambiarValoresVector(pos& x, pos& y){
    pos temp = x;
    x = y;
    y = temp;
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/

bool seJugoUnaMina(tablero& t, jugadas& j){
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
    for(int i = 0; i < p.size(); i++){
        if(!perteneceAJugadas(p[i], j)){
            return false;
        }
    }
    return true;
}

bool perteneceAJugadas(pos p, jugadas& j){
    for(int i = 0; i < j.size(); i++){
        if(j[i].first == p){
            return true;
        }
    }
    return false;
}

vector<pos> posicionesSinMinas (tablero& t){
    vector<pos> res = { };
    for(int i = 0; i < t.size(); i++) {
        for (int k = 0; k < t.size(); k++) {
            if(!t[i][k]){
                res.push_back(make_pair(i,k));
            }
        }
    }
    return res;
}
