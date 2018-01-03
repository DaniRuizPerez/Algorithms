/* Ismael Barbeito Vázquez (i.barbeito)
	Daniel Ruiz Pérez (d.ruiz.perez) 
	Algoritmos, curso 2012/2013
	5/10/2012

Especificaciones del computador (alba03181):
	- Procesador: Intel(R) Core(TM)2 Duo CPU E7300 @ 2.66GHz
	- Caché L2: 3072KB
	- Mem. principal: 3GB
	- Kernel: 2.6.32-42-generic*/

#include <stdio.h>
#include <sys/time.h>
#include <math.h>
#include <stdlib.h>


   	/*   MÓDULOS Y FUNCIONES AUXILIARES   */

/*Módulo hora*/
/* obtiene la hora actual en microsegundos */
double microsegundos() {
	struct timeval t;
	if (gettimeofday(&t, NULL) < 0 )
		return 0.0;
	return (t.tv_usec + t.tv_sec * 1000000.0);
}

// funcion auxiliar max

int max (int a, int b, int c){
	int aux = b;
	if (a > aux) {
		aux = a;
	}
	if (c > aux) {
		aux = c;
	}			

	return aux;
}


void inicializar_semilla() {
	srand(time(NULL));
/* se establece la semilla de una nueva serie de enteros pseudo-aleatorios */
}
void aleatorio_mod10(int v [], int n) {
	int i;
	for (i=0; i < n; i++)
		v[i] = (rand() % 21) - 10;
/* genera un número pseudoaleatorio entre -10 y +10 */
}



/*Procedimiento cotas*/
/* Este procedimiento recibe el número de sumamax que vamos a ejecutar y devuelve las funciones subestimada, ajustada y sobreestimada correstpondientes a esa sumamax.*/
void cotas (double *subestimada, double *ajustada, double *sobreestimada,int actual, int n) {

	if (actual == 1) {
		*subestimada = pow(n, 1.6);
		*ajustada = pow (n,2);
		*sobreestimada = pow(n,2.2);
	}
		if (actual == 2) {
		*subestimada = log(n)*pow(n,0.8);
		*ajustada = pow(n,0.98)*log(n);
		*sobreestimada = pow(n,1.18);
	} 
}

	/*   FIN FUNCIONES Y MÓDULOS AUXILIARES   */




	 /*    EJERCICIO 1    */
	


int sumaSubMax1 (int *v, int n){
	int estaSuma, sumaMax = 0;
	int i,j;
	for ( i = 0; i< n; i++) {
		estaSuma = 0;
		for (j = i; j<n; j++){
			estaSuma = estaSuma + v[j];
			if (estaSuma > sumaMax) {
	 		 	sumaMax = estaSuma;
			}
		}
	}
	return sumaMax;
}


int sumaSubMax2 (int *v, int n) {
	return sumaSubMaxAux (v,0,n-1);
}

int sumaSubMaxAux (int *v, int izq, int der) {
	if (izq == der) {
		if (v[izq] > 0) {
			return v[izq];		
		} 	
		else {
			return 0;
		}
	}
	else {
		int centro = (izq+der) / 2;
		int sumDer = sumaSubMaxAux (v, centro + 1, der);
		int sumIzq = sumaSubMaxAux (v, izq, centro);
		int sumBordeDer = 0;
		int sumAux = 0;
		int i;
		for (i = centro + 1 ; i <=der; i++) {
			sumAux = sumAux + v[i];
			if (sumAux > sumBordeDer){
				sumBordeDer = sumAux;
			}		
		}
		int sumBordeIzq = 0;
		sumAux= 0;
		for (i= centro ; i>= izq; i--){
			sumAux= sumAux + v[i];
			if (sumAux > sumBordeIzq) {
				sumBordeIzq = sumAux;
			}
		}
		return max(sumIzq, sumDer, sumBordeIzq + sumBordeDer);
	}
}

	 /*   FIN EJERCICIO 1    */



	 /*  	EJERCICIO 2	    */


