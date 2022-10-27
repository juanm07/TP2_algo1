// Tests para la función sugerir121.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(sugerir121TEST, hay121Horizontal){
    tablero t = {{cVACIA,cVACIA,cVACIA},
                 {cMINA,cVACIA,cMINA},
                 {cVACIA,cMINA,cVACIA}};
    jugadas j = {jugada(pos(0,0),1), jugada(pos(0,1),2), jugada(pos(0,2),1)};
    pos p = {1,1};
    banderitas b = {{2,0}};
    ASSERT_TRUE(sugerirAutomatico121(t, b, j, p));
}

TEST(sugerir121TEST, hay121Vertical){
    tablero t = {{cVACIA,cMINA,cVACIA},
                 {cVACIA,cVACIA,cMINA},
                 {cVACIA,cMINA,cVACIA}};
    jugadas j = {jugada(pos(0,0),1), jugada(pos(1,0),2), jugada(pos(2,0),1),  jugada(pos(2,2), 2)};
    pos p = {1,1};
    banderitas b = {{0,1}};
    ASSERT_TRUE(sugerirAutomatico121(t, b, j, p));
}


TEST(sugerir121TEST, noHay121){
    tablero t = {{cVACIA,cVACIA,cVACIA},
                 {cMINA,cVACIA,cMINA},
                 {cVACIA,cMINA,cVACIA}};
    jugadas j = {jugada(pos(2,0),2), jugada(pos(0,1),2), jugada(pos(0,2),1)};
    pos p = {1,1};
    banderitas b = {{2,2}};
    ASSERT_FALSE(sugerirAutomatico121(t, b, j, p));
}
