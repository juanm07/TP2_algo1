// Tests para la función sugerir121.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(sugerir121TEST, hay121Horizontal){
    pos p = { };
    tablero t = {{cVACIA,cVACIA,cVACIA},
                 {cMINA,cVACIA,cMINA},
                 {cVACIA,cMINA,cVACIA}};
    jugadas j = {jugada(pos(0,0),1), jugada(pos(0,1),2), jugada(pos(0,2),1)};
    pos pos121 = {1,1};
    banderitas b = {{2,0}};
    sugerirAutomatico121(t,b,j,p);
    ASSERT_EQ(p,pos121);
    ASSERT_TRUE(sugerirAutomatico121(t, b, j, p));
}

TEST(sugerir121TEST, hay121Vertical){
    pos p = { };
    tablero t = {{cVACIA,cMINA,cVACIA},
                 {cVACIA,cVACIA,cMINA},
                 {cVACIA,cMINA,cVACIA}};
    jugadas j = {jugada(pos(0,0),1), jugada(pos(1,0),2), jugada(pos(2,0),1),  jugada(pos(2,2), 2)};
    pos pos121 = {1,1};
    banderitas b = {{0,1}};
    sugerirAutomatico121(t,b,j,p);
    ASSERT_EQ(p,pos121);
    ASSERT_TRUE(sugerirAutomatico121(t, b, j, p));
}

TEST(sugerir121TEST, noHay121){
    pos p = { };
    tablero t = {{cVACIA,cVACIA,cVACIA},
                 {cMINA,cVACIA,cMINA},
                 {cVACIA,cMINA,cVACIA}};
    jugadas j = {jugada(pos(2,0),2), jugada(pos(0,1),2), jugada(pos(0,2),1)};
    pos pos121 = { };
    banderitas b = {{2,2}};
    sugerirAutomatico121(t,b,j,p);
    ASSERT_EQ(p,pos121);
    ASSERT_FALSE(sugerirAutomatico121(t, b, j, p));
}
