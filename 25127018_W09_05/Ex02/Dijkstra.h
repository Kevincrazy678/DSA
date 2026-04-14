#ifndef Dijkstra_H
#define Dijkstra_H
using namespace std;
#include<iostream>
#include<fstream>
#include<vector>

const int maxn = 101;
const int INF = 1e9;

// Function prototypes
// Reads the adjacency matrix from a file and fills the provided matrix.
int readMatrix(int adj[maxn][maxn], const char* filename);

// Implements Dijkstra's algorithm to find the shortest paths from the start node to all other nodes in the graph.
void dijkstra(int start, int n, int adj[maxn][maxn], int dist[maxn]);

// Outputs the results of Dijkstra's algorithm, including the shortest distances from the start node to all other nodes, to a specified file.
void result(int n, int start, int dist[maxn], const char* filename);

#endif