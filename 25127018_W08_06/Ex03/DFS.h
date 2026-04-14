#ifndef DFS_LIB_H
#define DFS_LIB_H
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>

//if the graph has more than MAX vertices, it will cause overflow in the adjacency matrix
const int MAX = 100;

//function prototypes

int readMatrix(int adj[MAX][MAX], const char* filename);

void DFS(int u, int n, int adj[MAX][MAX], bool visited[], vector<int>& result);

void saveResult(const vector<int>& result, const char* filename);

#endif