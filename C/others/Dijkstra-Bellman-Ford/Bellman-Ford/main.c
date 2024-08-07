// A C++ program for Bellman-Ford's single source
// shortest path algorithm.
// #include <bits/stdc++.h>
// using namespace std;
#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647

// a structure to represent a weighted edges in graph
typedef struct Edge 
{
    int src, dest, weight;
} EDGE;

// a structure to represent a connected, directed and
// weighted graph
typedef struct Graph 
{
    // NVertices-> Number of vertices, NEgdes-> Number of edges
    int NVertices, NEgdes;

    // graph is represented as an array of edges.
    EDGE* edges;
} GRAPH;

// Creates a graph with NVertices and NEgdes 
GRAPH* createGraph(int NVertices, int NEgdes)
{
    GRAPH* graph = (GRAPH*) malloc(sizeof(GRAPH));
    graph->NVertices = NVertices;
    graph->NEgdes = NEgdes;
    graph->edges = (EDGE*) malloc(sizeof(EDGE)*NEgdes);
    return graph;
}

// function used to print the solution
void printArr(int dist[], int n)
{
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

// The main function that finds shortest distances from src
// to all other vertices using Bellman-Ford algorithm.  The
// function also detects negative weight cycle
void BellmanFord(GRAPH* graph, int src)
{
    int NVertices = graph->NVertices;
    int NEgdes = graph->NEgdes;
    int dist[NVertices];

    // Step 1: Initialize distances from src to all other
    // vertices as INFINITE
    for (int i = 0; i < NVertices; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // Step 2: Relax all edges |NVertices| - 1 times. A simple
    // shortest path from src to any other vertex can have
    // at-most |NVertices| - 1 edges
    for (int i = 1; i <= NVertices - 1; i++) {
        for (int j = 0; j < NEgdes; j++) {
            int u = graph->edges[j].src;
            int v = graph->edges[j].dest;
            int weight = graph->edges[j].weight;
            if (dist[u] != INT_MAX
                && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Step 3: check for negative-weight cycles.  The above
    // step guarantees shortest distances if graph doesn't
    // contain negative weight cycle.  If we get a shorter
    // path, then there is a cycle.
    for (int i = 0; i < NEgdes; i++) {
        int u = graph->edges[i].src;
        int v = graph->edges[i].dest;
        int weight = graph->edges[i].weight;
        if (dist[u] != INT_MAX
            && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle");
            return; // If negative cycle is detected, simply
                    // return
        }
    }

    printArr(dist, NVertices);

    return;
}

// Driver's code
int main()
{
    /* Let us create the graph given in above example */
    int NVertices = 5; // Number of vertices in graph
    int NEgdes = 8; // Number of edges in graph
    GRAPH* graph = createGraph(NVertices, NEgdes);

    // add edges 0-1 (or A-B in above figure)
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = -1;

    // add edges 0-2 (or A-C in above figure)
    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 4;

    // add edges 1-2 (or B-C in above figure)
    graph->edges[2].src = 1;
    graph->edges[2].dest = 2;
    graph->edges[2].weight = 3;

    // add edges 1-3 (or B-D in above figure)
    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 2;

    // add edges 1-4 (or B-NEgdes in above figure)
    graph->edges[4].src = 1;
    graph->edges[4].dest = 4;
    graph->edges[4].weight = 2;

    // add edges 3-2 (or D-C in above figure)
    graph->edges[5].src = 3;
    graph->edges[5].dest = 2;
    graph->edges[5].weight = 5;

    // add edges 3-1 (or D-B in above figure)
    graph->edges[6].src = 3;
    graph->edges[6].dest = 1;
    graph->edges[6].weight = 1;

    // add edges 4-3 (or NEgdes-D in above figure)
    graph->edges[7].src = 4;
    graph->edges[7].dest = 3;
    graph->edges[7].weight = -3;
    
      // Function call
    BellmanFord(graph, 0);

    return 0;
}