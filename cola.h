#ifndef COLA_H
#define COLA_H

typedef struct Nodo_Ligado 
{   
    void* elemento;
 	struct Nodo_Ligado *siguiente;
} Nodo_Ligado;

typedef struct Cola
{
    Nodo_Ligado* primero;
    Nodo_Ligado* ultimo;
} Cola;

// Métodos

/* =========== Constructores ============= */
Nodo_Ligado* crea_nodo_simple(void* elem);

Nodo_Ligado* crea_nodo_siguiente(void* elem, Nodo_Ligado* sig); // A consideración

Cola* crea_cola(Nodo_Ligado* cabeza);
/*
 * Método que verifica si una cola es vacía
 * param: cola - Una cola con apuntador a vacío. 
 * return: valores booleanos en representación binaria.
 */
int es_vacia(Cola* cola);

/**
 * Método que realiza un incersión en la cola. 
 * param: cola - La estructura.
 * param: elem - El elemento a insertar.
 */
void* queue(Cola* cola, void* elem);

/**
 * Método que remueve un elemento de la cola.
 * param: cola - la EDD a utilizar.
 */
void* dequeue(Cola* cola);

#endif