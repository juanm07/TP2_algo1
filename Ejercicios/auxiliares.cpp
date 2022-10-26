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

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/

bool existeCaminoValido(tablero& t,banderitas& b,pos posJugada,jugadas& j){
    int minas_ady_a_posJugada = minasAdyacentes(t,posJugada);
    if(noEsMina(t,posJugada) && minas_ady_a_posJugada == 0 && hayCaminoLibre(t,b,posJugada,j)){
        return true;
    }
    else{
        return false;
    }
}

bool hayCaminoLibre(tablero& t, banderitas& b, pos posInicial, jugadas& j){
    if(existeAdyacenteValida(t,b,posInicial,j)){
        return true;
    }
    return false;
}

bool existeAdyacenteValida(tablero& t, banderitas& b, pos p, jugadas& j){
    for(int i = -1; i<2;i++){
        for(int k = -1;k<2;k++){
            pos adyacente = {(p.first)-i, (p.second)-k};
            if(esCasillaDeCamino(t,b,adyacente,j) || esFinalDeCamino(t,b,adyacente,j)){
                return true;
            }
        }
    }
    return false;
}

bool noEsMina(tablero& t, pos p){
    if(t[p.first][p.second]){
        return false;
    }
    else{
        return true;
    }
}

bool esCasillaDeCamino(tablero& t, banderitas& b, pos p, jugadas& j){
    return (esAdyacenteValida(p,t) && minasAdyacentes(t,p)== 0 && noEsMina(t,p)
            && !perteneceABanderitas(p,b) && !posEstaEnJugadas(p,j));
}

bool posEstaEnJugadas(pos p, jugadas& j){
    for(int i = 0;i<j.size();i++){
        if(j[i].first == p){
            return true;
        }
    }
    return false;
}


void caminoLibre(tablero& t, banderitas& b, pos p, jugadas& j) {
        if (esCasillaDeCamino(t, b, p, j)) {
            j.push_back(jugada(pos(p), minasAdyacentes(t,p)));
            for (int i = -1; i < 2; i++) {
                for (int k = -1; k < 2; k++) {
                    pos posNueva = {p.first - i, p.second - k};
                    if (esCasillaDeCamino(t, b, posNueva, j)) {
                        j.push_back(jugada(pos(posNueva), minasAdyacentes(t, posNueva)));
                    }
                    else {
                        if(esFinalDeCamino(t, b, posNueva, j)){
                            j.push_back(jugada(pos(posNueva), minasAdyacentes(t, posNueva)));
                        }
                    }
                    posNueva = p;
                }
            }
            caminoLibre(t,b,p,j);
       }
        else {
            j.push_back(jugada(pos(p), minasAdyacentes(t, p)));
        }
}
bool esFinalDeCamino(tablero& t, banderitas& b, pos p, jugadas& j){
    if(minasAdyacentes(t,p)>=1 && noEsMina(t,p) && !posEstaEnJugadas(p,j) &&
       !perteneceABanderitas(p,b)){
        return true;
    }
    else{
        return false;
    }
}
bool esAdyacenteAcamino(tablero& t, banderitas& b, pos p, jugadas& j){
    for(int i = -1; i<2;i++){
        for(int k = -1; k<2;k++){
            pos posAdescubrir = {p.first -i , p.second -k};
            if(esCasillaDeCamino(t,b,posAdescubrir,j)){
                return true;
            }
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

