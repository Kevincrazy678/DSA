#include "Dijkstra.h"
using namespace std;

// Reads the adjacency matrix from a file and fills the provided matrix.
int readMatrix(int adj[maxn][maxn], const char* filename){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file!" << endl;
        return 0;
    }

    // Read all values into a temporary vector to determine the size of the matrix
    int value, cnt = 0;
    vector<int>temp;
    while(file >> value){
        temp.push_back(value);
        cnt++;
    }
    file.close();

    // Determine the size of the matrix (n x n) based on the number of values read
    int n = 0;
    while(n*n < cnt) n++;

    // Fill the adjacency matrix with the values from the temporary vector
    int k = 0;
    for(int i=0; i<n; i++){
        for(int j = 0; j<n; j++){
            adj[i][j] = temp[k++];
        }
    }
    return n;
}

void dijkstra(int start, int n, int adj[maxn][maxn], int dist[maxn]) {
    // Initialize visited array to keep track of visited nodes
    bool visited[maxn] = {false};

    // Initialize distances to infinity, except for the start node which is set to 0
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    // Main loop of Dijkstra's algorithm
    for (int count = 0; count < n - 1; count++) {
        // Find the unvisited node with the smallest distance
        int minDistance = INF, u = -1;
        for (int i = 0; i < n; i++) {
            // Update minDistance and u if the current node is unvisited and has a smaller distance
            if (!visited[i] && dist[i] < minDistance) {
                minDistance = dist[i];
                u = i;
            }
        }

        if (u == -1) break; 

        visited[u] = true;

        // Update the distances of the neighboring nodes of u
        for (int v = 0; v < n; v++) {
            if (!visited[v] && adj[u][v] > 0 && dist[u] != INF 
                && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
}

void result(int n, int start, int dist[maxn], const char* filename){
    // Write the results to the specified file
    ofstream file(filename);
    if(!file.is_open()){
        cerr << "Error opening file!" << endl;
        return;
    }

    file << "Shortest distances from node " << start << ":\n";
    for(int i=0; i<n; i++){
        file << "To node " << i << ": " << (dist[i] == INF ? "INF" : to_string(dist[i])) << "\n";
    }
    file.close();
}