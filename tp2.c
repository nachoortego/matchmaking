#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tp2.h"

// Funciones

Arbol create(){
  return NULL;
}

int isEmpty(Arbol a) {
	return a == NULL;
}

void muestraPreOrder(Arbol a){
	if (!isEmpty(a)) {
		Judoca temp = a->dato;
		printf("%s ",temp->nombre);
		printf("%s ",temp->apellido);
		printf("%i\n",temp->edad);
    	muestraPreOrder(a->izq);
    	muestraPreOrder(a->der);
  	}
}

Arbol agrega(Arbol a, Judoca jugador){
    if (isEmpty(a)) {
        a = malloc(sizeof(TNodo));
        a->dato = jugador;
        a->izq = NULL;
        a->der = NULL;
      }
    else {
        Judoca temp = a->dato;
        if (temp->edad > jugador->edad) 
			a->izq = agrega(a->izq, jugador);
        else 
			a->der = agrega(a->der, jugador);
    }
    return a;
}

Judoca creaJugador(char line[]) 
{
	Judoca jugador = malloc(sizeof(Judoca));
	jugador->nombre = malloc(sizeof(char) * 30);
	jugador->apellido = malloc(sizeof(char) * 30);
	strcpy(jugador->nombre,strtok(line,","));
	strcpy(jugador->apellido, strtok(NULL,","));
	jugador->edad = atoi(strtok(NULL,","));
	return jugador;
}

Arbol creaEquipos (FILE * in, Arbol a, int team)
{
	char line[1000];
	if(team == 1)
	{
		fscanf(in,"%s",line);
		fscanf(in,"%s",line);
		while(strcmp(line,"Equipo2:") != 0)
		{
			Judoca jugador = creaJugador(line);
			a = agrega(a,jugador);
			fscanf(in,"%s",line);
		}
		return a;
	}
	if(team == 2)
	{
		while(fscanf(in,"%s",line) != EOF)
		{
			Judoca jugador = creaJugador(line);
			a = agrega(a,jugador);
		}
		return a;
	}
}

void ejecutaSalida(Arbol equipo1, Arbol equipo2, FILE * out)
{
    salida(equipo1,equipo2,out);
	if (!isEmpty(equipo1->der)) ejecutaSalida(equipo1->der,equipo2,out);
	if (!isEmpty(equipo1->izq)) ejecutaSalida(equipo1->izq,equipo2,out);
}

Arbol buscaMayorDeMenores(Arbol a){
	if  (a->izq == NULL) {
    	return NULL;
  	}
  	else {
	    Arbol t;
    	for(t = a->izq; t->der != NULL; t = t->der);
    	return t;
  	}
}

Arbol formaPareja (int estado, Arbol equipo2, Judoca temp1, Judoca temp2, FILE * out)
{
	if (estado == 0) 
	{
		fprintf(out, "%s %s %i, %s %s %i. Pareja valida.\n", temp1->nombre, temp1->apellido, temp1->edad, temp2->nombre, temp2->apellido, temp2->edad);
		Judoca tempeliminado=equipo2->dato;
		strcpy(tempeliminado->nombre,"Eliminado");
	}
	if (estado == 1) fprintf(out,"%s %s %i, %s %s %i. Pareja no valida. Compuesta por un mayor y un menor de edad\n", temp1->nombre, temp1->apellido, temp1->edad, temp2->nombre, temp2->apellido, temp2->edad);
	if (estado == 2) fprintf(out,"%s %s %i, %s %s %i. Pareja no valida. Compuesta por menores con una diferencia de edad mayor a 1\n", temp1->nombre, temp1->apellido, temp1->edad, temp2->nombre, temp2->apellido, temp2->edad);
	if (estado == 3) fprintf(out,"%s %s %i, %s %s %i. Pareja no valida. Compuesta por mayores con una diferencia de edad mayor a 2\n", temp1->nombre, temp1->apellido, temp1->edad, temp2->nombre, temp2->apellido, temp2->edad);

	return equipo2;
}

int salida (Arbol equipo1, Arbol equipo2, FILE * out)
{
	int estado = 1;

	if (isEmpty(equipo2) || estado == 0) 
	{
		Judoca temp1 = equipo1->dato;
		fprintf(out,"No hubo coincidencias con %s\n", temp1->nombre);
		return 0;
	}
	if (!isEmpty(equipo2))
	{
		Judoca temp1 = equipo1->dato;
		Judoca temp2 = equipo2->dato;
		if (strcmp(temp2->nombre,"Eliminado") == 0) estado = 4;
		else if(temp2->edad >= 18 && temp1->edad >= 18)
		{
			if(abs(temp2->edad - temp1->edad) <= 2)
			{
				/*Forma la pareja*/
				estado = 0;
				equipo2 = formaPareja(estado,equipo2,temp1,temp2,out);
			}
			else
			{
				estado = 3;
				equipo2 = formaPareja(estado,equipo2,temp1,temp2,out);
			}
		}
		else if(temp2->edad < 18 && temp1->edad < 18)
		{
			if(abs((temp2->edad) - (temp1->edad)) <= 1)
			{
				/*Forma la pareja*/
				estado = 0;
				equipo2 = formaPareja(estado,equipo2,temp1,temp2,out);
			}
			else 
			{
				estado = 2;
				equipo2 = formaPareja(estado,equipo2,temp1,temp2,out);
			}
		}
		else
		{
		estado = 1;
		equipo2 = formaPareja(estado,equipo2,temp1,temp2,out);
		}

		if (estado != 0 )
		{
			if(temp2->edad > temp1->edad) salida(equipo1,equipo2->izq,out);
			else salida(equipo1,equipo2->der,out);
		}

		else if(estado == 0)
		{
			return 0;
		}
	}
}



void freeJudoca(Arbol a)
{
	printf("1");
	free(((Judoca)a->dato)->nombre);
	printf("2");
	free(((Judoca)a->dato)->apellido);
	printf("3");
	free((Judoca)a->dato);
	printf("4");
	free(a);
	printf("5");
	a = NULL;
	printf("6\n");
}

void elimina(Arbol a)
{
	if(!isEmpty(a))
	{
		printf("rip %s",((Judoca)a->dato)->nombre);
		freeJudoca(a);
		elimina(a->der);
		elimina(a->izq);
	}
}
