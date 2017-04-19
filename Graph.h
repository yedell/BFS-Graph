//===============================================================================================================
// Graph.h
// Header file for Graph ADT and Breadth-first search algorithm.
// Uses Doubly Linked List ADT for adjacency list representation and Breadth-first search.
//
// Yona Edell
// CruzID: yedell
// CMPS 101
// PA4
// 02/18/2017
//===============================================================================================================

#include <stdio.h>
#include "List.h"

#define INF -10 // Infinity
#define NIL -1 // Undefined vertex label

#ifndef _GRAPH_H_INCLUDE_
#define _GRAPH_H_INCLUDE_

// Exported Type ------------------------------------------------------------------------------------------------

typedef struct GraphObj* Graph;

// Constructors-Destructors -------------------------------------------------------------------------------------

Graph newGraph(int n);
void freeGraph(Graph* pG);

// Access Functions ---------------------------------------------------------------------------------------------

int getOrder(Graph G);
int getSize(Graph G);
int getSource(Graph G);
int getParent(Graph G, int u);
int getDist(Graph G, int u);
void getPath(List L, Graph G, int u);

// Manipulation Procedures --------------------------------------------------------------------------------------

void makeNull(Graph G);
void addEdge(Graph G, int u, int v);
void addArc(Graph G, int u, int v);
void BFS(Graph G, int s);

// Other Operations ---------------------------------------------------------------------------------------------

void printGraph(FILE* out, Graph G);

#endif // GRAPH_H