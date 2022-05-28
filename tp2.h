#ifndef __TP__H__
#define __TP__H__
#include <stddef.h>

// Estructuras 

typedef struct {
char * nombre , * apellido ;
int edad ;
} _Judoca ;
typedef _Judoca * Judoca ;

typedef struct _TNodo {
void * dato ;
struct _TNodo * izq , * der ;
} TNodo ;
typedef TNodo * Arbol ;

// Funciones

/*Crea un arbol nuevo*/
Arbol create();

/*Si el arbol esta vacio*/
int isEmpty(Arbol a);

/*Agrega jugador a un arbol*/
Arbol agrega(Arbol a, Judoca jugador);

/*Imprime un arbol*/
void muestraPreOrder(Arbol a);

/*Forma los equipos*/
Arbol creaEquipos (FILE * in, Arbol a, int team);

/*Crea la structura jugador*/
Judoca creaJugador(char line[]);

/*Itera el primer equipo para ejecutar la función salida*/
void ejecutaSalida(Arbol equipo1, Arbol equipo2, FILE * out);

/*Crea las parejas comparando los árboles*/
int salida (Arbol equipo1, Arbol equipo2, FILE * out);

/*Despliega las parejas validas y no validas*/
Arbol formaPareja (int estado, Arbol equipo2, Judoca temp1, Judoca temp2, FILE * out);

/*Libera la memoria*/
void freeJudoca(Arbol a);

/*Busca el mayor de los menores de los nodos de un árbol*/
Arbol buscaMayorDeMenores(Arbol a);

/*Elimina un nodo de un árbol considerando 3 casos distintos*/
void elimina(Arbol a);


#endif