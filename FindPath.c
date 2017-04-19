////===============================================================================================================
//// FindPath.c
//// Creates Graph from vertices specified in the given input file and prints
//// adjacency list & shortest path(s) to the given output file.
////
//// Yona Edell
//// CruzID: yedell
//// CMPS 101
//// PA4
//// 02/18/2017
////===============================================================================================================
//
//#include<stdio.h>
//#include<stdlib.h>
//#include"Graph.h"
//
//#define MAX_LEN 512
//
//int main(int argc, char * argv[]) {
//
//    // Check command line for correct number of arguments
//    if(argc != 3) {
//        printf("Usage: %s <input file> <output file>\n", argv[0]);
//        exit(1);
//    }
//
//    // Variables
//    FILE *input, *output;
//    char line[MAX_LEN];
//    int order = 0, u = 0, v = 0;
//    Graph G = NULL;
//
//    // Opening files for read/write
//    input = fopen(argv[1], "r");
//    output = fopen(argv[2], "w");
//
//    if(input == NULL) {
//        printf("FindPath Error: cannot read file %s\n", argv[1]);
//        exit(1);
//    }
//    if(output == NULL) {
//        printf("FindPath Error: cannot write file %s\n", argv[2]);
//        exit(1);
//    }
//
//    // Creating graph w/ order
//    fgets(line, MAX_LEN, input); // Store first line from input file into String line
//    sscanf(line, "%d", &order);  // Convert String line into int order
//    G = newGraph(order);
//
//    // Adding edges to graph
//    while(fgets(line, MAX_LEN, input) != NULL) { // Read input file for vertices
//        sscanf(line, "%d %d", &u, &v);           // Convert String vertices into ints
//        if(u == 0 && v == 0) { // Stop adding when line is "0 0"
//            break;
//        }
//        addEdge(G, u, v);
//    }
//
//    printGraph(output, G);
//
//    // BFS/Shortest Path
//    while(fgets(line, MAX_LEN, input) != NULL) { // Read input file until end
//        //u = v = 0;
//        sscanf(line, "%d %d", &u, &v); // Convert String vertices into ints
//        if(u == 0 && v == 0) {         // Stop when line is "0 0"
//            break;
//        }
//        fprintf(output, "\n");
//
//        BFS(G, u); // Run BFS
//        fprintf(output, "The distance from %d to %d is ", u, v);
//
//        if(getDist(G, v) == INF) { // If no path exists between source and dest
//            fprintf(output, "infinity\n");
//            fprintf(output, "No %d-%d path exists\n", u, v); //
//        }
//        else { // If path exists between source and dest
//            fprintf(output, "%d\n", getDist(G, v));
//
//            List path = newList(); // path = shortest path between source and dest
//            getPath(path, G, v);   // store shortest path in 'path'
//
//            fprintf(output, "A shortest %d-%d path is: ", u, v); //
//            printList(output, path);                             //
//            fprintf(output, "\n");                               //
//
//            freeList(&path);
//        }
//    }
//
//    freeGraph(&G); // Memory Leaks? No thanks!!
//
//    // Close Reader/Writer
//    fclose(input);
//    fclose(output);
//
//    return 0;
//}