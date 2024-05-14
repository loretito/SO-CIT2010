/*
    Ejemplo de un grafo aciclico dirigido en C
    La conexión de cada nodo tiene un costo asociado
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    int cost;
    struct Node *next;
};

struct List {
    struct Node *head;
};

struct Graph {
    struct List *arr;
};

struct Node *newNode(int dest, int cost) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->dest = dest;
    node->cost = cost;
    node->next = NULL;
    return node;
}

struct Graph *createGraph(int V) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->arr = (struct List *)malloc(V * sizeof(struct List));
    for (int i = 0; i < V; ++i)
        graph->arr[i].head = NULL;
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest, int cost) {
    struct Node *node = newNode(dest, cost);
    node->next = graph->arr[src].head;
    graph->arr[src].head = node;
}

void printGraph(struct Graph *graph, int V) {
    for (int i = 0; i < V; ++i) {
        struct Node *tmp = graph->arr[i].head;
        printf("\nNodos adyacentes al nodo %d\n", i);
        while (tmp) {
            printf(" -> %d (costo: %d) \n", tmp->dest, tmp->cost);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

int main() {
    int V = 0;

    while (1) {
        printf("Ingresa la cantidad de nodos: ");
        scanf("%d", &V);

        if (V < 2) {
            printf("La cantidad de nodos debe ser al menos 2.\n");
        }
        else {
            break;
        }
    }

    struct Graph *graph = createGraph(V);

    // Esto podria ser aleatorio (para la tarea)
    for (int i = 0; i < V - 1; ++i) {
        addEdge(graph, i, i + 1, (i + 1) * 2); 
        if (i + 2 < V) {
            addEdge(graph, i, i + 2, (i + 2) * 3); 
        }
    }

    printGraph(graph, V);

    return 0;
}
