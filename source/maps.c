#include <nds.h>
#include "sprites.h"
#include "maps.h"
#include "definiciones.h"
#include "structs.h"
#include "juego.h"
#include "fondos.h"
#include "perifericos.h"
#include <math.h>
extern Enemigo enemigos[MAX_ENEMIGOS];
extern Moneda monedas[MAX_MONEDAS];
extern int numEnemigos;
extern int numMonedas;
extern Prota personaje;
Tile map1[160] = { //El mapa ocupa toda la pantalla y esta compuesto de structs de tipo Tile (de structs.h en /included/)
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, 0, false, true, false},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, 0, false, true, false},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, 0, false, true, false},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, 0, false, true, true /*AQUI EMPIEZA EL PERSONAJE*/ } ,{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, 0, false, true, false},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, 0, false, true, false},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, 0, false, true, false},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, 0, false, true, false},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, 1, false, true, false},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, 1, false, true, false},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, 1, false, true, false},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, 1, false, true, false},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, 1, false, true, false},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, 1, false, true, false},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, 1, false, true, false},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, 1, false, true, false},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, 2, false, true, false},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, 2, false, true, false},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, 2, false, true, false},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, 2, false, true, false},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, 2, false, true, false},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, 2, false, true, false},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, 2, false, true, false},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, 2, false, true, false},
    
    {tileAgua, NULL, AGUA_SUELO, 0, 0, SPRITE32, 3, true, false, false},{tileAgua, NULL, AGUA_SUELO, 32, 0, SPRITE32, 3, false, false, false},{tileAgua, NULL, AGUA_SUELO, 64, 0, SPRITE32, 3, false, false, false},{tileAgua, NULL, AGUA_SUELO, 96, 0, SPRITE32, 3, false, false, false},{tileAgua, NULL, AGUA_SUELO, 128, 0, SPRITE32, 3, false, false, false},{tileAgua, NULL, AGUA_SUELO, 160, 0, SPRITE32, 3, false, false, false},{tileAgua, NULL, AGUA_SUELO, 192, 0, SPRITE32, 3, false, false, false},{tileAgua, NULL, AGUA_SUELO, 224, 0, SPRITE32, 3, false, false, false},
    
    {tileAgua, NULL, AGUA_SUELO, 0, 0, SPRITE32, 4, false, false, false},{tileAgua, NULL, AGUA_SUELO, 32, 0, SPRITE32, 4, false, false, false},{tileAgua, NULL, AGUA_SUELO, 64, 0, SPRITE32, 4, false, false, false},{tileAgua, NULL, AGUA_SUELO, 96, 0, SPRITE32, 4, false, false, false},{tileAgua, NULL, AGUA_SUELO, 128, 0, SPRITE32, 4, false, false, false},{tileAgua, NULL, AGUA_SUELO, 160, 0, SPRITE32, 4, false, false, false},{tileAgua, NULL, AGUA_SUELO, 192, 0, SPRITE32, 4, false, false, false},{tileAgua, NULL, AGUA_SUELO, 224, 0, SPRITE32, 4, true, false, false},
    
    {tileAgua, NULL, AGUA_SUELO, 0, 0, SPRITE32, 5, true, false, false},{tileAgua, NULL, AGUA_SUELO, 32, 0, SPRITE32, 5, false, false, false},{tileAgua, NULL, AGUA_SUELO, 64, 0, SPRITE32, 5, false, false, false},{tileAgua, NULL, AGUA_SUELO, 96, 0, SPRITE32, 5, false, false, false},{tileAgua, NULL, AGUA_SUELO, 128, 0, SPRITE32, 5, false, false, false},{tileAgua, NULL, AGUA_SUELO, 160, 0, SPRITE32, 5, false, false, false},{tileAgua, NULL, AGUA_SUELO, 192, 0, SPRITE32, 5, false, false, false},{tileAgua, NULL, AGUA_SUELO, 224, 0, SPRITE32, 5, false, false, false},

    {tileAgua, NULL, AGUA_SUELO, 0, 0, SPRITE32, 6, false, false, false},{tileAgua, NULL, AGUA_SUELO, 32, 0, SPRITE32, 6, false, false, false},{tileAgua, NULL, AGUA_SUELO, 64, 0, SPRITE32, 6, false, false, false},{tileAgua, NULL, AGUA_SUELO, 96, 0, SPRITE32, 6, false, false, false},{tileAgua, NULL, AGUA_SUELO, 128, 0, SPRITE32, 6, false, false, false},{tileAgua, NULL, AGUA_SUELO, 160, 0, SPRITE32, 6, false, false, false},{tileAgua, NULL, AGUA_SUELO, 192, 0, SPRITE32, 6, false, false, false},{tileAgua, NULL, AGUA_SUELO, 224, 0, SPRITE32, 6, true, false, false},

    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, 7, false, true, false},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, 7, false, true, false},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, 7, false, true, false},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, 7, false, true, false},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, 7, false, true, false},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, 7, false, true, false},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, 7, false, true, false},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, 7, false, true, false},

    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, 8, false, true, false},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, 8, false, true, false},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, 8, false, true, false},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, 8, false, true, false},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, 8, false, true, false},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, 8, false, true, false},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, 8, false, true, false},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, 8, false, true, false},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, 9, false, true, false},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, 9, false, true, false},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, 9, false, true, false},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, 9, false, true, false},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, 9, false, true, false},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, 9, false, true, false}, {tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, 9, false, true, false},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, 9, false, true, false},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, 10, false, true, false},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, 10, false, true, false},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, 10, false, true, false},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, 10, false, true, false},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, 10, false, true, false},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, 10, false, true, false},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, 10, false, true, false},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, 10, false, true, false},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, 11, false, true, false},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, 11, false, true, false},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, 11, false, true, false},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, 11, false, true, false},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, 11, false, true, false},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, 11, false, true, false},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, 11, false, true, false},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, 11, false, true, false},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, 12, false, true, false},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, 12, false, true, false},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, 12, false, true, false},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, 12, false, true, false},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, 12, false, true, false},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, 12, false, true, false},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, 12, false, true, false},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, 12, false, true, false},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, 13, false, true, false},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, 13, false, true, false},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, 13, false, true, false},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, 13, false, true, false},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, 13, false, true, false},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, 13, false, true, false},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, 13, false, true, false},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, 13, false, true, false},
    
    {tileAgua, NULL, AGUA_SUELO, 0, 0, SPRITE32, 14, true, false, false},{tileAgua, NULL, AGUA_SUELO, 32, 0, SPRITE32, 14, false, false, false},{tileAgua, NULL, AGUA_SUELO, 64, 0, SPRITE32, 14, false, false, false},{tileAgua, NULL, AGUA_SUELO, 96, 0, SPRITE32, 14, false, false, false},{tileAgua, NULL, AGUA_SUELO, 128, 0, SPRITE32, 14, false, false, false},{tileAgua, NULL, AGUA_SUELO, 160, 0, SPRITE32, 14, false, false, false},{tileAgua, NULL, AGUA_SUELO, 192, 0, SPRITE32, 14, false, false, false},{tileAgua, NULL, AGUA_SUELO, 224, 0, SPRITE32, 14, false, false, false},

    {tileAgua, NULL, AGUA_SUELO, 0, 0, SPRITE32, 15, false, false, false},{tileAgua, NULL, AGUA_SUELO, 32, 0, SPRITE32, 15, false, false, false},{tileAgua, NULL, AGUA_SUELO, 64, 0, SPRITE32, 15, false, false, false},{tileAgua, NULL, AGUA_SUELO, 96, 0, SPRITE32, 15, false, false, false},{tileAgua, NULL, AGUA_SUELO, 128, 0, SPRITE32, 15, false, false, false},{tileAgua, NULL, AGUA_SUELO, 160, 0, SPRITE32, 15, false, false, false},{tileAgua, NULL, AGUA_SUELO, 192, 0, SPRITE32, 15, false, false, false},{tileAgua, NULL, AGUA_SUELO, 224, 0, SPRITE32, 15, true, false, false},

    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, 16, false, true, false},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, 16, false, true, false},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, 16, false, true, false},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, 16, false, true, false},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, 16, false, true, false},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, 16, false, true, false},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, 16, false, true, false},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, 16, false, true, false},

    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, 17, false, true, false},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, 17, false, true, false},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, 17, false, true, false},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, 17, false, true, false},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, 17, false, true, false},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, 17, false, true, false},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, 17, false, true, false},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, 17, false, true, false},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, 18, false, true, false},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, 18, false, true, false},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, 18, false, true, false},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, 18, false, true, false},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, 18, false, true, false},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, 18, false, true, false}, {tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, 18, false, true, false},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, 18, false, true, false},
    
    {metaTile, NULL, META_SUELO, 0, 0, SPRITE32, 19, false, true, false},{metaTile, NULL, META_SUELO, 32, 0, SPRITE32, 19, false, true, false},{metaTile, NULL, META_SUELO, 64, 0, SPRITE32, 19, false, true, false},{metaTile, NULL, META_SUELO, 96, 0, SPRITE32, 19, false, true, false},{metaTile, NULL, META_SUELO, 128, 0, SPRITE32, 19, false, true, false},{metaTile, NULL, META_SUELO, 160, 0, SPRITE32, 19, false, true, false},{metaTile, NULL, META_SUELO, 192, 0, SPRITE32, 19, false, true, false},{metaTile, NULL, META_SUELO, 224, 0, SPRITE32, 19, false, true, false},
};
Tile map2[208] = {                                                                                                                                                                                                                   /*AQUI EMPIEZA EL PERSONAJE*/ 
    {tileSuelo, NULL, SUELO_SUELO, 0, 0, SPRITE32, 0, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 32, 0, SPRITE32, 0, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 64, 0, SPRITE32, 0, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 96, 0, SPRITE32, 0, false, true, true} ,{tileSuelo, NULL, SUELO_SUELO, 128, 0, SPRITE32, 0, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 160, 0, SPRITE32, 0, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 192, 0, SPRITE32, 0, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 224, 0, SPRITE32, 0, false, true, false},
    
    {tileSuelo, NULL, SUELO_SUELO, 0, 0, SPRITE32, 1, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 32, 0, SPRITE32, 1, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 64, 0, SPRITE32, 1, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 96, 0, SPRITE32, 1, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 128, 0, SPRITE32, 1, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 160, 0, SPRITE32, 1, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 192, 0, SPRITE32, 1, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 224, 0, SPRITE32, 1, false, true, false},
    
    {tileSuelo, NULL, SUELO_SUELO, 0, 0, SPRITE32, 2, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 32, 0, SPRITE32, 2, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 64, 0, SPRITE32, 2, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 96, 0, SPRITE32, 2, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 128, 0, SPRITE32, 2, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 160, 0, SPRITE32, 2, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 192, 0, SPRITE32, 2, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 224, 0, SPRITE32, 2, false, true, false},
    
    {tileAgua2, NULL, AGUA_SUELO2, 0, 0, SPRITE32, 3, true, false, false},{tileAgua2, NULL, AGUA_SUELO2, 32, 0, SPRITE32, 3, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 64, 0, SPRITE32, 3, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 96, 0, SPRITE32, 3, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 128, 0, SPRITE32, 3, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 160, 0, SPRITE32, 3, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 192, 0, SPRITE32, 3, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 224, 0, SPRITE32, 3, false, false, false},
    
    {tileAgua2, NULL, AGUA_SUELO2, 0, 0, SPRITE32, 4, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 32, 0, SPRITE32, 4, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 64, 0, SPRITE32, 4, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 96, 0, SPRITE32, 4, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 128, 0, SPRITE32, 4, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 160, 0, SPRITE32, 4, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 192, 0, SPRITE32, 4, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 224, 0, SPRITE32, 4, true, false, false},

    {tileAgua2, NULL, AGUA_SUELO2, 0, 0, SPRITE32, 5, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 32, 0, SPRITE32, 5, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 64, 0, SPRITE32, 5, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 96, 0, SPRITE32, 5, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 128, 0, SPRITE32, 5, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 160, 0, SPRITE32, 5, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 192, 0, SPRITE32, 5, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 224, 0, SPRITE32, 5, true, false, false},

    {tileSuelo, NULL, SUELO_SUELO, 0, 0, SPRITE32, 6, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 32, 0, SPRITE32, 6, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 64, 0, SPRITE32, 6, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 96, 0, SPRITE32, 6, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 128, 0, SPRITE32, 6, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 160, 0, SPRITE32, 6, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 192, 0, SPRITE32, 6, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 224, 0, SPRITE32, 6, false, true, false},

    {tileSuelo, NULL, SUELO_SUELO, 0, 0, SPRITE32, 7, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 32, 0, SPRITE32, 7, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 64, 0, SPRITE32, 7, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 96, 0, SPRITE32, 7, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 128, 0, SPRITE32, 7, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 160, 0, SPRITE32, 7, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 192, 0, SPRITE32, 7, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 224, 0, SPRITE32, 7, false, true, false},
    
    {tileAgua2, NULL, AGUA_SUELO2, 0, 0, SPRITE32, 8, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 32, 0, SPRITE32, 8, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 64, 0, SPRITE32, 8, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 96, 0, SPRITE32, 8, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 128, 0, SPRITE32, 8, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 160, 0, SPRITE32, 8, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 192, 0, SPRITE32, 8, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 224, 0, SPRITE32, 8, true, false, false},
    
    {tileSuelo, NULL, SUELO_SUELO, 0, 0, SPRITE32, 9, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 32, 0, SPRITE32, 9, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 64, 0, SPRITE32, 9, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 96, 0, SPRITE32, 9, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 128, 0, SPRITE32, 9, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 160, 0, SPRITE32, 9, false, true, false}, {tileSuelo, NULL, SUELO_SUELO, 192, 0, SPRITE32, 9, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 224, 0, SPRITE32, 9, false, true, false},
    
    {tileSuelo, NULL, SUELO_SUELO, 0, 0, SPRITE32, 10, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 32, 0, SPRITE32, 10, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 64, 0, SPRITE32, 10, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 96, 0, SPRITE32, 10, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 128, 0, SPRITE32, 10, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 160, 0, SPRITE32, 10, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 192, 0, SPRITE32, 10, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 224, 0, SPRITE32, 10, false, true, false},
    
    {tileSuelo, NULL, SUELO_SUELO, 0, 0, SPRITE32, 11, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 32, 0, SPRITE32, 11, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 64, 0, SPRITE32, 11, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 96, 0, SPRITE32, 11, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 128, 0, SPRITE32, 11, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 160, 0, SPRITE32, 11, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 192, 0, SPRITE32, 11, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 224, 0, SPRITE32, 11, false, true, false},
    
    {tileAgua2, NULL, AGUA_SUELO2, 0, 0, SPRITE32, 12, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 32, 0, SPRITE32, 12, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 64, 0, SPRITE32, 12, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 96, 0, SPRITE32, 12, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 128, 0, SPRITE32, 12, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 160, 0, SPRITE32, 12, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 192, 0, SPRITE32, 12, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 224, 0, SPRITE32, 12, true, false, false},

    {tileAgua2, NULL, AGUA_SUELO2, 0, 0, SPRITE32, 13, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 32, 0, SPRITE32, 13, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 64, 0, SPRITE32, 13, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 96, 0, SPRITE32, 13, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 128, 0, SPRITE32, 13, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 160, 0, SPRITE32, 13, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 192, 0, SPRITE32, 13, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 224, 0, SPRITE32, 13, true, false, false},

    {tileAgua2, NULL, AGUA_SUELO2, 0, 0, SPRITE32, 14, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 32, 0, SPRITE32, 14, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 64, 0, SPRITE32, 14, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 96, 0, SPRITE32, 14, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 128, 0, SPRITE32, 14, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 160, 0, SPRITE32, 14, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 192, 0, SPRITE32, 14, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 224, 0, SPRITE32, 14, true, false, false},

    {tileAgua2, NULL, AGUA_SUELO2, 0, 0, SPRITE32, 15, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 32, 0, SPRITE32, 15, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 64, 0, SPRITE32, 15, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 96, 0, SPRITE32, 15, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 128, 0, SPRITE32, 15, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 160, 0, SPRITE32, 15, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 192, 0, SPRITE32, 15, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 224, 0, SPRITE32, 15, true, false, false},

    {tileSuelo, NULL, SUELO_SUELO, 0, 0, SPRITE32, 16, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 32, 0, SPRITE32, 16, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 64, 0, SPRITE32, 16, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 96, 0, SPRITE32, 16, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 128, 0, SPRITE32, 16, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 160, 0, SPRITE32, 16, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 192, 0, SPRITE32, 16, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 224, 0, SPRITE32, 16, false, true, false},
    
    {tileSuelo, NULL, SUELO_SUELO, 0, 0, SPRITE32, 17, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 32, 0, SPRITE32, 17, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 64, 0, SPRITE32, 17, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 96, 0, SPRITE32, 17, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 128, 0, SPRITE32, 17, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 160, 0, SPRITE32, 17, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 192, 0, SPRITE32, 17, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 224, 0, SPRITE32, 17, false, true, false},
    
    {tileAgua2, NULL, AGUA_SUELO2, 0, 0, SPRITE32, 18, true, false, false},{tileAgua2, NULL, AGUA_SUELO2, 32, 0, SPRITE32, 18, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 64, 0, SPRITE32, 18, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 96, 0, SPRITE32, 18, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 128, 0, SPRITE32, 18, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 160, 0, SPRITE32, 18, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 192, 0, SPRITE32, 18, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 224, 0, SPRITE32, 18, false, false, false},

    {tileAgua2, NULL, AGUA_SUELO2, 0, 0, SPRITE32, 19, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 32, 0, SPRITE32, 19, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 64, 0, SPRITE32, 19, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 96, 0, SPRITE32, 19, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 128, 0, SPRITE32, 19, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 160, 0, SPRITE32, 19, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 192, 0, SPRITE32, 19, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 224, 0, SPRITE32, 19, true, false, false},

    {tileAgua2, NULL, AGUA_SUELO2, 0, 0, SPRITE32, 20, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 32, 0, SPRITE32, 20, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 64, 0, SPRITE32, 20, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 96, 0, SPRITE32, 20, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 128, 0, SPRITE32, 20, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 160, 0, SPRITE32, 20, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 192, 0, SPRITE32, 20, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 224, 0, SPRITE32, 20, true, false, false},

    {tileSuelo, NULL, SUELO_SUELO, 0, 0, SPRITE32, 21, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 32, 0, SPRITE32, 21, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 64, 0, SPRITE32, 21, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 96, 0, SPRITE32, 21, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 128, 0, SPRITE32, 21, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 160, 0, SPRITE32, 21, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 192, 0, SPRITE32, 21, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 224, 0, SPRITE32, 21, false, true, false},
    
    {tileSuelo, NULL, SUELO_SUELO, 0, 0, SPRITE32, 22, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 32, 0, SPRITE32, 22, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 64, 0, SPRITE32, 22, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 96, 0, SPRITE32, 22, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 128, 0, SPRITE32, 22, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 160, 0, SPRITE32, 22, false, true, false}, {tileSuelo, NULL, SUELO_SUELO, 192, 0, SPRITE32, 22, false, true, false},{tileSuelo, NULL, SUELO_SUELO, 224, 0, SPRITE32, 22, false, true, false},

    {tileAgua2, NULL, AGUA_SUELO2, 0, 0, SPRITE32, 23, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 32, 0, SPRITE32, 23, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 64, 0, SPRITE32, 23, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 96, 0, SPRITE32, 23, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 128, 0, SPRITE32, 23, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 160, 0, SPRITE32, 23, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 192, 0, SPRITE32, 23, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 224, 0, SPRITE32, 23, true, false, false},

    {tileAgua2, NULL, AGUA_SUELO2, 0, 0, SPRITE32, 24, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 32, 0, SPRITE32, 24, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 64, 0, SPRITE32, 24, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 96, 0, SPRITE32, 24, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 128, 0, SPRITE32, 24, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 160, 0, SPRITE32, 24, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 192, 0, SPRITE32, 24, false, false, false},{tileAgua2, NULL, AGUA_SUELO2, 224, 0, SPRITE32, 24, true, false, false},
    
    {metaTile, NULL, META_SUELO, 0, 0, SPRITE32, 25, false, true, false},{metaTile, NULL, META_SUELO, 32, 0, SPRITE32, 25, false, true, false},{metaTile, NULL, META_SUELO, 64, 0, SPRITE32, 25, false, true, false},{metaTile, NULL, META_SUELO, 96, 0, SPRITE32, 25, false, true, false},{metaTile, NULL, META_SUELO, 128, 0, SPRITE32, 25, false, true, false},{metaTile, NULL, META_SUELO, 160, 0, SPRITE32, 25, false, true, false},{metaTile, NULL, META_SUELO, 192, 0, SPRITE32, 25, false, true, false},{metaTile, NULL, META_SUELO, 224, 0, SPRITE32, 25, false, true, false},
};
Tile map3[240] = {};

