// Tests para la función perdio.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(perdioTEST, YaPerdio){
    tablero t = {
            {cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cMINA,cVACIA},
            {cVACIA,cMINA,cVACIA,cMINA},
            {cVACIA,cMINA,cVACIA,cMINA}
    };
    jugadas j = {
            jugada(pos(0,0),0),jugada(pos(0,1),1), jugada(pos(0,2),1),
            jugada(pos(1,0),1), jugada(pos(1,2),2)
    };
    bool res = perdio(t,j);
    ASSERT_TRUE(res);
}

TEST(perdioTEST, noPerdioAun){
    tablero t = {
            {cVACIA,cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cMINA,cVACIA},
            {cVACIA,cMINA,cVACIA,cMINA},
            {cVACIA,cMINA,cVACIA,cMINA}
    };
    jugadas j = {
            jugada(pos(0,0),0),jugada(pos(0,1),1), jugada(pos(0,2),1),
            jugada(pos(1,0),1), jugada(pos(1,3),2), jugada(pos(3,0),2)
    };
    bool res = perdio(t,j);
    ASSERT_FALSE(res);
}
