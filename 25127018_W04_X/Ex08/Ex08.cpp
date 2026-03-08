//link to the problem: https://leetcode.com/problems/sort-matrix-by-diagonals/
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=0; i<n; i++){
            vector<int>tmp;
            int row = i, col = 0;
            while(row < n && col < n){
                tmp.push_back(grid[row][col]);
                row++;
                col++;
            }
            sort(tmp.begin(), tmp.end(), greater<int>());
            row = i, col = 0;
            for(int x : tmp){
                grid[row][col] = x;
                row++;
                col++;
            }
        }
        for(int j=1; j<n; j++){
            vector<int>tmp;
            int row = 0, col = j;
            while(row < n && col < n){
                tmp.push_back(grid[row][col]);
                row++;
                col++;
            }
            sort(tmp.begin(), tmp.end());
            row = 0, col = j;
            for(int x : tmp){
                grid[row][col] = x;
                row++;
                col++;
            }
        }
        return grid;
    }
};

//test case 1: not normally arranged
//[[1,7,3],[9,8,2],[4,5,6]]
//Ans: [[8,2,3],[9,6,7],[4,5,1]]

//test case 2: not normally arranged
//[[0,1],[1,2]]
//Ans: [[2,1],[1,0]]

//test case 3: only one element in the matrix
//[[1]]
//Ans: [[1]]