void renderMapa(int tipoMapa){ //Pinta el mapa en pantalla 
    
    int i;
    int j;
    int k;
    switch(tipoMapa){
        case 1://El mapa 1, de dificultad fácil
        spriteIndice = 1; //Un ID por cada sprite (siempre aumenta)
        if (scrollY > personaje.estadisticas->nivActual->altura) return;
        for (i = scrollY*8; i < 48 + scrollY*8; i++){ // Lo del scrollY aqui es como un viewport
            switch(map1[i].spriteID){ // Esto se pone asi porque no se puede asignar un puntero al gfx antes de iniciar un programa
                case FLOR_SUELO:
                    if(map1[i].gfxpoint == NULL) map1[i].gfxpoint = florSuelo;
                    EstablecerPaletaPrincipal(FLOR_SUELO);
                    break;
                case AGUA_SUELO:
                    if(map1[i].gfxpoint == NULL) map1[i].gfxpoint = aguaSuelo;
                    EstablecerPaletaPrincipal(AGUA_SUELO);
                    
                    break;
                case META_SUELO:
                    if(map1[i].gfxpoint == NULL) map1[i].gfxpoint = metaSuelo;
                    EstablecerPaletaPrincipal(META_SUELO);
                    
                    break;
            }
            map1[i].y = 6 - (map1[i].col - scrollY) - 1;
            if(map1[i].gfxpoint!=NULL) {
                MostrarSprite(spriteIndice, map1[i].x, map1[i].y * 32, map1[i].spriteSize, map1[i].gfxpoint, 3);
            } 
            
            spriteIndice++;    
        }

        
       
        for(k = 0;k < personaje.estadisticas->nivActual->tamMapa; k++){
            if(map1[k].enemigoSpawn){ // Esto tendria que estar dentro del switch case del spriteID pero aun solo hay un tipo de "enemigo"
                if(map1[k].x < 128) spawnEnemigo(map1[k].x, (-1)*32*map1[k].col + 160, COCHE_SPRITE, ESTE, k, map1[k].col);
                else spawnEnemigo(map1[k].x, (-1)*32*map1[k].col + 160, COCHE_SPRITE, OESTE, k, map1[k].col);
                map1[k].enemigoSpawn = false;
            }
        }
        
        for (j = 0; j < numEnemigos; j++) { // Actualiza la posicion de los enemigos cada tick del reloj
            enemigos[j].spriteIndice = spriteIndice;
            if(enemigos[j].colOrigen > 6 + scrollY  - 1 || enemigos[j].colOrigen < scrollY - 1){//Si los enemigos están fuera de la vista, no renderiza los sprites, los oculta
                BorrarSprite(enemigos[j].spriteIndice, enemigos[j].posx, enemigos[j].posy + scrollY*32, enemigos[j].spriteSize, enemigos[j].gfxpoint, 2);
                spriteIndice++;
            }
            else{ //Si se ven pues claro
                EstablecerPaletaPrincipal(enemigos[j].spriteID);
                MostrarSprite(enemigos[j].spriteIndice, enemigos[j].posx, enemigos[j].posy + scrollY*32, enemigos[j].spriteSize, enemigos[j].gfxpoint, 2);
                spriteIndice++;
            }
            if(enemigos[j].posx > 256 || enemigos[j].posx < -32){
                map1[enemigos[j].tileOrigen].enemigoSpawn = true; // Si el enemigo se pasa de x, la tile que genera enemigos puede volver a generarlos
                BorrarSprite(enemigos[j].spriteIndice, 0, 0, enemigos[j].spriteSize, enemigos[j].gfxpoint, 2);
                enemigos[j].posx = 0;
                enemigos[j].posy = 0;
                enemigos[j].tileOrigen = 0;
                enemigos[j].colOrigen = 0;
                enemigos[j].gestorEnemigo = NULL;
            }
            
        }
        i = 0;
        j = 0;
        k = 0;
        break;
        case 2: //El mapa 2, de dificultad normal
        spriteIndice = 1; //Un ID por cada sprite (siempre aumenta)
        if (scrollY > personaje.estadisticas->nivActual->altura) return;
        for (i = scrollY*8; i < 48 + scrollY*8; i++){ // Lo del scrollY aqui es como un viewport
            switch(map2[i].spriteID){ // Esto se pone asi porque no se puede asignar un puntero al gfx antes de iniciar un programa
                case SUELO_SUELO:
                    if(map2[i].gfxpoint == NULL) map2[i].gfxpoint = sueloSuelo;
                    EstablecerPaletaPrincipal(SUELO_SUELO);
                    break;
                case AGUA_SUELO2:
                    if(map2[i].gfxpoint == NULL) map2[i].gfxpoint = aguaSuelo2;
                    EstablecerPaletaPrincipal(AGUA_SUELO2);
                    
                    break;
                case META_SUELO:
                    if(map2[i].gfxpoint == NULL) map2[i].gfxpoint = metaSuelo;
                    EstablecerPaletaPrincipal(META_SUELO);
                    break;
            }
            map2[i].y = 6 - (map2[i].col - scrollY) - 1;
            if(map2[i].gfxpoint!=NULL) {
                MostrarSprite(spriteIndice, map2[i].x, map2[i].y * 32, map2[i].spriteSize, map2[i].gfxpoint, 3);
            } 
            
            spriteIndice++;    
        }

        for(k = 0;k < personaje.estadisticas->nivActual->tamMapa; k++){
            if(map2[k].enemigoSpawn){ // Esto tendria que estar dentro del switch case del spriteID pero aun solo hay un tipo de "enemigo"
                if(map2[k].x < 128) spawnEnemigo(map2[k].x, (-1)*32*map2[k].col + 160, COCHE_SPRITE2, ESTE, k, map2[k].col);
                else spawnEnemigo(map2[k].x, (-1)*32*map2[k].col + 160, COCHE_SPRITE2, OESTE, k, map2[k].col);
                map2[k].enemigoSpawn = false;
            }
        }
        for (j = 0; j < numEnemigos; j++) { // Actualiza la posicion de los enemigos cada tick del reloj
            enemigos[j].spriteIndice = spriteIndice;
            if(enemigos[j].colOrigen > 6 + scrollY  - 1 || enemigos[j].colOrigen < scrollY - 1){//Si los enemigos están fuera de la vista, no renderiza los sprites, los oculta
                BorrarSprite(enemigos[j].spriteIndice, enemigos[j].posx, enemigos[j].posy + scrollY*32, enemigos[j].spriteSize, enemigos[j].gfxpoint, 2);
                spriteIndice++;
            }
            else{ //Si se ven pues claro
                EstablecerPaletaPrincipal(enemigos[j].spriteID);
                MostrarSprite(enemigos[j].spriteIndice, enemigos[j].posx, enemigos[j].posy + scrollY*32, enemigos[j].spriteSize, enemigos[j].gfxpoint, 2);
                spriteIndice++;
            }
            if(enemigos[j].posx > 256 || enemigos[j].posx < -32){
                map2[enemigos[j].tileOrigen].enemigoSpawn = true; // Si el enemigo se pasa de x, la tile que genera enemigos puede volver a generarlos
                BorrarSprite(enemigos[j].spriteIndice, 0, 0, enemigos[j].spriteSize, enemigos[j].gfxpoint, 2);
                enemigos[j].posx = 0;
                enemigos[j].posy = 0;
                enemigos[j].tileOrigen = 0;
                enemigos[j].colOrigen = 0;
                enemigos[j].gestorEnemigo = NULL;
            }
            
        }
        i = 0;
        j = 0;
        k = 0;
        break;
    }

    int l;
    EstablecerPaletaPrincipal(0); // Lo mismo con el personaje
    MostrarSprite(0,personaje.x, personaje.y, 1, gfxpersonaje, 1);
    
    for (l = 0; l < MAX_MONEDAS; l++){ // Generar monedas funciona igual que generar enemigos, pero las monedas desaparecen cuando se "recogen"
        monedas[l].spriteIndice = spriteIndice;
        if(monedas[l].recogida || monedas[l].posy > 6 + scrollY - 1 || monedas[l].posy < scrollY - 1){
            BorrarSprite(monedas[l].spriteIndice, monedas[l].posx, monedas[l].posy + scrollY*32, monedas[l].spriteSize, monedas[l].gfxpoint, 0);
            spriteIndice++;
        }
        else{
            EstablecerPaletaPrincipal(monedas[l].spriteID);
            MostrarSprite(monedas[l].spriteIndice, monedas[l].posx, (-1)*32*monedas[l].posy + 160 + scrollY*32, monedas[l].spriteSize, monedas[l].gfxpoint, 0);
            spriteIndice++;                     
        }
    }
    consoleClear();
    iprintf("\x1b[4;0H %d segundos", tiempoMaximo);
    iprintf("\x1b[6;0H %d Monedas", personaje.estadisticas->monedas);
    iprintf("\x1b[22;0H Pausa [SELECT]");
    oamUpdate(&oamMain);
    if(floor(personaje.posEnMapa/8) >= personaje.estadisticas->nivActual->altura + 6 - 1){ // Si el personaje ha llegado a la tile más alta del mapa, este gana
        ganar(); // Ganas
    }
}