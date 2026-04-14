#include "DFS.h"
using namespace std;

int main() {
    //Time complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph
    //Space complexity: O(V) for the visited array and the result vector, where V is the number of vertices in the graph

    int adj[MAX][MAX];     //Matrix adjacency to store the graph
    bool visited[MAX] = {false}; // Array to keep track of visited vertices
    std::vector<int> result; // Save the order of visited vertices

    // Read the adjacency matrix from the file
    int n = readMatrix(adj, "input.txt");
    if (n == 0) {
        std::cout << "File can't be found or the matrix is empty!" << endl;
        return 1;
    }

    //Input the starting vertex for DFS
    int startVertex;
    cout << "Input the first vertex to start";
    cin >> startVertex;

    if (startVertex < 0 || startVertex >= n) {
        cout << "The vertex is invalid" << endl;
        return 1;
    }

    //DFS traversal
    DFS(startVertex, n, adj, visited, result);

    //Save the result to output.txt
    saveResult(result, "output.txt");
    
    std::cout << "\nThe result has been saved to file output.txt" << std::endl;

    return 0;
}

/*
Test case 1: normal case
Input file (input.txt):
0 1 1 0 0
1 0 0 1 0
1 0 0 0 1
0 1 0 0 1
0 0 1 1 0
1

Expected output: 1 0 2 4 3

Test case 2: empty file
Input file (input.txt):

Expected output: File can't be found or the matrix is empty!

Test case 3: invalid starting vertex
Input file (input.txt):
0 1 1
1 0 0
4
Expected output: The vertex is invalid
*/