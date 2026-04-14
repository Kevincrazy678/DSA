#ifndef BFS_H
#define BFS_H
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

const int MAX = 100;

//function prototypes

//function to read adjacency matrix from file
int readMatrix(int adj[MAX][MAX], const char* filename);

//BFS function to traverse the graph
void BFS(int start, int n, int adj[MAX][MAX], bool visited[], vector<int>& result);

//function to save the BFS result to a file
void saveResult(const vector<int>& result, const char* filename);

#endif