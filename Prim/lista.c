#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void crear_lista(lista *l){
	l->cabeza = NULL;
	l->ultimo = NULL;
}

int lista_vacia(lista l){
	return (l.cabeza == NULL);
}


void insertar(tipo_elemento x, lista *l) {
   pnodo temp = (pnodo) malloc (sizeof (nodo));
	if (temp == NULL)
		exit (EXIT_FAILURE);
	temp -> elemento = x;
	temp -> siguiente = NULL;
	if (l -> cabeza == NULL) { 	
		l-> cabeza = temp;
		l-> ultimo = temp;
	}
	else {
		l->ultimo->siguiente = temp;
		l->ultimo = temp;
	}

}

tipo_elemento eliminar(lista *l) {
	if (lista_vacia (*l)) {
		exit (EXIT_FAILURE);
	}
   pnodo borrar = l->cabeza;
	tipo_elemento temp = l->cabeza->elemento;
	l->cabeza = l->cabeza -> siguiente;
   free(borrar);
	return temp;
}

void vaciar_lista (lista *l) {
	pnodo temp;
	while (!lista_vacia(*l)) {
		temp = l-> cabeza;
		l->cabeza = l->cabeza->siguiente;
		free(temp);
	}
	l->ultimo = NULL;
}
