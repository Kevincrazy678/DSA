#ifndef CONNECTED_COMPONENTS_H
#define CONNECTED_COMPONENTS_H
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>

const int MAX = 100;

//function prototypes

//function to read the adjacency matrix from a file and return the number of vertices in the graph
int readMatrix(int adj[MAX][MAX], const char* filename);

//function to find the connected components of the graph using depth-first search (DFS)
void findComponents(int n, int adj[MAX][MAX], vector<vector<int>>& components);

//function to perform depth-first search (DFS) and mark the visited vertices
void saveResults(const vector<vector<int>>& components, const char* filename);

#endif