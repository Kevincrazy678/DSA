#include "ETT.h"
using namespace std;

int readMatrix(int adj[MAX][MAX], const char* filename) {
    //open the file and read the adjacency matrix
    fstream file(filename);
    if (!file.is_open()) return 0;

    //Read the values into a temporary vector and count the number of values
    int value, count = 0;
    vector<int> temp;
    while (file >> value) {
        temp.push_back(value);
        count++;
    }
    file.close();

    //Determine the size of the matrix (n x n) based on the number of values read
    int n = 0;
    while (n * n < count) n++;

    //Fill the adjacency matrix using the values from the temporary vector
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = temp[k++];
        }
    }
    return n;
}

//ETT is a depth-first traversal that records the vertices in the order they are visited.
void findEulerTour(int u, int n, int adj[MAX][MAX], bool visited[], vector<int>& tour) {
    visited[u] = true;
    tour.push_back(u); //Record the current vertex u in the tour

    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            findEulerTour(v, n, adj, visited, tour);
            
            //After visiting vertex v, we return to vertex u and record it again in the tour to indicate the return to the previous vertex.
            tour.push_back(u); 
        }
    }
}

void saveResult(const vector<int>& result, const char* filename) {
    //Save the Euler tour result to a file, with vertices separated by spaces
    ofstream file(filename);
    //Write the vertices in the result vector to the file, separated by spaces
    for (size_t i = 0; i < result.size(); i++) {
        //Write the current vertex to the file, followed by a space (except for the last vertex)
        file << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    file.close();
}