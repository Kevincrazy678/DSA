class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int n = grid.size();
        //Complexity: O(n^2)
        vector<vector<int>>res;
        for(int i=1; i<n-1; i++){
            vector<int>row;
            for(int j=1; j<n-1; j++){
                int tmp = grid[i][j];
                //We try to reach to all of the element around grid[i][j]
                for(int k=0; k<8; k++){
                    tmp = max(tmp, grid[i + dx[k]][j + dy[k]]);
                }
                row.push_back(tmp);
            }
            res.push_back(row);
        }
        return res;
    }
};
//Test case 1
//Input: [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
//Expected: [[9,9],[8,6]]
//Test case 2
//Input: [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
//Expected: [[2,2,2],[2,2,2],[2,2,2]]
//Test case 3
//Input: [[9,8,6,6],[4,4,3,7],[4,2,3,4],[1,1,3,2]]
//Expected: [[9,8],[4,7]]
