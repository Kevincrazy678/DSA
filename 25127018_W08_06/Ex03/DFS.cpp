#include "DFS.h"
using namespace std;

//function to read adjacency matrix from file
int readMatrix(int adj[MAX][MAX], const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) return 0;

    int n = 0, value;
    //Read all values into a temporary vector to determine n
    vector<int> temp;
    while (file >> value) {
        temp.push_back(value);
    }
    file.close();

    //Calculate n based on the number of values read (n*n)
    if (temp.empty()) return 0;
    for (n = 0; n * n < temp.size(); n++);

    //Fill the adjacency matrix
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = temp[k++];
        }
    }
    return n;
}

//DFS function to traverse the graph
void DFS(int u, int n, int adj[MAX][MAX], bool visited[], vector<int>& result) {
    //check if the vertex is already visited
    visited[u] = true;      
    //save the visited vertex to the result vector
    result.push_back(u);    

    for (int v = 0; v < n; v++) {
        //if there is an edge from u to v and v is not visited, continue DFS on vertex v
        if (adj[u][v] == 1 && !visited[v]) {
            DFS(v, n, adj, visited, result);
        }
    }
}

//function to save the DFS result to a file
void saveResult(const vector<int>& result, const char* filename) {
    ofstream file(filename);
    for (size_t i = 0; i < result.size(); i++) {
        file << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    file.close();
}