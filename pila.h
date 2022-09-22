#ifndef PILA_H
#define PILA_H
#include <stdio.h>
#include <stdlib.h>

typedef int Item; //Para cualquier tipo de dato

typedef struct Pila
{
    // TODO: Definir los elementos necesarios para una pila
    /*
     * Recuerda que esta estructura requiere de una implementación
       basada en arreglos. Se requiere de un tope, una capacidad y
       por supuesto un arreglo.
     */
    Item *dato;
    int tope;
    int tam;
} Pila;

// Métodos a considerar:
Pila* crea_pila(int capacidad){
  Pila *pila = malloc(sizeof(Pila));
  Item *elem;
  elem = (Item *)malloc(sizeof(Item)*capacidad);
  if(elem == NULL){
    printf("\nError al reservar memoria para la pila\n");
    exit(1);
  }
  pila->dato = elem;
  pila->tope = (-1);
  pila->tam = capacidad;
  return pila;
}

/* Método que indica si una pila está llena.
 * param: pila - el apuntador a una pila
 * return: representación numérica de booleanos.
 */
int es_llena(Pila* pila){
  return (pila->tope==(pila->tam-1));
}

/* Método que indica si una pila está vacía.
 * param: pila - el apuntador a una pila
 * return: representación numérica de booleanos.
 */
int es_vacia(Pila* pila){
  return (pila->tope==(-1));
}

/* Método que expulsa el primer elemento de la pila.
 * param: pila - el apuntador a una pila.
 */
void pop(Pila* pila){
  if(es_vacia(pila)){
    puts("La pila esta vacia");
  }
  //Item temp=pila->dato[pila->tope]; //Dejo esta linea por si se cambia a que regrese el dato que estaba en la cima.
  pila->tope--;
  //return tem;
}


/* Método que realiza la incersión de un elemento a la pila.
 * param: pila - el apuntador a una pila
 * param: elem - elemento a ser insertado
 */
void push(Pila* pila, Item elem){
  if(es_llena(pila)){
    puts("La pila esta llena");
  }
  pila->tope++;
  pila->dato[pila->tope]=elem;
}

/* Metodo que limpia la pila
 * param: pila - el apuntador a una pila
 */
void limpia_pila(Pila* pila){
  pila->tope=(-1);
}

/* Metodo que elimna la pila
 * param: pila - el apuntador a una pila
 */
void elimina_pila(Pila* pila){
  free(pila->dato);
  pila->dato=NULL;
  pila->tam=0;
  pila->tope=(-1); 
}
#endif
