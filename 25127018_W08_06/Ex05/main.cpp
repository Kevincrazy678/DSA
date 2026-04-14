#include "CC.h"
using namespace std;

int main() {
    //Time complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph
    //Space complexity: O(V) for the visited array and O(V) for the current component vector, resulting in O(V) overall space complexity

    // Define the adjacency matrix and a vector to store the connected components
    int adj[MAX][MAX];
    vector<vector<int>> components;

    //Read the adjacency matrix from the input file and get the number of vertices
    int n = readMatrix(adj, "input.txt");
    if (n == 0) {
        cout << "File can't be found or the matrix is empty!" << endl;
        return 1;
    }

    //Find the connected components of the graph using depth-first search (DFS)
    findComponents(n, adj, components);

    //Save the results of connected components to an output file
    saveResults(components, "output.txt");

    cout << "Saved the results of connected components to file output.txt" << endl;

    return 0;
}

/*
Test case 1: no edges
Input (input.txt):
0 0 0
0 0 0
0 0 0
Output (output.txt):
3
0
1
2

Test case 2: normal case with some edges
Input (input.txt):
0 1 0 0 0
1 0 0 0 0
0 0 0 1 1
0 0 1 0 1
0 0 1 1 0
Output (output.txt):
2
0 1
2 3 4

Test case 3: complete graph
Input (input.txt):
0 1 1
1 0 1
1 1 0
Output (output.txt):
1
0 1 2
*/