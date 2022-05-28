# matchmaking 

Programa escrito en C, implementanto punteros y utilizando Árboles Binarios como estructura de datos.

El mismo recibe un archivo TXT de dos equipos de Judo y sus integrantes; con nombre, apellido y edad (incluye ejemplo).
Luego, arma parejas para enfrentarse entre sí, teniendo en cuenta la edad.

Instrucciones para ejecutar:
  ./main datos.txt salida.txt

Instrucciones para compilar:
  gcc -c tp2.c
  gcc -Wall -o main main.c tp2.o 

Árboles binarios creados por el programa usando la entrada de ejemplo:

                        Robert Mshvidobadze 30
                        /                   \
            Idalys Ortiz 29             Amiran Papinashvili 31
            /               \
Daria Bilodid 18        Lukhumi Chkhvimiani 26
            \
        Madeleine Malonga 25



                        Clarisse Agbegnenou 26
                    /                           \
        Ryuju Nagayama 23                   Sharafuddin Lutfillaev 28
        /               \                       /
Uta Abe 19         Tsukasa Yoshida 23    Naohisa Takato 26

Nota: 
  Este proyecto fue realizado antes de que aprenda a usar git, por lo que no cuenta con commits.
