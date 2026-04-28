#include <nds.h>
#include <math.h>
#include "gestionEntidades.h"
#include "definiciones.h"
#include "structs.h"
#include "sprites.h"

extern Enemigo enemigos[MAX_ENEMIGOS];
extern Prota personaje;
extern int numEnemigos;
extern int spriteIndice;
extern int scrollY;

void movEnemigo(){
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
    if(VerificarColision(self->posx, personaje.x, self->posy + scrollY*32, personaje.y, 32, 32, 32, 32, self->direccion) && collisionOffsetx < 10 && collisionOffsetx==0){
        iprintf("\x1b[5;0H colision entre prota y \"tronco\"");
        personaje.x = self->posx;
        EstablecerPaletaPrincipal(0);
        MostrarSprite(0,personaje.x, personaje.y, 1, gfxpersonaje, 0);
    }
    else iprintf("\x1b[5;0H                                ");
    

}
