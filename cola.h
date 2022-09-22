#ifndef COLA_H
#define COLA_H

typedef struct Nodo_Ligado 
{
    // ¿Qué debe contener un nodo ligado
} Nodo_Ligado;

typedef struct Cola
{
    // Recuerda: Implementación basada en Listas ligadas
} Cola;

// Métodos

/* =========== Constructores ============= */
Nodo_Ligado* crea_nodo_simple(<tipo> elem);

Nodo_Ligado* crea_nodo_siguiente(<tipo> elem, Nodo_Ligado* sig); // A consideración

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
void queue(Cola* cola, <tipo> elem);

/**
 * Método que remueve un elemento de la cola.
 * param: cola - la EDD a utilizar.
 */
void dequeue(Cola* cola);

#endif