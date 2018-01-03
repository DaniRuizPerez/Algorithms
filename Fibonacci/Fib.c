/* Daniel Ruiz Pérez (d.ruiz.perez) 
	Ismael Barbeito Vázquez (i.barbeito)
	Algoritmos, curso 2012/2013
	1/10/2012

Especificaciones del computador (alba03181):
	- Procesador:Intel(R) Core(TM) i5 CPU       M 450  @ 2.40GHz
	- Caché L2: 3072KB
	- Mem. principal: 4GB
	- Kernel:  3.2.0-30-generic*/

#include <stdio.h>
#include <sys/time.h>
#include <math.h>

//Fib 1
int fib1 (int n) {
	if (n < 2) {
		return n;
	} 
	else {
		return fib1(n-1) + fib1(n-2);
	}
}

//Fib 2
int fib2 (int n) {
	int i = 1, j = 0, k;
	n = n;
	for (k = 1; k <= n; k++) {
		j = i + j;
		i = j - i;
	}
	return j;
}

//Fib 3
int fib3 (int n) {
	int i = 1, j = 0, k = 0, h = 1, t = 0;
	
	while (n > 0) {
		if (n % 2 != 0) {
			t = j*h;
			j = i*h + j*k + t;
			i = i*k + t;
		}
		t = h*h;
		h = 2*k*h + t;
		k = k*k+t;
		n = n/2;
	}
	return j;
}

/*Módulo hora*/
/* obtiene la hora actual en microsegundos */
double microsegundos() {
struct timeval t;
if (gettimeofday(&t, NULL) < 0 )
return 0.0;
return (t.tv_usec + t.tv_sec * 1000000.0);
}

/*Procedimiento cotas*/
/* Este procedimiento recibe el número de fib que vamos a ejecutar y devuelve las funciones subestimada, ajustada y sobreestimada correstpondientes a ese fib.*/
void cotas (double *subestimada, double *ajustada, double *sobreestimada,int actual, int n) {

	if (actual == 1) {
		*subestimada = pow(1.1, n);
		*ajustada = pow ((1+sqrt(5))/2,n);
		*sobreestimada = pow(2.,n);
	}
	if (actual == 2) {
		*subestimada = pow(n, 0.8);
		*ajustada = n;
		*sobreestimada = n*log(n);
	}
	if (actual == 3) {
		*subestimada = sqrt(log(n));
		*ajustada = log(n);
		*sobreestimada = pow(n,0.5);
	}
}


/*Ejercicio 2*/
void ejercicio2() {

	/*Variables*/
	int n;
	/*Cuerpo*/
	printf ("\n%s| n |fib1|fib2|fib3|\n", "   ");
	printf ("   |---|----|----|----|\n");
	for (n = 0; n <= 14; n++) {
		printf ("%s|%3d| %3d| %3d| %3d|\n","   ",n, fib1(n), fib2(n), fib3(n));
	} 
}

/*Ejercicio 3*/
void ejercicio3 (int (*fibactual) (int), int actual) {
/* El ejercicio 3 es un procedicmiento que recibe como parametro de entrada las funciones fib1, fib2 o fib3 y actual, que es el numero correspondiente (1,2 o 3), para las iteracciones del bucle.*/

	//Variables
	int n,i,inicio = 1000, limite = 10000000, escalar = 10, repetir;
	double t1, t2, t;
	
	/* Este procedimiento inicializa inicio limite y escalar a estos valores porque son los que se van a utilizar en fib2 y fib3 (son el número de interacciones que hace el bucle, que va de 1000 a 10000000, multiplicando cada vez opr 10)
	Si estamos haciendo fib1 se asignan los valores correspondientes (de 2 a 32) .*/

	//Cuerpo
	printf ("\nfib%d\n\n%s|    n    |     t(n)      |\n",actual, "   ");
	printf ("   |---------|---------------|\n");

	if (actual == 1) {
		inicio = 2;
		limite = 32;
		escalar = 2;
	}
	for (repetir = 1; repetir <=3; repetir++) {
	/* Este bucle es para que se impriman tres veces las tablas, por si hay algúne error. */
		for (n = inicio; n <= limite; n=escalar*n) {
			t1 = microsegundos();
			fibactual(n);
			t2 = microsegundos();
			t = t2-t1;
			if (t < 500) {
				t1 = microsegundos();
				for (i=0;i<10000;i++) {
					fibactual(n);
				}
				t2 = microsegundos();
				t = (t2 - t1)/i;
	/*Mide el tiempo antes y despues de ejecutar el algoritmo, y si es menor q 500 microsegundos hacemos 10000 iteracciones y medimos el tiempo, para minimizar los posibles errores.*/
			}
			printf("%s|%8d | %12.6f  |\n","   ",n,t);
		}
		printf("\n");
	}
}


/*Ejercicio 4*/
void ejercicio4 (int (*fibactual) (int), int actual){
/* Este void se basa en lo mismo que ejercicio4, los comentarios del ejercicio anterior se aplican a este */

	//Variables
	int n,i,inicio = 1000, limite = 10000000, escalar = 10, repetir;
	double t1, t2, t;
	double subestimada, ajustada,sobreestimada;

	//Cuerpo
	printf ("\nfib%d\n                          |  subestimada   |    ajustada    |  sobreestimada |\n   |    n   |     t(n)    |   t(n)/h(n)    |    t(n)/g(n)   |    t(n)/f(n)   |\n", actual, "     ");
	printf ("   |--------|-------------|----------------|----------------|----------------|\n");

	if (actual == 1) {
		inicio = 2;
		limite = 32;
		escalar = 2;
	}
	for (repetir = 1; repetir <=3; repetir++) {
		for (n = inicio; n <= limite; n=escalar*n) {
			t1 = microsegundos();
			fibactual(n);
			t2 = microsegundos();
			t = t2-t1;
			if (t < 500) {
				t1 = microsegundos();
				for (i=0;i<10000;i++) {
					fibactual(n);
				}
				t2 = microsegundos();
				t = (t2 - t1)/i;
			}
			cotas(&subestimada, &ajustada, &sobreestimada,actual,n);
			printf("%s|%8d|%13.7f| %13.7f  | %13.7f  | %13.7f  |\n","   ",n,t,t/subestimada,t/ajustada,t/sobreestimada);
	/* divide t entre las funciones obtenidas mediante el void cotas */	
		}
		printf("\n");
	}
	
}

int main() {
	printf ("\nALGORITMOS 2012/2013\nPRÁCTICA 1\nIsmael Barbeito Vázquez: i.barbeito\nDaniel Ruiz Pérez: d.ruiz.perez\n\n");
	printf ("TESTEO DE LOS ALGORITMOS\n");
	ejercicio2();
	printf ("\nTIEMPOS DE EJECUCION PARA CADA ALGORITMO:\n");
	ejercicio3(fib1,1);
	ejercicio3(fib2,2);
	ejercicio3(fib3,3);
	printf ("\nESTUDIO DE LAS COTAS PARA CADA ALGORITMO\n");
	printf("\n *subestimada = pow(1.1, n) \n *ajustada = pow ((1+sqrt(5))/2,n)\n *sobreestimada = pow(2.,n)\n");
	ejercicio4(fib1,1);
	printf("\n *subestimada = pow(n, 0.8) \n *ajustada = n\n *sobreestimada = n*log(n)\n");
	ejercicio4(fib2,2);
	printf("\n *subestimada = sqrt(log(n)) \n *ajustada = log(n)\n *sobreestimada = pow(n,0.5)\n");
	ejercicio4(fib3,3);
	return 0;
}
