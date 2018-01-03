#include <limits.h>
#include <stdio.h>
#include "lista.h"
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>


typedef int ** matriz;
typedef int * vector;

   /*    FUNCIONES AUXILIARES   */

double microsegundos() {
	struct timeval t;
	
	if (gettimeofday(&t, NULL) < 0 )
		return 0.0;
	return (t.tv_usec + t.tv_sec * 1000000.0);
}

void inicializar_semilla() {
	srand(time(NULL));
}


arista crearArista(x,y,p) {
   static arista a;
   a.x = x;
   a.y = y;
   a.peso = p;
   return a;
}


lista prim(matriz m, int n) {
	int min, i, j, k=0, contador = 0;
	arista a;
	static lista l;
	vector masProximo = (vector) malloc(n*sizeof(int));
	vector distanciaMinima = (vector) malloc(n*sizeof(int));
	
	crear_lista(&l);
	distanciaMinima[0] = -1;
	for(i = 1; i < n; i++) {
		masProximo[i] = 0;
		distanciaMinima[i] = m[i][0];
	}
   do {
      min = INT_MAX;
      for (j= 1; j < n ; j++) 
         if ((0 <= distanciaMinima[j]) && (distanciaMinima[j] < min)) {
            min = distanciaMinima[j];
            k= j;     
         }
      a = crearArista (masProximo[k], k, distanciaMinima[k]);
      insertar(a,&l);
      distanciaMinima[k] = -1;
      for (j=1;j<n;j++)
         if (m[j][k]<distanciaMinima[j]){
            distanciaMinima[j] = m[j][k];
            masProximo[j] = k;
         }
      contador++;
   } while (contador < n-1);    
	free(masProximo);
	free(distanciaMinima);
	return l;
}

      /*    FUNCIONES AUXILIARES SOBRE MATRICES    */

matriz crearMatriz(int n) {
   int i;
   matriz aux;
   if ((aux = (int **) malloc(n*sizeof(int *))) == NULL)
      return NULL;
   for (i=0; i<n; i++)
      if ((aux[i] = (int *) malloc(n*sizeof(int))) == NULL)
         return NULL;
   return aux;
}

void inicializarMatriz(matriz m, int n) {

/* Crea un grafo completo no dirigido con pesos aleatorios entre 1 y n */
int i, j;
   for (i=0; i<n; i++)
      for (j=i+1; j<n; j++)
         m[i][j] = (rand() % n) + 1;
      for (i=0; i<n; i++)
         for (j=0; j<=i; j++)
            if (i==j)
               m[i][j] = 0;
            else
               m[i][j] = m[j][i];
}



void liberarMatriz(matriz m, int n) {
   int i;
   for (i=0; i<n; i++)
      free(m[i]);
   free(m);
}


void matrizEjemplos(matriz m, int n, vector v) {
   int i,k=0,j;   
   for (i= 0; i< n; i++)
      for(j=i;j<n;j++)
          if (j==i) 
            m[i][j] = 0;
          else {
            m[i][j] = v[k];
            m[j][i] = v[k];
            k++;
          }
}

void inicializarv1(vector v) {
   v[0] = 1;      
   v[1] = 8;
   v[2] = 4;
   v[3] = 7;
   v[4] = 2;
   v[5] = 6;
   v[6] = 5;
   v[7] = 9;
   v[8] = 5;
   v[9] = 3;
}

void inicializarv2(vector v) {
   v[0] = 1;      
   v[1] = 4;
   v[2] = 7;
   v[3] = 2;
   v[4] = 8;
   v[5] = 3;
}

void inicializarv3(vector v) {
   v[0] = 7;      
   v[1] = INT_MAX;
   v[2] = 5;
   v[3] = INT_MAX;
   v[4] = INT_MAX;
   v[5] = INT_MAX;
   v[6] = 8;      
   v[7] = 9;
   v[8] = 7;
   v[9] = INT_MAX;
   v[10] = INT_MAX;
   v[11] = INT_MAX;
   v[12] = 5;      
   v[13] = INT_MAX;
   v[14] = INT_MAX;
   v[15] = 15;
   v[16] = 6;
   v[17] = INT_MAX;
   v[18] = 8;      
   v[19] = 9;
   v[20] = 11;
}

void imprimirMatriz(matriz m, int n) {
   int i,j;
   for (i=0; i<n; i++){
      for (j=0; j<n; j++)
         printf("%d ",m[i][j]);
      printf("\n");
   }
}



void imprimirArista(vector v, int n) {
   lista l;
   arista aux;
   int pesoTotal= 0;
   matriz m;
   
   m = crearMatriz(n);
   inicializarMatriz(m,n);   
   matrizEjemplos(m,n,v);
   imprimirMatriz(m,n);

   l = prim(m,n);
   while (!lista_vacia(l)) {
      aux = eliminar(&l);
      pesoTotal += aux.peso;
      printf("(%d,%d) ", aux.x, aux.y);
   }
   printf("\nPeso: %d\n",pesoTotal);
   vaciar_lista(&l);

}



void test () {
   
   vector v1 = malloc(10*sizeof(int));
   vector v2 = malloc(6*sizeof(int));
   vector v3 = malloc(21*sizeof(int));
   
   inicializarv1(v1);
   inicializarv2(v2);
   inicializarv3(v3);

   imprimirArista(v1,5);
   imprimirArista(v2,4);
   imprimirArista(v3,7);

   free(v1);
   free(v2);
   free(v3);

}


/*Procedimiento cotas*/
/* devuelve las funciones subestimada, ajustada y sobreestimada */
void cotas (double *subestimada, double *ajustada, double *sobreestimada,int n) {

		*subestimada = pow(n,1.93);
		*ajustada = pow(n,2.065);
		*sobreestimada = pow(n,2.5);
	}



void tiemposCotas () {

	int n,i, repetir;
	double t1, t2, t;
	int *v;
	int promedio;
	double subestimada, ajustada,sobreestimada;
   matriz m;


	printf ("\n                        | subestimada |  ajustada   |sobreestimada|");
	printf("\n  |    n    |    t(n)   |  t(n)/h(n)  |  t(n)/g(n)  |  t(n)/f(n)  |\n ");
	printf (" |---------|-----------|-------------|-------------|-------------|\n");
			
	for (repetir = 1; repetir <=3; repetir++) {
		for (n = 128; n <= 9182 ; n*=2) {
         m = crearMatriz(n);
         inicializarMatriz(m,n);
			t1 = microsegundos();
         prim(m,n);
			t2 = microsegundos();
			t = t2-t1;
			promedio = 0;
			if (t < 500) {
				promedio = 1;
				t1 = microsegundos();
				for (i=0;i<10000;i++) {
               prim(m,n);
				}
				t2 = microsegundos();
				t = (t2 - t1)/i;
			}
      	cotas(&subestimada, &ajustada, &sobreestimada,n);
			printf("%s | %c%6d |%10.2f |   %9.6f |   %9.6f |   %9.6f |\n"," ",((promedio == 1)? '*':' '),n,t,t/subestimada,t/ajustada,t/sobreestimada);
		/* divide t entre las funciones obtenidas mediante el void cotas */
      liberarMatriz(m,n);	
		}
		printf("\n");
	}
	
}



int main (void) {
	//test();
   tiemposCotas();   
   return 0;
}



