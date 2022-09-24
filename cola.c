#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
// Métodos

/* =========== Constructores ============= */
Nodo_Ligado* crea_nodo_simple(void* elem){
    Nodo_Ligado* nodo= malloc(sizeof(Nodo_Ligado));
    nodo->elemento = elem;
    nodo->siguiente = NULL;
	return nodo;
}

Nodo_Ligado* crea_nodo_siguiente(void* elem, Nodo_Ligado* sig){
    Nodo_Ligado* nodo = crea_nodo_simple(elem);
    nodo->siguiente = sig;
	return nodo;
} // A consideración

Cola* crea_cola(Nodo_Ligado* cabeza){
    Cola* cola=malloc(sizeof(Cola));
    cola->primero = cabeza;
    cola->ultimo = cabeza;
    return cola;
}
/*
 * Método que verifica si una cola es vacía
 * param: cola - Una cola con apuntador a vacío. 
 * return: valores booleanos en representación binaria.
 */
int cola_es_vacia(Cola* cola){
    return cola->primero==NULL;
}

/**
 * Método que realiza un incersión en la cola. 
 * param: cola - La estructura.
 * param: elem - El elemento a insertar.
 */
void queue(Cola* cola, void* elem){
    Nodo_Ligado* nuevo= crea_nodo_simple(elem);
	if (cola_es_vacia(cola)){
		cola->primero=nuevo;
        cola->ultimo = nuevo;
	}
	else{
        cola->ultimo->siguiente= nuevo;
        cola->ultimo = nuevo;
	}
    
}

/**
 * Método que remueve un elemento de la cola.
 * param: cola - la EDD a utilizar.
 */
void* dequeue(Cola* cola){
    if (!cola_es_vacia(cola)){
        void* dato = cola->primero->elemento;
        Nodo_Ligado* nodo_aux= cola->primero;
        cola->primero=nodo_aux->siguiente;
	    free(nodo_aux);
	    return dato;	
    }else{
        return NULL;
    }
}