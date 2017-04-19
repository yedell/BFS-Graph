////===============================================================================================================
//// GraphTest.c
//// A file for testing Graph ADT functions.
//// Creates & prints 100-vertex Graph, checks various distances, and then clears & prints the empty graph.
////
//// Yona Edell
//// CruzID: yedell
//// CMPS 101
//// PA4
//// 02/18/2017
////===============================================================================================================
//
//#include<stdio.h>
//#include"Graph.h"
//
//int main() {
//
//    int n = 100;
//    Graph G = newGraph(n); // Build graph G
//
//    addEdge(G, 13, 30);
//    addEdge(G, 77, 86);
//    addEdge(G, 20, 18);
//    addEdge(G, 4, 44);
//    addEdge(G, 16, 13);
//    addEdge(G, 64, 73);
//    addEdge(G, 21, 41);
//    addEdge(G, 82, 100);
//    addEdge(G, 100, 65);
//    addEdge(G, 74, 92);
//    addEdge(G, 60, 96);
//    addEdge(G, 97, 90);
//    addEdge(G, 64, 89);
//    addEdge(G, 99, 64);
//    addEdge(G, 7, 23);
//    addEdge(G, 3, 53);
//    addEdge(G, 17, 66);
//    addEdge(G, 76, 67);
//    addEdge(G, 21, 68);
//    addEdge(G, 78, 93);
//    addEdge(G, 50, 31);
//    addEdge(G, 63, 94);
//    addEdge(G, 50, 45);
//    addEdge(G, 23, 20);
//    addEdge(G, 65, 72);
//    addEdge(G, 3, 4);
//    addEdge(G, 87, 24);
//    addEdge(G, 25, 33);
//    addEdge(G, 44, 5);
//    addEdge(G, 37, 87);
//    addEdge(G, 87, 18);
//    addEdge(G, 65, 31);
//    addEdge(G, 31, 1);
//    addEdge(G, 84, 3);
//    addEdge(G, 80, 16);
//    addEdge(G, 64, 52);
//    addEdge(G, 84, 56);
//    addEdge(G, 56, 86);
//    addEdge(G, 83, 49);
//    addEdge(G, 72, 67);
//    addEdge(G, 90, 8);
//    addEdge(G, 22, 96);
//    addEdge(G, 51, 73);
//    addEdge(G, 71, 62);
//    addEdge(G, 36, 62);
//    addEdge(G, 92, 43);
//    addEdge(G, 19, 34);
//    addEdge(G, 84, 17);
//    addEdge(G, 75, 91);
//    addEdge(G, 35, 82);
//    addEdge(G, 29, 33);
//    addEdge(G, 25, 23);
//    addEdge(G, 65, 89);
//    addEdge(G, 92, 58);
//    addEdge(G, 31, 22);
//    addEdge(G, 71, 33);
//    addEdge(G, 34, 10);
//    addEdge(G, 30, 24);
//    addEdge(G, 27, 44);
//    addEdge(G, 26, 8);
//    addEdge(G, 99, 56);
//    addEdge(G, 25, 40);
//    addEdge(G, 47, 12);
//    addEdge(G, 69, 84);
//    addEdge(G, 2, 11);
//    addEdge(G, 43, 59);
//    addEdge(G, 99, 23);
//    addEdge(G, 34, 1);
//    addEdge(G, 3, 39);
//    addEdge(G, 42, 43);
//    addEdge(G, 87, 6);
//    addEdge(G, 50, 55);
//    addEdge(G, 83, 92);
//    addEdge(G, 62, 53);
//    addEdge(G, 90, 15);
//    addEdge(G, 69, 31);
//    addEdge(G, 45, 24);
//    addEdge(G, 34, 45);
//    addEdge(G, 8, 45);
//    addEdge(G, 8, 21);
//    addEdge(G, 98, 36);
//    addEdge(G, 50, 19);
//    addEdge(G, 21, 71);
//    addEdge(G, 82, 1);;
//    addEdge(G, 77, 65);
//    addEdge(G, 55, 15);
//    addEdge(G, 73, 28);
//    addEdge(G, 85, 5);
//    addEdge(G, 37, 49);
//    addEdge(G, 96, 3);
//    addEdge(G, 37, 84);
//    addEdge(G, 90, 81);
//    addEdge(G, 94, 98);
//    addEdge(G, 90, 73);
//    addEdge(G, 98, 97);
//    addEdge(G, 89, 34);
//    addEdge(G, 80, 66);
//    addEdge(G, 70, 30);
//    addEdge(G, 26, 2);
//    addEdge(G, 20, 59);
//    addEdge(G, 5, 66);
//    addEdge(G, 74, 22);
//    addEdge(G, 80, 76);
//    addEdge(G, 62, 32);
//    addEdge(G, 62, 61);
//    addEdge(G, 50, 16);
//    addEdge(G, 52, 73);
//    addEdge(G, 69, 4);
//    addEdge(G, 97, 81);
//    addEdge(G, 46, 90);
//    addEdge(G, 30, 11);
//    addEdge(G, 94, 25);
//    addEdge(G, 83, 64);
//    addEdge(G, 65, 62);
//    addEdge(G, 12, 39);
//    addEdge(G, 28, 50);
//    addEdge(G, 30, 84);
//    addEdge(G, 72, 68);
//    addEdge(G, 38, 52);
//    addEdge(G, 43, 65);
//    addEdge(G, 60, 81);
//    addEdge(G, 8, 4);
//    addEdge(G, 82, 34);
//    addEdge(G, 55, 10);
//    addEdge(G, 44, 41);
//    addEdge(G, 57, 61);
//
//    // Print adjacency list representation of G
//    printGraph(stdout, G);
//
//    // Dist Test 1 ------------------------------------------------------------
//    int u = 100, v = 42; // u is source, v is dest
//
//    printf("\n");
//    BFS(G, u);
//    printf("The distance from %d to %d is ", u, v);
//
//    if (getDist(G, v) == INF) { // If no path exists between source and dest
//        printf("infinity\n");
//    } else { // If path exists between source and dest
//        printf("%d\n", getDist(G, v));
//    }
//
//    List path = newList(); // path = shortest path between source and dest
//    getPath(path, G, v);   // store shortest path in 'path'
//    if (front(path) == NIL) { // If no path exists
//        printf("No %d-%d path exists\n", u, v); //
//    } else { // If a path does exist
//        printf("A shortest %d-%d path is: ", u, v);
//        printList(stdout, path);
//        printf("\n"); //
//    }
//
//    // Dist Test 2 ------------------------------------------------------------
//    u = 42;
//    v = 100; // 42-100
//
//    printf("\n");
//    BFS(G, u);
//    printf("The distance from %d to %d is ", u, v);
//
//    if (getDist(G, v) == INF) { // If no path exists between source and dest
//        printf("infinity\n");
//    } else { // If path exists between source and dest
//        printf("%d\n", getDist(G, v));
//    }
//
//    clear(path); // path = shortest path between source and dest
//    getPath(path, G, v);   // store shortest path in 'path'
//    if (front(path) == NIL) { // If no path exists
//        printf("No %d-%d path exists\n", u, v); //
//    } else { // If a path does exist
//        printf("A shortest %d-%d path is: ", u, v);
//        printList(stdout, path);
//        printf("\n"); //
//    }
//
//    // Dist Test 3 ------------------------------------------------------------
//    u = 42;
//    v = 42; // 42-42
//
//    printf("\n");
//    BFS(G, u);
//    printf("The distance from %d to %d is ", u, v);
//
//    if (getDist(G, v) == INF) { // If no path exists between source and dest
//        printf("infinity\n");
//    } else { // If path exists between source and dest
//        printf("%d\n", getDist(G, v));
//    }
//
//    clear(path); // path = shortest path between source and dest
//    getPath(path, G, v);   // store shortest path in 'path'
//    if (front(path) == NIL) { // If no path exists
//        printf("No %d-%d path exists\n", u, v); //
//    } else { // If a path does exist
//        printf("A shortest %d-%d path is: ", u, v);
//        printList(stdout, path);
//        printf("\n"); //
//    }
//
//    // Dist Test 4 ------------------------------------------------------------
//    u = 100;
//    v = 100; // 100-100
//
//    printf("\n");
//    BFS(G, u);
//    printf("The distance from %d to %d is ", u, v);
//
//    if (getDist(G, v) == INF) { // If no path exists between source and dest
//        printf("infinity\n");
//    } else { // If path exists between source and dest
//        printf("%d\n", getDist(G, v));
//    }
//
//    clear(path); // path = shortest path between source and dest
//    getPath(path, G, v);   // store shortest path in 'path'
//    if (front(path) == NIL) { // If no path exists
//        printf("No %d-%d path exists\n", u, v); //
//    } else { // If a path does exist
//        printf("A shortest %d-%d path is: ", u, v);
//        printList(stdout, path);
//        printf("\n"); //
//    }
//
//    // Dist Test 5 ------------------------------------------------------------
//    u = 7;
//    v = 14; // 7-14
//
//    printf("\n");
//    BFS(G, u);
//    printf("The distance from %d to %d is ", u, v);
//
//    if (getDist(G, v) == INF) { // If no path exists between source and dest
//        printf("infinity\n");
//    } else { // If path exists between source and dest
//        printf("%d\n", getDist(G, v));
//    }
//
//    clear(path); // path = shortest path between source and dest
//    getPath(path, G, v);   // store shortest path in 'path'
//    if (front(path) == NIL) { // If no path exists
//        printf("No %d-%d path exists\n", u, v); //
//    } else { // If a path does exist
//        printf("A shortest %d-%d path is: ", u, v);
//        printList(stdout, path);
//        printf("\n"); //
//    }
//
//    // Dist Test 6 ------------------------------------------------------------
//    u = 14;
//    v = 7; // 14-7
//
//    printf("\n");
//    BFS(G, u);
//    printf("The distance from %d to %d is ", u, v);
//
//    if (getDist(G, v) == INF) { // If no path exists between source and dest
//        printf("infinity\n");
//    } else { // If path exists between source and dest
//        printf("%d\n", getDist(G, v));
//    }
//
//    clear(path); // path = shortest path between source and dest
//    getPath(path, G, v);   // store shortest path in 'path'
//    if (front(path) == NIL) { // If no path exists
//        printf("No %d-%d path exists\n", u, v); //
//    } else { // If a path does exist
//        printf("A shortest %d-%d path is: ", u, v);
//        printList(stdout, path);
//        printf("\n"); //
//    }
//
//    // Dist Test 7 ------------------------------------------------------------
//    u = 14;
//    v = 14; // 14-14
//
//    printf("\n");
//    BFS(G, u);
//    printf("The distance from %d to %d is ", u, v);
//
//    if (getDist(G, v) == INF) { // If no path exists between source and dest
//        printf("infinity\n");
//    } else { // If path exists between source and dest
//        printf("%d\n", getDist(G, v));
//    }
//
//    clear(path); // path = shortest path between source and dest
//    getPath(path, G, v);   // store shortest path in 'path'
//    if (front(path) == NIL) { // If no path exists
//        printf("No %d-%d path exists\n", u, v); //
//    } else { // If a path does exist
//        printf("A shortest %d-%d path is: ", u, v);
//        printList(stdout, path);
//        printf("\n"); //
//    }
//
//    // Dist Test 8 ------------------------------------------------------------
//    u = 7;
//    v = 7; // 7-7
//
//    printf("\n");
//    BFS(G, u);
//    printf("The distance from %d to %d is ", u, v);
//
//    if (getDist(G, v) == INF) { // If no path exists between source and dest
//        printf("infinity\n");
//    } else { // If path exists between source and dest
//        printf("%d\n", getDist(G, v));
//    }
//
//    clear(path); // path = shortest path between source and dest
//    getPath(path, G, v);   // store shortest path in 'path'
//    if (front(path) == NIL) { // If no path exists
//        printf("No %d-%d path exists\n", u, v); //
//    } else { // If a path does exist
//        printf("A shortest %d-%d path is: ", u, v);
//        printList(stdout, path);
//        printf("\n"); //
//    }
//
//    // Clear Test --------------------------------------------------------------
//    printf("\nClear G:\n");
//    makeNull(G);
//    printGraph(stdout, G); // Print empty graph (no edges)
//
//    // Free objects
//    freeGraph(&G);
//    freeList(&path);
//
//    return (0);
//}