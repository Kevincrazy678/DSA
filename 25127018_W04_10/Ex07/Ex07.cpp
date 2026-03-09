https://leetcode.com/problems/sort-the-students-by-their-kth-score/submissions/1937398929/
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
    	//Time Comp: O(n*n), Space Comp: O(n)
        int n = score.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
            	//Sort the students by their scores in the kth exam from the highest to the lowest.
                if(score[i][k] < score[j][k]){
                    swap(score[i], score[j]);	
                }
            }
        }
        return score;
    }
};

//test case 1
//[[10,6,9,1],[7,5,11,2],[4,8,3,15]] 2
//Ans: [[7,5,11,2],[10,6,9,1],[4,8,3,15]]

//test case 2
//[[3,4],[5,6]] 0
//Ans: [[5,6],[3,4]]

//test case 3
//[[2,3,5],[1,8,7],[4,9,6]] 1
//Ans: [[4,9,6],[1,8,7],[2,3,5]]
