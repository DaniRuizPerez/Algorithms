/* Daniel Ruiz Pérez (d.ruiz.perez) 
	Ismael Barbeito Vázquez (i.barbeito)
	Algoritmos, curso 2012/2013
	1/10/2012*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <math.h>

int UMBRAL = 1;

void inicializar_semilla() {
	srand(time(NULL));
}

void aleatorio(int v [], int n) {

/* Le restamos n para que se generen numeros aleatorios entre -n y n, así con vectores muy grandes no va a haber casi números repetidos*/
	int i;
	for (i=0; i < n; i++)
		v[i] = (rand() % 201) - n;
}

void ascendente(int v [], int n) {
	int i;
	for (i=0; i < n; i++)
		v[i] = i;
}

void descendente(int v [], int n) {
	int i;
	for (i=0; i < n; i++)
		v[i] = n-1-i;
}


/*Procedimiento cotas*/
/* Este procedimiento recibe el tipo de ordenacion que vamos a ejecutar y devuelve las funciones subestimada, ajustada y sobreestimada correstpondientes a esa ordenacion.*/
void cotas (double *subestimada, double *ajustada, double *sobreestimada,int actual, int n) {

	if (actual == 0) {//Caso medio inserción
		*subestimada = pow(n,1.7);
		*ajustada = pow(n,2);
		*sobreestimada = pow(n,2.2);
	}
	if (actual == 1) { //Mejor caso inserción
		*subestimada = pow(n,0.7);
		*ajustada = n;
		*sobreestimada = pow(n,1.2);
	}
	if (actual == 2) {//Peor caso inserción
		*subestimada = pow(n,1.6);
		*ajustada = pow(n,2);
		*sobreestimada = pow(n,2.3);
	}
	if (actual > 2) { //Las cotas subestimada y sobreestimada son la misma
							//para cada caso de quicksort
		*subestimada = n;
		*sobreestimada = pow(n,1.5);
	} 
	if (actual == 3) //Quicksort UMBRAL 1 aleatorio
		*ajustada = log (n) * pow(n,0.935);
		
	if (actual == 4) //Quicksort UMBRAL 1 ascendente	
		*ajustada = log (n) * pow(n,0.938);
		
	if (actual == 5) //Quicksort UMBRAL 1 descendente	
		*ajustada = log (n) * pow(n,0.935);

	if (actual == 6) //Quicksort UMBRAL 10 aleatorio
		*ajustada = log (n) * pow(n,0.94);
		
	if (actual == 7) //Quicksort UMBRAL 10 ascendente	
		*ajustada = log (n) * pow(n,0.9835);
		
	if (actual == 8) //Quicksort UMBRAL 10 descendente	
		*ajustada = log (n) * pow(n,0.972);
		
	if (actual == 9) //Quicksort UMBRAL 100 aleatorio
		*ajustada = log (n) * pow(n,0.955);
		
	if (actual == 10) //Quicksort UMBRAL 100 ascendente	
		*ajustada = log (n)* pow(n,1.044);
		
	if (actual == 11) //Quicksort UMBRAL 100 descendente	
		*ajustada = log (n)* pow(n,1.02);
	
	
	
}

void ord_ins (int v [], int n) {
	int i,x,j;
	
	for (i=1; i < n; i++) {
		x = v[i];
		j = i - 1;
		while (j>= 0 && v[j] > x) {
			v[j+1] = v[j];
			j = j-1;
		}
		v[j+1] = x;
	}
}

void intercambiar (int* i, int* j) {
	int aux = *i;
	*i = *j;
	*j= aux;
}


void mediana3 (int v [], int i, int j) {
	int k = (i+j) / 2;	

	if (v[k] > v [j]) 
		intercambiar(&v[k], &v[j]);
	if (v[k] > v[i]) 
		intercambiar (&v[k], &v[i]);
	if (v[i] > v[j]) 
		intercambiar (&v[i], &v[j]);
}
 
void ordenarAux (int v [], int izq, int der) {
	int pivote;
	int i, j;
	if ((izq + UMBRAL) <= der) {
		mediana3 (v, izq, der);
		pivote = v[izq];
		i = izq;
	 	j = der;
		do {
			do
				i++;
       	    while (v[i] < pivote);
			do
				j--;
			while (v[j] > pivote);
			intercambiar (&v[i], &v[j]);
		} while (j > i);
        intercambiar (&v[i], &v[j]);
	    intercambiar (&v[izq], &v[j]);		
		ordenarAux(v,izq,j-1);
		ordenarAux(v,j+1,der);		
	}
}

void ordenacionRapida (int v[], int n) {
	ordenarAux(v,0,n-1);
	if (UMBRAL > 1) 
		ord_ins (v, n);
}

void imprimirVector (int* v, int n) {
	int i;
	printf("\n ");
	for (i = 0; i < n; i++) {
		printf ("%d ",v[i]);
	}
	printf("\n ");
}

void esOrdenado (int*v, int n) {
	int i = 0;
	int j = 1;
	
	while (i < n-1) {
		if (v[i] > v[i+1]) {
			j = 0;
			break;
		}
		i++;
	}
	printf ("¿Ordenado?: %d\n", j);
}

void casosTest (char* nominic, void (*iniactual) (int*,int), int*v,void (*ordactual) (int*,int)) {
	iniactual (v, 10);
	printf ("\n%s:", nominic);
	imprimirVector(v, 10);
	esOrdenado (v,10);
	ordactual (v,10);
	imprimirVector(v, 10);
	esOrdenado (v,10);
}

