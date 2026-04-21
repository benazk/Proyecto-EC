#include <nds.h>
#include "sprites.h"
#include "maps.h"
#include "definiciones.h"
#include <math.c>

Tile map1[96] = { //El mapa ocupa toda la pantalla y esta compuesto de structs de tipo Tile
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32},

    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32}, {tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32}
};
void renderMapa(int tipoMapa){ //Pinta el mapa en pantalla 
    if (48 + scrollY*8 > 96) return;
    int i;
    //switch(tipoMapa){
        //case 1:
        GuardarSpritesMemoria(florSuelo, tileFlor, SPRITE32); //Es necesario guardar todos los sprites necesarios en memoria antes de nada
        //GuardarSpritesMemoria(aguaSuelo, tileAgua, SPRITE32);
        
        for (i = scrollY*8; i < 48 + scrollY*8; i++){
            switch(map1[i].spriteID){ // Esto se pone asi porque no se puede asignar un puntero al gfx antes de iniciar un programa
                case FLOR_SUELO:
                    map1[i].gfxpoint = florSuelo;
                    EstablecerPaletaPrincipal(FLOR_SUELO);
                /*case AGUA_SUELO:
                    iprintf("\x1b[23;%dH flor", i);
                    map1[i].gfxpoint = aguaSuelo;
                    EstablecerPaletaPrincipal(AGUA_SUELO);    */
            }
            map1[i].y = 32 * floor((i-scrollY*8)/8);
            if(map1[i].gfxpoint!=NULL) {
                MostrarSprite(1+i, map1[i].x, map1[i].y, map1[i].spriteSize, map1[i].gfxpoint);
            }
            
        }
        oamUpdate(&oamMain);
        i = 0;
        //break;
    //}
}