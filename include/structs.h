
#ifndef STRUCTS_H
#define STRUCTS_H
#include <nds.h>
#include <stdio.h>
#include <stdlib.h>	
#include <unistd.h>	

typedef struct { //Prota
    int x;
    int y;
    bool vivo;
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
}Tile;

typedef struct{  //El struct que contiene los datos de los enemigos 
    //void (*GestionPosicion)(int *posx,int *posy); es una funcion asignada al struct (algo así como un método de clase)
    u8* spriteBitMap;
    u16* gfxpoint;
    int posx;
    int posy;
    int spriteID; 
    int spriteSize; // Tamaño de sprite para oam
    int spriteIndice; // El num de sprite a pasarle al oam
}Enemigo;


/*typedef struct {
    int monedas;
    int nivelNum;
    Nivel *nivActual;
}Stats;*/
#endif