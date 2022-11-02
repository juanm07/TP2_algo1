// Tests para la función jugarPlus.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;


bool mismasJugadas(jugadas& j0, jugadas& j){
    bool res = false;
    for(int i=0; i<j0.size();i++){
        if(seJugo(j0[i], j)){
            res = true;
        }
    }
    return res;
}

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
    ASSERT_TRUE(mismasJugadas(expected,jugadasValidas));
}

TEST(jugarPlusTEST, test2){
    tablero t = {
            { cMINA,  cVACIA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cMINA, cVACIA, cVACIA,  cVACIA },
            { cVACIA, cVACIA,  cVACIA, cVACIA, cVACIA },
            { cMINA, cVACIA, cVACIA, cMINA, cVACIA },
            { cVACIA,  cMINA, cVACIA,  cVACIA, cVACIA },
    };
    
    jugadas jugadasValidas = {
            jugada(pos(2,1),2), jugada(pos(3,1),2)
    };
    
    banderitas b= {
            pos(1,1),pos(4,1)
    };
    
    pos posicionJugada = {0,3};

    jugadas expected = {
            jugada(pos(2,1),2), jugada(pos(3,1), 2), jugada(pos(0,3),0),
            jugada(pos(0,2),1),  jugada(pos(0,4),0),
            jugada(pos(1,2),1),jugada(pos(1,3),0), jugada(pos(1,4),0),
            jugada(pos(2,2),2), jugada(pos(2,3),1), jugada(pos(2,4), 1),

    };

    jugarPlus(t,b,posicionJugada,jugadasValidas);
    ASSERT_TRUE(mismasJugadas(jugadasValidas,expected));
}

TEST(jugarPlusTEST,todasMinasMenosUna){
    tablero t = {
            {cMINA,cMINA,cMINA},
            {cMINA,cMINA,cMINA},
            {cMINA,cMINA,cVACIA}
    };
    
    jugadas jugadasValidas{};
    
    banderitas b = {
            pos(0,0),pos(0,1)
    };
    
    pos posicionJugada = {2,2};
    
    jugadas expected = {jugada(pos(2,2),3)};
    
    jugarPlus(t,b,posicionJugada,jugadasValidas);
    ASSERT_TRUE(mismasJugadas(jugadasValidas,expected));
}

TEST(jugarPlusTEST,tableroConSoloUnaMina){
    tablero t = {
            {cMINA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA}
    };
    
    jugadas jugadasValidas{ jugada(pos(0,1), 0)};
    
    banderitas b = {
            pos(0,2)
    };
    
    pos posicionJugada = {2,2};
    
    jugadas expected = {jugada(pos(0,1), 0), jugada(pos(2,2),0),
    jugada(pos(2,1),0), jugada(pos(2,0),0),jugada(pos(1,2),0),jugada(pos(1,0),0),
    jugada(pos(0,2),0)};
    
    jugarPlus(t,b,posicionJugada,jugadasValidas);
    ASSERT_TRUE(mismasJugadas(jugadasValidas,expected));
}

TEST(jugarPlusTEST,todasBanderitas){
    tablero t = {
            {cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA},
            {cVACIA,cVACIA,cVACIA}
    };
    
    jugadas jugadasValidas={ };
    
    banderitas b = {
            pos(0,0), pos(0,1), pos(0,2), pos(1,0), pos(1,1), pos(1,2), pos(2,0), pos(2,1)
    };
    
    pos posicionJugada = {2,2};
    
    jugadas expected = {jugada(pos(2,2),0)};
    
    jugarPlus(t,b,posicionJugada,jugadasValidas);
    ASSERT_TRUE(mismasJugadas(jugadasValidas,expected));
}

