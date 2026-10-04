#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/types.h>

int main () {

    int i = 0;

    switch (fork()) {
        case -1:
            perror ("Error al crear procesos");
            exit (-1);
            break;
        case 0:             //Codigo para el hijo
            while (i<10000) {
                sleep (0.1);
                printf ("\t\tSoy el proceso hijo: %d\n", 10000-(i++));
            }
            break;
        default:            //Codigo para el padre
            while (i<10000) {
                printf ("Soy el proceso padre: %d\n", i++);
                sleep (0.1);
            }
    };
    exit (0);
}
