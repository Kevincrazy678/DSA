#include "ETT.h"
using namespace std;

int main() {
    //Time complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph
    //Space complexity: O(V) for the visited array and the tour vector, where V is the number of vertices in the graph

    //Initialize the adjacency matrix, visited array, and tour vector
    int adj[MAX][MAX];
    bool visited[MAX] = {false};
    vector<int> tour;

    int n = readMatrix(adj, "input.txt");
    if (n == 0) {
        cout << "File can't be found or the matrix is empty!" << endl;
        return 1;
    }

    int startVertex;
    cout << "Please enter the starting vertex: ";
    cin >> startVertex;

    if (startVertex < 0 || startVertex >= n) {
        cout << "The starting vertex is invalid" << endl;
        return 1;
    }

    //Euler Tour Traversal
    findEulerTour(startVertex, n, adj, visited, tour);

    //Save the Euler tour result to a file
    saveResult(tour, "output.txt");

    cout << "\nThe result has been saved to file output.txt" << endl;

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
3
Expected output: 3 1 0 2 4 2 0 1 3

Test case 2: empty file
Input file (input.txt): (empty)
Expected output: "File can't be found or the matrix is empty!"

Test case 3: invalid starting vertex
Input file (input.txt):
0 1 0
1 0 1
0 1 0
-1
Expected output: "The starting vertex is invalid"
*/