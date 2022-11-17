#include "astro.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <errno.h>
int main(int argc, char *argv[])
{
    char *pFin = NULL, *pStr = NULL;
    double speed = 0.;
    double masse = 0.;
    double schwarzschild = 0.;
    int param = 0 ;

    if(argc < 2){
        fprintf(stderr, "Usage: %s [masse en kilogrammes]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    pStr = argv[1];
    masse = strtod(pStr, &pFin);
    /* vérification des erreurs de paramètre */
    if ((errno == ERANGE && (masse == HUGE_VALL || masse == HUGE_VALF))
            || (errno != 0 && masse == 0)) {
        perror("strtod");
        exit(EXIT_FAILURE);
    }
    if (pFin == pStr) {
        fprintf(stderr, "Pas de chiffre trouvé\n");
        exit(EXIT_FAILURE);
    }

    pStr = argv[2];
    speed = strtod(pStr, &pFin);

    pStr = argv[3];
    param = strtod(pStr, &pFin);

    /* calcul du rayon de Swartzschild */
    schwarzschild = getSchwarzschild(masse, speed, param);
    fprintf(stdout, "Schwarzschild(%.2e kg) = %.2e m\n", masse, schwarzschild);
    exit(EXIT_SUCCESS);
}