//funcion auxiliar test (para el segundo ejercicio)

void test (int a0, int a1, int a2, int a3, int a4){
	int *v = (int*) malloc(5*sizeof(int));
	v[0] = a0;
	v[1] = a1;
	v[2] = a2;
	v[3] = a3;
	v[4] = a4;
	printf("\nVector = %d %d %d %d %d\n",a0,a1,a2,a3,a4);
	printf("Algoritmo1 : %d\n", sumaSubMax1 (v, 5));
	printf("Algoritmo2: %d\n\n",sumaSubMax2 (v, 5));
	free(v);
}

void ejerciciodos() {
	
	printf("\n EJERCICIO 2: Probamos los algoritmos y verificamos que funcionan correctamente \n");

	test(-10,10,-10,10,-10);
	test(0,0,0,0,0);

	test (-9,2,-5,-4,6);
	test (4,0,9,2,5);
	test (-2,-1,-9,-7,-1);
	test(9,-2,1,-7,-8);
	test(15,-2,-5,-4,16);
	test(7,-5,6,7,-7); 

	printf("\n Efectivamente funcionan correctamente \n");

}

	 /*   FIN EJERCICIO 2  */


 	 /*	EJERCICIO 3		*/	

void ejerciciotres (int actual,int (*sumaactual)(int*,int)){ //es (int*, int) por que recibe un puntero a un int y un int
	//Variables
	int n,i,inicio = 500, limite = 32000, escalar = 2, repetir, numalgo;
	double t1, t2, t;
	double subestimada, ajustada,sobreestimada;


	printf("\n                      SUMASUBMAX %d",actual,"\n\n");

	if (actual == 1) {
		printf("\n subestimada = pow(n,1.8)");
		printf("\n ajustada = pow (n,2)");
		printf("\n sobreestimada = pow(n,2.2)\n");

	}

	else {
		printf("\n subestimada= log(n)*pow(n,0.8)");
		printf("\n ajustada = pow(n,0.98)*log(n)");
		printf("\n sobreestimada = pow(n,1.18)\n");
		inicio = 4000; 
		limite =256000;
	}

	printf ("\n                        | subestimada |  ajustada   |sobreestimada|");
	printf("\n  |    n    |    t(n)   |  t(n)/h(n)  |  t(n)/g(n)  |  t(n)/f(n)  |\n ");
	printf (" |---------|-----------|-------------|-------------|-------------|\n");

	for (repetir = 1; repetir <=3; repetir++) {
			for (n = inicio; n <= limite; n=escalar*n) {	
			
				int *v = malloc(n*sizeof(int));
				aleatorio_mod10(v,n);

				t1 = microsegundos();
				sumaactual(v, n);
				t2 = microsegundos();
				t = t2-t1;
 				int promedio= 0;
				if (t < 500) {
					promedio= 1;
					t1 = microsegundos();
					for (i=0;i<10000;i++) {
						sumaactual(v, n);
					}
					t2 = microsegundos();
					t = (t2 - t1)/i;
				}
				free(v);
				cotas(&subestimada, &ajustada, &sobreestimada,actual,n);
				printf("%s | %c%6d |%10.2f |   %9.6f |   %9.6f |   %9.6f |\n"," ",((promedio == 1)? '*':' '),n,t,t/subestimada,t/ajustada,t/sobreestimada);
		/* divide t entre las funciones obtenidas mediante el void cotas */	
		}
			printf("\n");
	}

}

int main (void) {

	printf("\n EJERCICIO 1: Implementamos los algorimos.\n");
	ejerciciodos();
	printf("\n EJERCICIO 3: Medimos los tiempos de ejecucion de los algoritmos, calculando las tablas con sus correspondientes cotas.\n");
	ejerciciotres(1,sumaSubMax1);
	ejerciciotres(2,sumaSubMax2);

	return 0;
}



