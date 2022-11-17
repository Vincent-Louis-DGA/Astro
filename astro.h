#ifndef ASTRO_H
#define ASTRO_H
#define VITESSE 299792458
#define CONSTANTE_G 6.67300e-11
/* paramètre : masse en kilogramme
   retourne : le rayon de Schwarzschild en mètre */
double getSchwarzschild(double masse, double vitesse, int param);
#endif
