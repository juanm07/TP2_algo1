// Tests para la función cambiarBanderita.
// Ver el archovo README.md para ayuda


#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(sacarBanderita, haybanderita){
    tablero t = {{cVACIA,cVACIA,cVACIA},
                 {cMINA,cVACIA,cVACIA},
                 {cVACIA,cMINA,cVACIA}
                 };
    jugadas j = {{{0,0},1}};
    pos p(1,0);
    banderitas b0 = {{1,0},{0,0}};
    cambiarBanderita(t,j,p,b0);
    banderitas b = {{0,0}};
    ASSERT_EQ(b,b0);
}

TEST(ponerBanderita, noHaybanderita){
    tablero t = {{cVACIA,cVACIA,cVACIA},
                 {cMINA,cVACIA,cVACIA},
                 {cVACIA,cMINA,cVACIA}
                };
    jugadas j = {{{0,0},1}};
    pos p(1,0);
    banderitas b0 = {{0,0}};
    cambiarBanderita(t,j,p,b0);
    banderitas b = {{0,0}, {1,0}};
    ASSERT_EQ(b,b0);
}
