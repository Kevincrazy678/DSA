class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        /*
        - Time Complexity: O(n^3) due to the Floyd-Warshall algorithm, which is used to compute the shortest paths between all pairs of cities. 
        The algorithm iterates through each pair of cities and updates the shortest path, resulting in a cubic time complexity.
        - Space Complexity: O(n^2) due to the distance matrix used to store the shortest paths between all pairs of cities. The matrix has dimensions n x n, where n is the number of cities.
        */
        vector<vector<int>> dist(n, vector<int>(n, 1e9)); 
        
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0; 
        }
        //we initialize the distance matrix with a large value (1e9) to represent infinity, and we set the distance from each city to itself to 0. 
        //Then, we populate the distance matrix with the given edges, setting the distance between directly connected cities to the weight of the edge.
        for (auto& edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        //we use the Floyd-Warshall algorithm to compute the shortest paths between all pairs of cities.
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        int min_neighbors = n; 
        int best_city = -1;
        //we iterate through each city and count the number of neighboring cities that are reachable within the distance threshold.
        for (int i = 0; i < n; ++i) {
            int neighbors = 0; 
            //we count the number of neighboring cities that are reachable within the distance threshold by iterating through the distance matrix for the current city and checking if the distance to each other city is less than or equal to the threshold.
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    neighbors++;
                }
            }
            //we keep track of the city with the smallest number of reachable neighbors. If we find a city with fewer neighbors than the current minimum, we update our best city. 
            //In case of a tie, we choose the city with the greatest index, as specified in the problem statement.
            if (neighbors <= min_neighbors) {
                min_neighbors = neighbors;
                best_city = i;
            }
        }

        return best_city;
    }
};

/*
Test case 1: normal case
Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3

Test case 2: input with multiple cities having the same number of reachable neighbors
Input: n = 5, edges = [[0,1,2],[0,2,3],[1,2,1],[1,3,4],[2,3,1],[3,4,2]], distanceThreshold = 3
Output: 4

Test case 3: only three cities with varying distances
Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 3
*/