//link to the problem: https://leetcode.com/problems/sort-matrix-by-diagonals/
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        //time complexity: O(n^2 * logn) + O(n^2) = O(n^2 * logn)
        //space complexity: O(n)
        int n = grid.size();
        //we are sorting the diagonals of the matrix in non-increasing order
        for(int i=0; i<n; i++){
            vector<int>tmp;
            int row = i, col = 0;
            //we are storing the elements of the diagonal in a temporary vector and then sorting it in non-increasing order
            while(row < n && col < n){
                tmp.push_back(grid[row][col]);
                row++;
                col++;
            }
            sort(tmp.begin(), tmp.end(), greater<int>());
            row = i, col = 0;
            //we are storing the sorted elements of the diagonal back in the matrix
            for(int x : tmp){
                grid[row][col] = x;
                row++;
                col++;
            }
        }
        //we are sorting the diagonals of the matrix in non-decreasing order
        for(int j=1; j<n; j++){
            vector<int>tmp;
            int row = 0, col = j;
            //we are storing the elements of the diagonal in a temporary vector and then sorting it in non-decreasing order
            while(row < n && col < n){
                tmp.push_back(grid[row][col]);
                row++;
                col++;
            }
            sort(tmp.begin(), tmp.end());
            row = 0, col = j;
            //we are storing the sorted elements of the diagonal back in the matrix
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