double microsegundos() {
	struct timeval t;
	
	if (gettimeofday(&t, NULL) < 0 )
		return 0.0;
	return (t.tv_usec + t.tv_sec * 1000000.0);
}

void test (void (*ordactual) (int*,int)) {
	int v[10];
	
	casosTest ("Aleatorio",aleatorio ,v,ordactual);
	casosTest ("Ascendente",ascendente ,v,ordactual);
	casosTest ("Descendente",descendente ,v,ordactual);

}


void tiempos ( void (*ordactual) (int*,int)) {

	int n,i,inicio = 256, limite = 8192, escalar = 2, repetir;
	double t1, t2, t;
	int *v,j;
	int promedio;
	void (*iniactual) (int*,int);

	printf("\n  |    n    |  ALEATORIO | ASCENDENTE  | DESCENDENTE |\n ");
	printf (" |---------|------------|-------------|-------------|\n");
			
	for (repetir = 1; repetir <=3; repetir++) {
		for (n = inicio; n <= limite; n=escalar*n) {
			printf("%s | %7d |"," ",n);
			for (j = 0; j < 3; j++) {
				if (j == 0) {
					iniactual = aleatorio;
				}
				if (j == 1) {
					iniactual = ascendente;
				}
				if (j == 2) {
					iniactual = descendente;
				}
				v = malloc (n*sizeof(int));
				iniactual(v,n);
				t1 = microsegundos();
				ordactual(v,n);
				t2 = microsegundos();
				t = t2-t1;
				promedio = 0;
				if (t < 500) {
					promedio = 1;
					t1 = microsegundos();
					for (i=0;i<10000;i++) {
						iniactual(v,n);
						ordactual(v,n);
					}
					t2 = microsegundos();
					t = (t2 - t1)/i;
					t1 = microsegundos();
					for (i=0;i<10000;i++) {
						iniactual(v,n);
					}
					t2 = microsegundos();
					t = t-(t2 - t1)/i;
				}
			
			printf(" %9.2f%c | ",t,((promedio == 1)? '*':' '));
			free(v);
			}
			printf("\n");
		}
		printf("\n");
	}
	
}



void tiemposCotas (void (*iniactual) (int*,int), void (*ordactual) (int*,int), char* tipord, int actual) {

	int n,i,inicio = 8, limite = 2048, escalar = 2, repetir;
	double t1, t2, t;
	int *v;
	int promedio;
	double subestimada, ajustada,sobreestimada;

//insercion es la 0
	if (actual == 1) {
		inicio = 1024;
		limite = 65536;
	}
	if (actual >= 3) {
		inicio = 256;
		limite = 8192; 
      printf("UMBRAL %d ", UMBRAL);;
	}
    printf("actual = %d", actual);;

	printf("\n\n           %s", tipord);
	printf ("\n                        | subestimada |  ajustada   |sobreestimada|");
	printf("\n  |    n    |    t(n)   |  t(n)/h(n)  |  t(n)/g(n)  |  t(n)/f(n)  |\n ");
	printf (" |---------|-----------|-------------|-------------|-------------|\n");
			
	for (repetir = 1; repetir <=3; repetir++) {
		for (n = inicio; n <= limite; n=escalar*n) {
			v = malloc (n*sizeof(int));
			iniactual(v,n);
			t1 = microsegundos();
			ordactual(v,n);
			t2 = microsegundos();
			t = t2-t1;
			promedio = 0;
			if (t < 500) {
				promedio = 1;
				t1 = microsegundos();
				for (i=0;i<10000;i++) {
					iniactual(v,n);
					ordactual(v,n);
				}
				t2 = microsegundos();
				t = (t2 - t1)/i;
				t1 = microsegundos();
				for (i=0;i<10000;i++) {
					iniactual(v,n);
				}
				t2 = microsegundos();
				t = t-(t2 - t1)/i;
			}
			cotas(&subestimada, &ajustada, &sobreestimada,actual,n);
			printf("%s | %c%6d |%10.2f |   %9.6f |   %9.6f |   %9.6f |\n"," ",((promedio == 1)? '*':' '),n,t,t/subestimada,t/ajustada,t/sobreestimada);
		/* divide t entre las funciones obtenidas mediante el void cotas */	
			free(v);
		}
		printf("\n");
	}
	
}


int main (void) {
	int i;
	inicializar_semilla();
	test(ordenacionRapida);
	tiemposCotas(aleatorio,ord_ins,"Aleatorio",0);
	tiemposCotas(ascendente,ord_ins, "Ascendente",1);
	tiemposCotas(descendente,ord_ins,"Descendente",2);
	tiempos (ord_ins);
	for (i = 0; i < 3; i++) {
		UMBRAL = pow (10,i);
		printf("\n\n       UMBRAL = %d", UMBRAL);
		tiempos(ordenacionRapida);}
	for (i = 0; i < 3; i++) {
		UMBRAL = pow (10,i);
		tiemposCotas(aleatorio,ordenacionRapida ,"Aleatorio",3+(3*i));
		tiemposCotas(ascendente,ordenacionRapida ,"Ascendente",4+(3*i));
		tiemposCotas(descendente,ordenacionRapida ,"Descendente",5+(3*i));		
	}
	return 0;
}
