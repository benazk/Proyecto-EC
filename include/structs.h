
#ifndef STRUCTS_H
#define STRUCTS_H
#include <nds.h>
#include <stdio.h>
#include <stdlib.h>	
#include <unistd.h>	

typedef struct { //Prota
    int x;
    int y;
    int posEnMapa;
    bool vivo;
    bool enBarca;  
}Prota;

typedef struct { // AÚN NO HE HECHO NADA CON ESTO
    int altura;
    float tiempo;
}Nivel;

typedef struct{  //Esto será para poner tiles (tambien pueden ser adornos encima del suelo u obstáculos estáticos)
    u8* spriteBitMap;
    u16* gfxpoint;
    int spriteID;
    int x;
    int y;
    int spriteSize;
    bool enemigoSpawn;
    bool caminable;
    bool estaPersonaje;
}Tile;

typedef struct Enemigo Enemigo;
struct Enemigo {  //El struct que contiene los datos de los enemigos 
    u8* spriteBitMap;
    u16* gfxpoint;
    int posx;
    int posy;
    int direccion; //La direccion de donde spawnea el enemigo
    int spriteID; 
    int spriteSize; // Tamaño de sprite para oam
    int spriteIndice; // El num de sprite a pasarle al oam
    void (*gestorEnemigo)(Enemigo* self);
};


/*typedef struct {
    int monedas;
    int nivelNum;
    Nivel *nivActual;
}Stats;*/
#endif