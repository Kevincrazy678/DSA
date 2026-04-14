#include "BFS.h"
using namespace std;

int readMatrix(int adj[MAX][MAX], const char* filename) {
    //open the file and read the adjacency matrix
    ifstream file(filename);
    if (!file.is_open()) return 0;

    //read values into a temporary vector to determine the size of the matrix
    int value, count = 0;
    vector<int> temp;
    //read all values from the file into a temporary vector
    while (file >> value) {
        temp.push_back(value);
        count++;
    }
    file.close();
    
    //determine the size of the matrix (n x n) based on the number of values read
    int n = 0;
    while (n * n < count) n++;

    //fill the adjacency matrix with the values from the temporary vector
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = temp[k++];
        }
    }
    return n;
}

void BFS(int start, int n, int adj[MAX][MAX], bool visited[], vector<int>& result) {
    queue<int> q;

    //start BFS from the given starting vertex
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); //Get the front vertex from the queue
        q.pop();
        result.push_back(u);

        //Explore all adjacent vertices of u
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                visited[v] = true; //Mark the vertex as visited
                q.push(v);
            }
        }
    }
}

void saveResult(const std::vector<int>& result, const char* filename) {
    //save the BFS result to a file
    ofstream file(filename);
    for (size_t i = 0; i < result.size(); i++) {
        //write each vertex in the result vector to the file, separated by spaces
        file << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    file.close();
}