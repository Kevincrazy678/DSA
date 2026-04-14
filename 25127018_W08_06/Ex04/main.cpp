#include "BFS.h"
using namespace std;
int main() {
    //Time complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph
    //Space complexity: O(V) for the visited array and the result vector, where V is the number of vertices in the graph
    
    //Initialize the adjacency matrix, visited array, and result vector
    int adj[MAX][MAX];
    bool visited[MAX] = {false};
    vector<int> result;

    int n = readMatrix(adj, "input.txt");
    if (n == 0) {
        cout << "File can't be found or the matrix is empty!" << endl;
        return 1;
    }

    //Input the starting vertex for BFS
    int startVertex;
    cout << "Input the start vertex: ";
    cin >> startVertex;

    //Check if the starting vertex is valid
    if (startVertex < 0 || startVertex >= n) {
        cout << "Dinh khong hop le!" << endl;
        return 1;
    }

    //Perform BFS traversal
    BFS(startVertex, n, adj, visited, result);

    saveResult(result, "output.txt");
        
    cout << "\nThe result has been saved to output.txt" << endl;

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
2
Expected output: 2 0 4 1 3

Test case 2: invalid starting vertex
Input file (input.txt):
0 1 1 
1 0 0
1 0 0
-1
Expected output: The starting vertex is invalid!

Test case 3: file not found
Input file (input.txt): (file does not exist)
Expected output: File can't be found or the matrix is empty!
*/