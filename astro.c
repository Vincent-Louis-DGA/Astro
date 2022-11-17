#include "astro.h"
#include <math.h>
double getSchwarzschild(double masse, double vitesse, int param)
{
    if(masse > 0 && vitesse !=0 && param !=0){
        return (double) ((2 * CONSTANTE_G * masse) / (vitesse * vitesse));
    }

}
