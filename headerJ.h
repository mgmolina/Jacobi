/*contiene declaracion de variables y funciones*/
#ifndef FUNCIONESJH
#define FUNCIONESJH
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>


void cargarMat(int dim,double  A[dim][dim],char *nom);
void cargarVect(int dim,double B[dim],char *nom);
float errorCalc1(int dim,double auxErr[dim]);
bool jacobi(int dim,double A[dim][dim],double B[dim],double X[dim],float errorB,double maxIt,float *err,int *it);
void mostrarDatos(int dim,double X[dim],float e,int it);


#endif
