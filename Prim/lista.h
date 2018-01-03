/*Le llamaban lista, pero era una cola*/
typedef struct {
	int x, y, peso;
} arista;

typedef arista tipo_elemento;

struct nodo {
	tipo_elemento elemento;
	struct nodo* siguiente;
} nodo;

typedef struct nodo* pnodo;

typedef struct {
	pnodo cabeza;
	pnodo ultimo;
} lista;



void crear_lista(lista *l);
int lista_vacia(lista);
tipo_elemento eliminar(lista *l);
void insertar(tipo_elemento x, lista *l);
void vaciar_lista (lista *l);
/* ERRORES: eliminar un elemento que no esta en la lista */


