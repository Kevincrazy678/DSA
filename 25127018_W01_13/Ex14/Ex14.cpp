class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size();
        //Complexity: O(n^2)
        //we use bubble sort to sort the student according to the k integer
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(score[i][k] < score[j][k]){
                    swap(score[i], score[j]);
                }
            }
        }
        return score;
    }
};
//Test case 1
//Input: [[10,6,9,1],[7,5,11,2],[4,8,3,15]], k = 2
//Expected: [[7,5,11,2],[10,6,9,1],[4,8,3,15]]
//Test case 2
//Input: [[3,4],[5,6]], k = 0
//Expected: [[5,6],[3,4]]
//Test case 3
//Input: [[9,3],[7,8]], k = 1
//Expected: [[7,8],[9,3]]

