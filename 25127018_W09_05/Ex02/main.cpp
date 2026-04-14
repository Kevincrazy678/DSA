#include "Dijkstra.h"
using namespace std;

int main(){
    /*Time complexity: O(V^2) due to the nested loops in Dijkstra's algorithm in the worst case when all nodes are connected 
    in matrix adjacency list representation. The algorithm iterates through all nodes to find the unvisited node with the smallest distance, 
    and then updates the distances of its neighbors, leading to a quadratic time complexity in the worst case.
    Space complexity: O(V^2) for the adjacency matrix, which requires space to store the distances between all pairs of nodes.
    */

    /*
    if the graph we represented is list adjacency list representation, the time complexity of Dijkstra's algorithm would be 
    O((V + E) log V) where V is the number of vertices and E is the number of edges.
    */
    int adj[maxn][maxn], dist[maxn];
    int n = readMatrix(adj, "input.txt");
    //check if the matrix was read successfully
    if(n==0){
        cout<<"Failed to read the adjacency matrix."<<endl;
        return 1;
    }
    
    //set the start node to 1, which is the first node in the graph
    int start = 1;
    //call Dijkstra's algorithm to find the shortest paths from the start node to all other nodes in the graph
    dijkstra(start, n, adj, dist);
    //output the results of Dijkstra's algorithm to a file named "output.txt"
    result(n, start, dist, "output.txt");

    return 0; 
}


/*
Test case 1: normal case
Input:
0 1 4 0 0 0
1 0 4 2 7 0
4 4 0 3 5 0
0 2 3 0 4 0
0 7 5 4 0 6
0 0 0 0 6 0

start node = 1

Expected output:
Shortest distances from node 1:
Node 1: 0
Node 2: 1
Node 3: 4
Node 4: 3
Node 5: 7
Node 6: 13

Test case 2: disconnected graph
Input:
0 1 0 0 0 0
1 0 0 0 0 0
0 0 0 1 0 0
0 0 1 0 0 0
0 0 0 0 0 1
0 0 0 0 1 0

start node = 1

Expected output:
Shortest distances from node 1:
Node 1: 0
Node 2: 1
Node 3: INF
Node 4: INF
Node 5: INF
Node 6: INF

Test case 3: only one node in graph
Input: 
0

start node = 1

Expected output:
Shortest distances from node 1:
To node 0: INF
*/