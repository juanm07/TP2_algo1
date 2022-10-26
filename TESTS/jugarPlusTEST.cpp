// Tests para la función jugarPlus.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(jugarPlusTEST, test1){
    tablero t = {
            { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
    };
    jugadas jugadasValidas = {
            jugada(pos(0,4),1), jugada(pos(3,0),2)
    };
    banderitas b= {
            pos(4,0),pos(4,1)
    };
    pos posicionJugada = {4,4};
    jugadas expected = {
            jugada(pos(0,4),1), jugada(pos(3,0),2), jugada(pos(4,4),0),
            jugada(pos(3,4),0),jugada(pos(2,4),1),  jugada(pos(4,3),1),
            jugada(pos(3,3),1), jugada(pos(2,3),1)
    };
    jugarPlus(t,b,posicionJugada,jugadasValidas);
    ASSERT_EQ(jugadasValidas, expected);
}
