//===============================================================================================================
// Graph.c
// Implementation file for Graph ADT and Breadth-first search algorithm.
//
// Yona Edell
// CruzID: yedell
// CMPS 101
// PA4
// 02/18/2017
//===============================================================================================================

#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

#define WHITE 0
#define GRAY 1
#define BLACK 2

// Structs ------------------------------------------------------------------------------------------------------

typedef struct GraphObj {
    List *adj; // Adjacency list (each row contains neighbors of vertex)
    int *color; // ith element is the color of vertex i
    int *parent; // ith element is the parent of vertex i
    int *dist; // ith element is the distance from the most recent source to vertex i
    int order; // Number of vertices in graph
    int size; // Number of edges in graph
    int source; // Vertex that was most recently used as source in BFS()
} GraphObj;

// Constructors-Destructors -------------------------------------------------------------------------------------

Graph newGraph(int n) { // Returns reference to new empty Graph object w/ n vertices
    if(n <= 0) {
        printf("Graph error: calling \"newGraph()\" with invalid number of vertices--%d\n", n);
        exit(1);
    }

    Graph G;
    G = malloc(sizeof(GraphObj));
    G->adj = calloc(n+1, sizeof(List));
    G->color = calloc(n+1, sizeof(int));
    G->parent = calloc(n+1, sizeof(int));
    G->dist = calloc(n+1, sizeof(int));
    G->order = n;
    G->size = 0;
    G->source = NIL;

    for(int i = 1; i < n+1; i++) { // initializing arrays
        G->adj[i] = newList();
        G->color[i] = WHITE;
        G->parent[i] = NIL;
        G->dist[i] = INF;
    }

    return G;
}

void freeGraph(Graph* pG) {
    if(pG != NULL && *pG != NULL) {
        for(int i = 1; i <= (*pG)->order; i++) { // Traverse through all vertices
            freeList(&(*pG)->adj[i]); // Free adjacency list at row i
        }
        free((*pG)->adj);
        free((*pG)->color);
        free((*pG)->parent);
        free((*pG)->dist);
        free(*pG);
        *pG = NULL;
    }
}

// Access Functions ---------------------------------------------------------------------------------------------

int getOrder(Graph G) { // Returns number of vertices in G
//    if(G == NULL) {
//        printf("Graph Error: calling \"getOrder()\" on NULL Graph reference\n");
//        exit(1);
//    }
    return G->order;
}

int getSize(Graph G) { // Returns number of edges in G
//    if(G == NULL) {
//        printf("Graph Error: calling \"getSize()\" on NULL Graph reference\n");
//        exit(1);
//    }
    return G->size;
}

int getSource(Graph G) { // Returns vertex most recently used as source in BFS()
//    if(G == NULL) {
//        printf("Graph Error: calling \"getSource()\" on NULL Graph reference\n");
//        exit(1);
//    }
    return G->source; // If BFS() has not been called, returns NIL
}

int getParent(Graph G, int u) { // Returns parent of vertex u in BFS tree
    if(G == NULL) {
        printf("Graph Error: calling \"getParent()\" on NULL Graph reference\n");
        exit(1);
    }
    if(u > getOrder(G) || u < 1) {
        printf("Graph Error: calling \"getParent()\" with invalid vertex u\n");
        exit(1);
    }
    return G->parent[u]; // If u has no parent or BFS() has not yet been called, returns NIL
}

int getDist(Graph G, int u) { // Returns the distance from the most recent BFS source to vertex u
    if(G == NULL) {
        printf("Graph Error: calling \"getDist()\" on NULL Graph reference\n");
        exit(1);
    }
    if(u > getOrder(G) || u < 1) {
        printf("Graph Error: calling \"getDist()\" with invalid vertex u\n");
        exit(1);
    }
    return G->dist[u]; // If u is not connected to source or BFS() has not yet been called, returns INF
}

void getPath(List L, Graph G, int v) { // Appends to the List L the vertices of a shortest path in G from source to v
    if(G == NULL) {
        printf("Graph Error: calling \"getPath()\" on NULL Graph reference\n");
        exit(1);
    }
    if(v > getOrder(G) || v < 1) {
        printf("Graph Error: calling \"getPath()\" with invalid vertex u\n");
        exit(1);
    }
    if(getSource(G) == NIL) {
        printf("Graph Error: calling \"getPath()\" before \"BFS()\"\n");
        exit(1);
    }

    if(getSource(G) == v) { // Appends u if it's the source/only vertex in the path
        append(L, v);
    }
    else if(getParent(G, v) == NIL) { // Appends NIL if no path in G from source to u exists
        append(L, NIL);
    }
    else {
        getPath(L, G, getParent(G, v));
        append(L, v);
    }
}

