#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "cola.h"
#include "cola.c"

int balanced_parenthesis(char* expr);
void bfs(int** digraph, int vertices);

int main()
{
    // Creación de casos de ejemplo
    int **matrix;
    int row = 7, col = 7;
    matrix = (int**)malloc(row*sizeof(int*));
    for (int i=0; i < row; i++)
    matrix[i]= (int*)malloc(col*sizeof(int));
    matrix[0][1] = 1;
    matrix[0][3] = 1;
    matrix[1][2] = 1;
    matrix[1][4] = 1;
    matrix[2][5] = 1;
    matrix[3][2] = 1;
    matrix[4][3] = 1;
    matrix[5][6] = 1;
    matrix[6][3] = 1;
    // Prueba con dichos casos
    bfs(matrix, 7);

    char formula1[] = "1/[(3)*(5)+7]";
    char formula2[] = "5*(1)+(3)}";

    if (balanced_parenthesis(formula1)){
        printf("La formula %s Esta balanceada!\n",formula1);
    }else{
         printf("La formula %s No esta balanceada!\n",formula1);
    }
    if (balanced_parenthesis(formula2)){
        printf("La formula %s Esta balanceada!\n",formula2);
    }else{
         printf("La formula %s No esta balanceada!\n",formula2);
    }
    

    return 0;
}

/**
 * Método que resuelve el problema de los paréntesis balanceados
 * Para demostrar el uso de la pila
 * @param expr Una expresión de paréntesis a realizar
 * @return 0 si no hay balance, 1 e.o.c.
 */
int balanced_parenthesis(char* expr){
    //printf("%s",expr);
    Pila* pila = crea_pila(strlen(expr));
    int f;
    for (f=0;f<strlen(expr);f++){
        if (expr[f]=='(' || expr[f]=='[' || expr[f]=='{'){
            push(pila,  expr[f]);
        }
        else{
            if (expr[f]==')'){
                if (pop(pila)!='('){
                    return 0;
                }
            }
            else{
                if (expr[f]==']'){
                    if (pop(pila)!='['){
                        return 0;
                    }
                }
                else{
                    if (expr[f]=='}'){
                        if (pop(pila)!='{'){
                            return 0;
                        }
                    }
                }
            }
        }
    }
    if (es_vacia(pila)){
        return 1;
    }
    else{
        return 0;
    }
}

/**
 * Realiza un recorrido BFS sobre una gráfica
 * Demostrar el uso de una cola.
 * @param digraph - Una gráfica dirigida representada en una matriz de adyacencia, una gráfica simple puede verse
 * como un caso particular en el que graph[i][j] = graph[j][i] para toda i,j.
 * @param vertices - El número de vértices de la gráfica, notesé que graph
 * tiene que ser de tamaño vertices * vertices.
 */
void bfs(int** digraph, int vertices)
{   
    printf("Recorrido BFS: ");
    //Create visited array
    int visited[vertices];
    for(int i = 0; i < vertices; i++)
    visited[i] = 0;
    //Create queque
    //Put first node in queue
    void* headElemptr = malloc(sizeof(int));
    *((int*)headElemptr) = 0;
    Nodo_Ligado* head = crea_nodo_simple(headElemptr);
    Cola* Q = crea_cola(head);
    
    void* currentIndex = 0;
    int current = -1;
    void* toAddptr;
    //Loop until queue's empty:
    while (!cola_es_vacia(Q))
    {
        //Dequeue node
        currentIndex = dequeue(Q);
        current = *((int*)currentIndex);
        //If visited, throw away.
        if (!visited[current]){
        //If unvisited:
            //Mark as visited
            visited[current] = 1;
            //Put all neighbors in queue
            for (int j = 0; j < vertices; j++){
                if (digraph[current][j]){
                    toAddptr =  malloc(sizeof(int));
                    *((int*)toAddptr) = j;
                    queue(Q, toAddptr);
                }
            }
            //Print that it has been visited  
            printf("%d ", current);
        }
    }        
    printf("\n");
}