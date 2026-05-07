
#ifndef STRUCTS_H
#define STRUCTS_H
#include <nds.h>
#include <stdio.h>
#include <stdlib.h>	
#include <unistd.h>	


typedef struct { // AÚN NO HE HECHO NADA CON ESTO
    int altura; // Numero que tiene que alcanzar scrollY para cubrir el mapa sin pasarse
    int tamMapa; //Longitud del array del mapa
    int dificultad; // Si la dificultad es alta, las cosas se moverán más rápido
}Nivel;

typedef struct {
    int monedas;
    int nivelNum;
    Nivel *nivActual;
}Stats;

typedef struct { //Prota
    int x;
    int y;
    int posEnMapa;
    bool vivo; 
    Stats *estadisticas;
}Prota;



typedef struct{  //Esto será para poner tiles (tambien pueden ser adornos encima del suelo u obstáculos estáticos)
    u8* spriteBitMap;
    u16* gfxpoint;
    int spriteID;
    int x;
    int y;
    int spriteSize;
    int col; // Esto es un apaño para que funcione
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
    int tileOrigen; //Es el indice del array de tiles del cual ha aparecido
    int colOrigen;
    void (*gestorEnemigo)(Enemigo* self);
};
typedef struct Moneda Moneda;
struct Moneda{
    u8* spriteBitMap;
    u16* gfxpoint;
    int posx;
    int posy;
    int size;
    int spriteID;
    int spriteSize;
    int spriteIndice;
    int valor;
    bool recogida;
    void (*gestorMoneda)(Moneda* self);
};

#endif