// Manipulation Procedures --------------------------------------------------------------------------------------

void makeNull(Graph G) { // Deletes all edges of G, restoring it to its original (no edge) state
    if(G != NULL) {
        for(int i = 1; i <= G->order; i++) {
            clear(G->adj[i]); // calls List clear() function
        }
        G->size = 0;
    }
}

void addEdge(Graph G, int u, int v) { // Inserts a new edge joining u to v
    // u is added to the adjacency List of v, and v to the adjacency List of u.
    // Pre: its two int arguments must lie in the range 1 to getOrder(G)

    addArc(G, u, v); // No need to check arguments, because addArc() already does that
    addArc(G, v, u);
    G->size--; // Decrement size because addArc() is called twice
               // and we only added one edge
}

void addArc(Graph G, int u, int v) { // Inserts a new directed edge from u to v
    // v is added to the adjacency List of u (but not u to the adjacency List of v)
    // Pre: its two int arguments must lie in the range 1 to getOrder(G)
    if(G == NULL) {
        printf("Graph Error: calling \"addArc()\" on NULL Graph reference\n");
        exit(1);
    }
    if(u < 1 || u > getOrder(G)) {
        printf("Graph Error: calling \"addArc()\" with invalid vertex u\n");
        exit(1);
    }
    if(v < 1 || v > getOrder(G)) {
        printf("Graph Error: calling \"addArc()\" with invalid vertex v\n");
        exit(1);
    }
    List A = G->adj[u];
    if(length(A) == 0) { // If List empty, append
        append(A, v);
        G->size++;
    }
    else { // If List non-empty
        moveFront(A);
        while(index(A) != -1) { // Traverse list
            if(v == get(A)) { // If vertex matches, do nothing
                return;
            }
            else if(v > get(A)) { // keeps list in ascending order
                moveNext(A);
            }
            else {                  // we passed our desired index,
                insertBefore(A, v); // so insertBefore() to keep in ascending order
                G->size++;
                return;
            }
        }
        append(A, v);
        G->size++;
    }
}

void BFS(Graph G, int s) { // runs the BFS algorithm on the Graph G with source s
    // sets the color, distance, parent, and source fields of G
    if(G == NULL) {
        printf("Graph Error: calling \"BFS()\" on NULL Graph reference\n");
        exit(1);
    }

    G->source = s;

    for(int i = 1; i <= G->order; i++) {
        G->color[i] = WHITE; // Resetting color[], parent[], and dist[]
        G->parent[i] = NIL;  // if BFS() has been called before
        G->dist[i] = INF;    //
    }

    G->dist[s] = 0;
    G->color[s] = GRAY;
    List queue = newList();
    append(queue, s);

    while(length(queue) != 0) { // BFS Queue Loop (starting with s)
        int temp = front(queue);
        deleteFront(queue);
        List adj = G->adj[temp]; // adj = list of adjacent vertices for s
        moveFront(adj); // move cursor to smallest number vertex

        while(index(adj) != -1) { // Traverse through list of temp's adjacent vertices
            if(G->color[get(adj)] == WHITE) { // If adjacent vertex undiscovered
                G->color[get(adj)] = GRAY; // Color gray (to indicate processing)
                G->parent[get(adj)] = temp; // Add temp as parent of current/cursor vertex
                G->dist[get(adj)] = G->dist[temp] +1; // Add distance of current/cursor vertex to temp
                append(queue, get(adj)); // add vertex to BFS Queue
            }
            moveNext(adj); // Advance to next vertex in temp's adjacent list
        }
        G->color[temp] = BLACK; // Vertex has been fully processed
    }
    freeList(&queue);
}

// Other Operations ---------------------------------------------------------------------------------------------

void printGraph(FILE* out, Graph G) { // Prints the adjacency list representation of G to FILE* out
    if(G != NULL && out != NULL){
        for(int i = 1; i <= getOrder(G); i++) {
            fprintf(out, "%d: ", i);
            printList(out, G->adj[i]);
            fprintf(out, "\n");
        }
    }
}