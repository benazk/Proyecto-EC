#include <nds.h>
#include "sprites.h"
#include "maps.h"
#include "definiciones.h"

Tile map1[48] = { //El mapa ocupa toda la pantalla y esta compuesto de structs de tipo Tile
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 0, 32, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 0, 64, SPRITE32}, 
    {tileFlor, NULL, FLOR_SUELO, 0, 96, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 0, 128, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 0, 160, SPRITE32},

    {tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 32, 32, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 32, 64, SPRITE32}, 
    {tileFlor, NULL, FLOR_SUELO, 32, 96, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 32, 128, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 32, 160, SPRITE32},
    
    {tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 64, 32, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 64, 64, SPRITE32}, 
    {tileFlor, NULL, FLOR_SUELO, 64, 96, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 64, 128, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 64, 160, SPRITE32},
    
    {tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 96, 32, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 96, 64, SPRITE32}, 
    {tileFlor, NULL, FLOR_SUELO, 96, 96, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 96, 128, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 96, 160, SPRITE32},
    
    {tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 128, 32, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 128, 64, SPRITE32}, 
    {tileFlor, NULL, FLOR_SUELO, 128, 96, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 128, 128, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 128, 160, SPRITE32},
    
    {tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 160, 32, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 160, 64, SPRITE32},
    {tileFlor, NULL, FLOR_SUELO, 160, 96, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 160, 128, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 160, 160, SPRITE32},
    
    {tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 192, 32, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 192, 64, SPRITE32},
    {tileFlor, NULL, FLOR_SUELO, 192, 96, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 192, 128, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 192, 160, SPRITE32},
    
    {tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 224, 32, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 224, 64, SPRITE32},
    {tileFlor, NULL, FLOR_SUELO, 224, 96, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 224, 128, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 224, 160, SPRITE32}
};
void renderMapa(int tipoMapa){
    int i;
    //switch(tipoMapa){
        //case 1:
        GuardarSpritesMemoria(florSuelo, tileFlor, SPRITE32);
        EstablecerPaletaPrincipal(FLOR_SUELO);
        for (i = 0; i < 48; i++){
            EstablecerPaletaPrincipal(map1[i].spriteID);
            switch(map1[i].spriteID){ // Esto se pone asi porque no se puede asignar un puntero al gfx antes de iniciar un programa
                case FLOR_SUELO:
                    map1[i].gfxpoint = florSuelo;
            }
            if(map1[i].gfxpoint!=NULL) {
                iprintf("\x1b[%d;0H esto es datos de gfxpoint %d",i,map1[i].gfxpoint[i]);
                MostrarSprite(1+i, map1[i].x, map1[i].y, map1[i].spriteSize, map1[i].gfxpoint);
            }
            
        }
        oamUpdate(&oamMain);
        i = 0;
        //break;
    //}
}