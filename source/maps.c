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
void renderMapa(int tipoMapa){ //Pinta el mapa en pantalla 
    
    int i;
    switch(tipoMapa){
        case 1:
        GuardarSpritesMemoria(florSuelo, tileFlor, SPRITE32); //Es necesario guardar todos los sprites necesarios en memoria antes de nada
        GuardarSpritesMemoria(aguaSuelo, tileAgua, SPRITE32);  
        GuardarSpritesMemoria(gfxCoche, cocheMap, SPRITE32);
        GuardarSpritesMemoria(metaSuelo, metaTile, SPRITE32);
        GuardarSpritesMemoria(monedaSuelo, monedaTile, SPRITE32);
        
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

        
        int k;
        for(k = 0;k < personaje.estadisticas->nivActual->tamMapa; k++){
            if(map1[k].enemigoSpawn){ // Esto tendria que estar dentro del switch case del spriteID pero aun solo hay un tipo de "enemigo"
                if(map1[k].x < 128) spawnEnemigo(map1[k].x, (-1)*32*map1[k].col + 160, COCHE_SPRITE, ESTE, k, map1[k].col);
                else spawnEnemigo(map1[k].x, (-1)*32*map1[k].col + 160, COCHE_SPRITE, OESTE, k, map1[k].col);
                map1[k].enemigoSpawn = false;
            }
        }
        int j;
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
                enemigos[j].spriteSize = 0;
                enemigos[j].spriteID = 0;
                enemigos[j].gfxpoint = NULL;
                enemigos[j].tileOrigen = 0;
            }
            
        }

        int l;
        for (l = 0; l < numMonedas; l++){
            if(!monedas[l].recogida){
                monedas[l].spriteIndice = spriteIndice;
                EstablecerPaletaPrincipal(monedas[l].spriteID);
                MostrarSprite(monedas[l].spriteIndice, monedas[l].posx, monedas[l].posy + scrollY*32, monedas[l].spriteSize, monedas[l].gfxpoint, 0);
                spriteIndice++;
            }
        }

        EstablecerPaletaPrincipal(0); // Lo mismo con el personaje
        MostrarSprite(0,personaje.x, personaje.y, 1, gfxpersonaje, 1);
        oamUpdate(&oamMain);
        if(floor(personaje.posEnMapa/8) >= personaje.estadisticas->nivActual->altura + 6 - 1){
            ganar(); // Ganas
        }
        j = 0;
        i = 0;
        break;
    }
}