#include "CC.h"
using namespace std;

//function to read the adjacency matrix from a file and return the number of vertices in the graph
int readMatrix(int adj[MAX][MAX], const char* filename) {
    //open the file and read the adjacency matrix into the 2D array adj
    ifstream file(filename);
    if (!file.is_open()) return 0;

    //read all values into a temporary vector to determine the size of the matrix
    int value, count = 0;
    vector<int> temp;
    while (file >> value) {
        temp.push_back(value);
        count++;
    }
    file.close();


    //calculate the size of the matrix (n x n) based on the number of values read
    int n = 0;
    while (n * n < count) n++;

    //fill the adjacency matrix adj with the values from the temporary vector
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = temp[k++];
        }
    }
    return n;
}

//DFS function to explore the graph and mark visited vertices
void DFS(int u, int n, int adj[MAX][MAX], bool visited[], std::vector<int>& currentComp) {
    visited[u] = true;
    currentComp.push_back(u);

    //explore all adjacent vertices of u
    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            DFS(v, n, adj, visited, currentComp);
        }
    }
}

//main function to find the connected components of the graph using depth-first search (DFS)
void findComponents(int n, int adj[MAX][MAX], vector<vector<int>>& components) {
    bool visited[MAX] = {false};

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> currentComp;
            DFS(i, n, adj, visited, currentComp);
            components.push_back(currentComp);
        }
    }
}

//function to save the results of connected components to a file
void saveResults(const vector<vector<int>>& components, const char* filename) {
    ofstream file(filename);
    if (!file.is_open()) return;

    //the first line: the number of connected components
    file << components.size() << "\n";

    //the next lines: the vertices in each connected component, separated by spaces
    for (const auto& comp : components) {
        for (size_t i = 0; i < comp.size(); i++) {
            file << comp[i] << (i == comp.size() - 1 ? "" : " ");
        }
        file << "\n";
    }
    file.close();
}