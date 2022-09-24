#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "cola.c"

int balanced_parenthesis(char* expr);
void bfs(int** graph);

int main()
{   
    //PRUEBA DE FUNCIONAMIENTO DE COLA
    int elem1 = 1;
    int elem2 = 2;
    int elem3 = 3;
    void* p1 = &elem1;
    void* p2 = &elem2;
    void* p3 = &elem3;

    Cola* cola = crea_cola(crea_nodo_simple(p1));
    queue(cola, p2);
    queue(cola, p3);
    
    while (!cola_es_vacia(cola)){
        printf("%d\n",*(int*)dequeue(cola));
    }
    //FIN DE PRUEBA DE FUNCIONAMIENTO DE COLA
    
    
    // Creación de casos de ejemplo
    // Prueba con dichos casos
    return 0;
}

/**
 * Método que resuelve el problema de los paréntesis balanceados
 * Para demostrar el uso de la pila
 * @param expr Una expresión de paréntesis a realizar
 * @return 0 si no hay balance, 1 e.o.c.
 */
int balanced_parernthesis(char expr)
{
    // TODO: Impl
    return -1;
}

/**
 * Realiza un recorrido BFS sobre una gráfica
 * Demostrar el uso de una cola.
 * @param graph - Una gráfica representada en una matriz de adyacencia
 */
void bfs(int** graph)
{
    // TODO: Impl
}

