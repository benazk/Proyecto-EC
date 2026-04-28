#include <nds.h>
#include "sprites.h"
#include "maps.h"
#include "definiciones.h"
#include "structs.h"
#include "juego.h"
#include <math.h>
extern Enemigo enemigos[MAX_ENEMIGOS];
extern int numEnemigos;
extern Prota personaje;
Tile map1[96] = { //El mapa ocupa toda la pantalla y esta compuesto de structs de tipo Tile (de structs.h en /included/)
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, false, true},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, false, true},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, false, true},
    
    {tileAgua, NULL, AGUA_SUELO, 0, 0, SPRITE32, true, false},{tileAgua, NULL, AGUA_SUELO, 32, 0, SPRITE32, false, false},{tileAgua, NULL, AGUA_SUELO, 64, 0, SPRITE32, false, false},{tileAgua, NULL, AGUA_SUELO, 96, 0, SPRITE32, false, false},{tileAgua, NULL, AGUA_SUELO, 128, 0, SPRITE32, false, false},{tileAgua, NULL, AGUA_SUELO, 160, 0, SPRITE32, false, false},{tileAgua, NULL, AGUA_SUELO, 192, 0, SPRITE32, false, false},{tileAgua, NULL, AGUA_SUELO, 224, 0, SPRITE32, false, false},
    
    {tileAgua, NULL, AGUA_SUELO, 0, 0, SPRITE32, false, false},{tileAgua, NULL, AGUA_SUELO, 32, 0, SPRITE32, false, false},{tileAgua, NULL, AGUA_SUELO, 64, 0, SPRITE32, false, false},{tileAgua, NULL, AGUA_SUELO, 96, 0, SPRITE32, false, false},{tileAgua, NULL, AGUA_SUELO, 128, 0, SPRITE32, false, false},{tileAgua, NULL, AGUA_SUELO, 160, 0, SPRITE32, false, false},{tileAgua, NULL, AGUA_SUELO, 192, 0, SPRITE32, false, false},{tileAgua, NULL, AGUA_SUELO, 224, 0, SPRITE32, true, false},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, false, true},

    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, false, true},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, false, true}, {tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, false, true},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, false, true},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, false, true},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, false, true},
    
    {tileFlor, NULL, FLOR_SUELO, 0, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 32, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 64, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 96, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 128, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 160, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 192, 0, SPRITE32, false, true},{tileFlor, NULL, FLOR_SUELO, 224, 0, SPRITE32, false, true}
};
void renderMapa(int tipoMapa){ //Pinta el mapa en pantalla 
    if (48 + scrollY*8 > 96) return;
    int i;
    //switch(tipoMapa){
        //case 1:
        GuardarSpritesMemoria(florSuelo, tileFlor, SPRITE32); //Es necesario guardar todos los sprites necesarios en memoria antes de nada
        GuardarSpritesMemoria(aguaSuelo, tileAgua, SPRITE32);  
        GuardarSpritesMemoria(gfxCoche, cocheMap, SPRITE32);
        spriteIndice = 1;
        for (i = scrollY*8; i < 48 + scrollY*8; i++){ // Lo del scrollY aqui es como un viewport
            switch(map1[i].spriteID){ // Esto se pone asi porque no se puede asignar un puntero al gfx antes de iniciar un programa
                case FLOR_SUELO:
                    map1[i].gfxpoint = florSuelo;
                    EstablecerPaletaPrincipal(FLOR_SUELO);
                    break;
                case AGUA_SUELO:
                    map1[i].gfxpoint = aguaSuelo;
                    EstablecerPaletaPrincipal(AGUA_SUELO);
                    
                    break;
            }
            map1[i].y = 160 - 32 * floor((i-scrollY*8)/8);
            if(map1[i].gfxpoint!=NULL) {
                MostrarSprite(spriteIndice+i - scrollY*8, map1[i].x, map1[i].y, map1[i].spriteSize, map1[i].gfxpoint, 2);
            }
            spriteIndice++;
            if(map1[i].enemigoSpawn){ // Esto tendria que estar dentro del switch case del spriteID pero aun solo hay un tipo de "enemigo"
                if(map1[i].x < 32) spawnEnemigo(map1[i].x, map1[i].y, COCHE_SPRITE, ESTE);
                if(map1[i].x > 192) spawnEnemigo(map1[i].x, map1[i].y, COCHE_SPRITE, OESTE);
                map1[i].enemigoSpawn = false;
            }

            int j;
            for (j = 0; j < numEnemigos; j++) { // Actualiza la posicion de los enemigos cada tick del reloj
                EstablecerPaletaPrincipal(enemigos[j].spriteID);
                MostrarSprite(enemigos[j].spriteIndice,enemigos[j].posx,enemigos[j].posy + scrollY * 32,enemigos[j].spriteSize,enemigos[j].gfxpoint,1);
                if(enemigos[j].posx > 256 || enemigos[j].posx < -32){ //Si el enemigo se sale de la pantalla, será "eliminado" de la lista de enemigos (su pointer a la funcion GM será null)
                    enemigos[j].posx = 0;
                    enemigos[j].posy = 0;
                    enemigos[j].spriteSize = 0;
                    enemigos[j].spriteID = 0;
                    enemigos[j].gfxpoint = NULL;
                    enemigos[j].gestorEnemigo = NULL;
                }
            }
            EstablecerPaletaPrincipal(0); // Lo mismo con el personaje
            MostrarSprite(0,personaje.x, personaje.y, 1, gfxpersonaje, 0);
            
        }
        oamUpdate(&oamMain);
        i = 0;
        //break;
    //}
}