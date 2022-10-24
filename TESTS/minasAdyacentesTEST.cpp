// Tests para la función minasAdyacentes.
// Ver el archivo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "../definiciones.h"
#include "gtest/gtest.h"

using namespace std;

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
