#include "headerJ.h"	
 
 void cargarMat(int dim,double A[dim][dim],char *nom){
		//busca en un archivo de texto los datos de una matriz de tmaño dim
		//y los guarda en la matriz A
		//parametros: A matriz de dimxdim y *nom: puntero con el nombre del archivo
		//            dim entero con el tamño de las matrices 
		
		FILE *fuente;
		
		if((fuente=fopen(nom,"r"))==NULL){
			printf("No se ha encontrado el archivo.");
		}
		int i,j;
	
		for(i=0;i<dim;i++){
			for(j=0;j<dim;j++){
				fscanf(fuente,"%lf",&A[i][j]);
			}
			
		}
		fclose(fuente);	
	}
	
	void cargarVect(int dim,double B[dim],char *nom){
		//busca en un archivo de texto los datos de una vector de tmaño dim
		//y los guarda en el vector B
		//parametros: B vector de dim y *nom: puntero con el nombre del archivo
		//            dim entero con el tamño de las matrices 
	
		FILE *fuente;
		
		if((fuente=fopen(nom,"r"))==NULL){
			printf("No se ha encontrado el archivo.");
		}
		int i;
	
		for(i=0;i<dim;i++){
			fscanf(fuente,"%lf",&B[i]);
		}
		fclose(fuente);	
	}
	
	float errorCalc1(int dim,double auxErr[dim]){
		//funcion que calcular el error en cada iteracion
		//obtiene el error mediante el calculo de la norma infinita que es el max(valor abs(aux-X[i])) para 
		//i=0 hasta dim 
     	// en aux esta almacenado el nuevo valor de X[i]
		
		//entrada: auxErr vector de double de tamaño dim con el valor absoluto de aux- X[i],esto es
		//         valor actual - valor anterior
		//         dim entero con el tamño de las matrices 
		//salida:  errorA numero real con el valor del error obtenido en cada iteracion
		
		
		//tomo como maximo error el valor almacenado en la posicion 0
		float errorA=auxErr[0];
		int i;

		for(i=1;i<dim;i++){
			//si algun valor en auxErr[i] es mayor que el error actual entonces éste valor es el nuevo error 
			if(auxErr[i]>errorA){
				errorA=auxErr[i];
			}
		}

		return errorA;
	}
	
	bool  jacobi(int dim,double A[dim][dim],double B[dim],double X[dim],float cota,double maxIt,float *err,int *it){
		//funcion jacobi
		//entrada: A matriz de numeros reales de dimxdim, B vector de numeros reales de tamaño dim,
		//         X vector con la solucion inicial, de numeros reales y tamaño dim,
		//         cota nro real con la maxima cota de error permitida,
		//         maxIt numero entero, maximo numero de iteraciones permitido -hacer un define-,
		//         *it puntero a entero para poder retornar el numero de iteraciones realizado en caso de hallar una
		//         solucion,
		//         *err puntero a real para poder retornar el error logrado en caso de alcanzar una solucion.		
		//         dim entero con el tamño de las matrices 
		//salida : booleano indicando exito o fracaso
		//Aux:     errorVect vector de numeros reales de tamaño dim, utilizado para calcular el error en cada it,
		//         aux numero real utilizado para almacenar la nueva solucion X[i] obtenida en cada iteracion
		//         Xaux vector de numeros reales de tamaño dim utilizado para almacenar el nuevo valor de 
		//         la nueva solucion Xi (el vector) obtenida en cada iteracion, si lo guardase en X[i]=aux , el metodo se transformaria
		//		   en el metodo de Gauss-Seidel.      
			
			*it=0;   
			double aux;
			*err=100;
			double errorVect[dim];
			double  Xaux[dim]; //trate de evitar usar esta variable auxiliar
			bool salida=false;   
			int i,j;
		
			//mientras el numero de iteraciones sea menor que el maximo permitido y el error actual sea mas 
			//grande que el error permitdo -es decir que no se ha alcanzado una solucion-
		
			while(*it<maxIt && *err>=cota){
				//recorro todas las filas de A
				for(i=0;i<dim;i++){
					aux=0;
					
					//recorro todas las columnas
					for(j=0;j<dim;j++){
						if(i!=j){
							//calculo del nuevo valor X[i] para i!=j
							aux=aux+A[i][j]*X[j];
						}
					}
					// valor final del nuevo valor X[i] tomando tambien i=j
					aux=(B[i]-aux)/A[i][i];	

					//guardo en el vector para calcular el error 
					errorVect[i]=fabs(aux-X[i]);
					
					//guardo en Xaux[i] para no sobreeescribir X[i] 
					Xaux[i]=aux;
				}
			
				//aumento el numero de iteraciones 
				*it=*it+1;
	             
	             //calculo el error actual 		
				*err=errorCalc1(dim,errorVect);
			
				//realizo X[i]=Xaux[i]  es la nueva aproximacion de X
				for(i=0;i<dim;i++){
					X[i]=Xaux[i];
				}
			}
			if(*it<maxIt)
				salida=true;
			
			return salida;
			
	}
	
	void mostrarDatos(int dim,double  X[dim],float e,int it){ //,float error,int iteraciones
		int i;
		
		printf("\nEl resultado es : \n");
		for(i=0;i<dim;i++){
			printf(" %.6lf",X[i]);
		}
		printf("\n");
		printf("El error es: %f", e);
		printf("\n El numnero de iteraciones es:%d",it);
		printf("\n");
	}
	
