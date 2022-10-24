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

//cambiarBanderita
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

//minasAdyacentes
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
