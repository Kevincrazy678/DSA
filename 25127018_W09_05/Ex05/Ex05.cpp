class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        //Time Complexity: O(E log V) where E is the number of edges and V is the number of vertices.
        //Space Complexity: O(V + E) where V is the number of vertices and E is the number of edges, and this is due to the adjacency list and the distance array.
        vector<vector<pair<int, double>>>adj(n);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double>d(n, 0.0);
        d[start_node] = 1.0;
        //we use a max heap to always expand the node with the highest probability first, ensuring that we find the maximum probability path efficiently.
        //but this is kind of similar to Dijkstra's algorithm, but instead of summing the weights, we multiply them, and we are looking for the maximum product path instead of the shortest path.
        priority_queue<pair<double, int>>pq;
        pq.push({1.0, start_node});
        //we continue to expand nodes until we either find the end node or exhaust all possibilities. 
        //If we find the end node, we return the probability associated with it. If we exhaust all possibilities without finding the end node, we return 0, indicating that there is no path from the start node to the end node.
        while(!pq.empty()){
            auto top = pq.top(); pq.pop();
            int v = top.second;
			double dis = top.first;
            
            if(dis < d[v])continue;
            if(v == end_node)return d[v];
            /*we iterate through the neighbors of the current node, calculating the new probability to 
            reach each neighbor through the current node. If this new probability is greater than the previously recorded 
            probability for that neighbor, we update it and push it onto the priority queue for further exploration.
            */
            for(auto x : adj[v]){
                int ve_before = x.first;
				double w = x.second;
                //we used Dijkstra's algorithm to find the maximum probability path from the start node to the end node. 
                //The key difference is that instead of summing edge weights, we multiply probabilities, and we use a max heap to prioritize paths with higher probabilities.
                if(d[ve_before] < d[v] * w){
                    d[ve_before] = d[v] * w;
                    pq.push({d[ve_before], ve_before});
                }
            }
        }
        return d[end_node];
    }
};

/*
Test case 1: normal case
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start_node = 0, end_node = 2
Output: 0.25

Test case 2: normal case
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start_node = 0, end_node = 2
Output: 0.3

Test case 3: empty graph
Input: n = 0, edges = [], succProb = [], start_node = 0, end_node = 0
Output: 0.0
*/