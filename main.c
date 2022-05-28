#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tp2.h"

int main(int argc, char * argv[]) {

    FILE * in, * out;
    in = fopen(argv[1],"r");
    out = fopen(argv[2],"w");

    if(argv[1] == NULL || argv[2] == NULL) 
    {
        printf("Recuerda especificar un archivo de entrada y uno de salida\nEjemplo:\n./main datos.txt salida.txt\n\n");
        return 1;
    }
    
    Arbol equipo1, equipo2;
    equipo1 = create();
    equipo2 = create();
    equipo1 = creaEquipos(in,equipo1,1);
    equipo2 = creaEquipos(in,equipo2,2);

    ejecutaSalida(equipo1,equipo2,out);

    fclose(in);
    fclose(out);

    elimina(equipo1);
    elimina(equipo2);

    return 0;
}