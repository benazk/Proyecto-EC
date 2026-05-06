#include <nds.h>
#include <math.h>
#include "gestionEntidades.h"
#include "definiciones.h"
#include "structs.h"
#include "sprites.h"
#include "juego.h"
#include "maps.h"

extern Enemigo enemigos[MAX_ENEMIGOS];
extern Prota personaje;
extern int numEnemigos;
extern int spriteIndice;
extern int scrollY;
bool subirBarca = 0;
void movEnemigo(){
    personaje.enBarca = false;
    subirBarca = 0;
    int i;
    for(i = 0; i < numEnemigos; i++){
        if(enemigos[i].gestorEnemigo != NULL) {
            enemigos[i].gestorEnemigo(&enemigos[i]);
        }
    }
    i = 0;
    
}
void GM(Enemigo *self){ // Como se mueve de izquierda a derecha y viceversa, tengo una variable dirección y vuelvo a dibujar el sprite cada vez que lo muevo
    if(self->direccion==OESTE) self->posx-=1;
    else if(self->direccion==ESTE) self->posx+=1;
    subirBarca |= VerificarColision(self->posx, personaje.x, self->posy + scrollY*32, personaje.y, 32, 32, 32, 32, self->direccion) && collisionOffsetx < 16 && collisionOffsety==0 && personaje.x > 0 && personaje.x < 224;
    if(subirBarca){
        personaje.enBarca = true;
        personaje.x = self->posx;
        if((personaje.x % 32)==0 && self->direccion == ESTE){
            personaje.posEnMapa++;
        }
        if((personaje.x % 32)==0 && self->direccion == OESTE){
            personaje.posEnMapa--;
        }
    }
}

void estaPersonaje(){
    subirBarca = 0;
    int i;
    for(i = 0; i < numEnemigos; i++){
        if(enemigos[i].gestorEnemigo != NULL) {
            subirBarca |= VerificarColision(enemigos[i].posx, personaje.x, enemigos[i].posy + scrollY*32, personaje.y, 32, 32, 32, 32, enemigos[i].direccion) && collisionOffsetx < 16 && collisionOffsety==0 && personaje.x > 0 && personaje.x < 224;
        }
    }
    i = 0;
}