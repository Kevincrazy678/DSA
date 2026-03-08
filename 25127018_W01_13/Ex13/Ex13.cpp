class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size(), sum = 0;
        //Complexity: O(n^2)
        vector<vector<int>>res;
        vector<int>maxr, maxc;
        //We are trying to find the max of the column and row
        for(int i=0; i<n; i++){ 
            int maxrow = 0, maxcol = 0;
            for(int j=0; j<n; j++){
                maxrow = max(maxrow, grid[i][j]);
                maxcol = max(maxcol, grid[j][i]);
                sum += grid[i][j];
            }
            maxr.push_back(maxrow);
            maxc.push_back(maxcol);
        }
        //The algorithm we are using is min of the max of column and row(minimax)
        for(int i=0; i<n; i++){
            vector<int>minimax;
            for(int j=0; j<n; j++){
                int tmp = min(maxr[i], maxc[j]);
                minimax.push_back(tmp);
            }
            res.push_back(minimax);
        }
        //finally, we try to find the diff of the original matrix and the fixed matrix
        int diff = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                diff += res[i][j];
            }
        }
        return diff - sum;
    }
};
//Test case 1
//Input: [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
//Expected: 35
//Test case 2
//Input: [[0,0,0],[0,0,0],[0,0,0]]
//Expected: 0
//Test case 3
//Input: [[1,2,3],[4,5,6],[7,8,9]]
//Expected: 6
