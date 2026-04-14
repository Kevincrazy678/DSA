#ifndef EULER_TOUR_H
#define EULER_TOUR_H
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>

const int MAX = 100;

//function prototypes
int readMatrix(int adj[MAX][MAX], const char* filename);

//function to find the Euler tour of the graph
void findEulerTour(int u, int n, int adj[MAX][MAX], bool visited[], vector<int>& tour);

//function to save the Euler tour result to a file
void saveResult(const vector<int>& result, const char* filename);

#endif