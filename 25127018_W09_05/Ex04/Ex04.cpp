class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        /*Time Complexity: O(N*M*log(N*M)) where N is the number of rows and M is the number of columns in the moveTime grid. 
        This is because we are using a priority queue to explore the grid, and in the worst case, we may need to explore all cells.
        Space Complexity: O(N*M) where N is the number of rows and M is the number of columns in the moveTime grid. 
        This is because we are using a distance array to store the minimum time to reach each cell, and in the worst case, we may need to store a value for each cell in the grid.
        */
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        int n = moveTime.size(), m = moveTime[0].size();
        //we use Dijkstra's algorithm to find the minimum time to reach the bottom-right corner of the grid.
        vector<vector<int>>d(n, vector<int>(m, INT_MAX));
        d[0][0] = 0;
        //we use a priority queue to always expand the cell with the smallest time first, ensuring that we find the minimum time path efficiently.
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});
        //we continue to expand cells until we either find the bottom-right corner or exhaust all possibilities.
        while(!pq.empty()){
            auto [time, r, c] = pq.top(); pq.pop();

            //if the current time is greater than the recorded time for this cell, we skip it, as we have already found a faster way to reach this cell.
            if(time > d[r][c])continue;
            if(r == n-1 && c == m-1)return time;

            /*the move time for the next step depends on the parity of the current cell's coordinates. 
            If the sum of the row and column indices is even, the move time is 1; otherwise, it is 2. 
            This is because we can only move to adjacent cells (up, down, left, right) and the time taken to move depends on whether we are moving from an even or odd cell.
            */
            int move = ((r+c)%2 == 0) ? 1 : 2;
            for(int i=0; i<4; i++){
                //we calculate the new time to reach the adjacent cell, which is the maximum of the current time and the move time of the adjacent cell, plus the move time for the current step.
                int nr = r + dx[i], nc = c + dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int wait = max(time, moveTime[nr][nc]);
                    int next = wait + move;
                    //if this new time is less than the previously recorded time for the adjacent cell, we update it and push it onto the priority queue for further exploration.
                    if(next < d[nr][nc]){
                        d[nr][nc] = next;
                        pq.push({next, nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};

/*
Test case 1: normal case
Input: moveTime = [[0,1,2],[1,2,3],[2,3,4]]
Output: 7

Test case 2: zero time case
Input: moveTime = [[0,0,0],[0,0,0],[0,0,0]]
Output: 4

Test case 3: single cell grid
Input: moveTime = [[0]]
Output: 0

*/