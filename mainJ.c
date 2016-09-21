#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcionesJ.c"

#define dim 4
   int main(){
		
		
			bool conv;			  // variable para analizar si converge el metodo de jacobi	
			float err;            //variable utilizada para almacenar el error alcanzado en caso de obtener una solucion
			int iterc;            // variable utilizada para almacenar el numero de iteraciones realizadas en caso de obtener una solucion
			float cota=0.000007; //cota de error elegida
			double itM=1000;         //maximo numero de iteraciones
			double A[dim][dim];
			double B[dim];
			double X[dim];
			
			char *nomArch="matr3F.txt";    //txt con la matriz diagonal dominante
			char *nomArB="vect3F.txt";        //txt con la matriz B
			char *nomX="matX4.txt";			//txt con la matriz X
			
			cargarMat(dim,A,nomArch);
			cargarVect(dim,B,nomArB);
			cargarVect(dim,X,nomX);
			clock_t start= clock();
			conv=jacobi(dim,A,B,X,cota,itM,&err,&iterc);
			clock_t end=clock();
			if(conv){
				printf("Resultado exitoso!! \n");
				mostrarDatos(dim,X,err,iterc);
				printf("Tiempo transcurrido es : %f",((double)(end-start)/(double)CLOCKS_PER_SEC ));
			}else{
				printf("Se ha alcanzado el maximo numero de iteraciones sin exito! \n");
				printf("Tiempo transcurrido es : %f",((double)(end-start)/(double)CLOCKS_PER_SEC ));
			}
			printf("\n");
			return 0;
	}
