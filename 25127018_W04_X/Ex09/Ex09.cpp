//link to the problem: https://leetcode.com/problems/magnetic-force-between-two-balls
class Solution {
public:
    bool check(vector<int>& position, int m, int mid){
        int cnt = 1, last_p = position[0];
        //we are checking if we can place m balls in the array with a distance of mid between them
        for(int i=1; i<position.size(); i++){
            //if the distance between two balls is greater than or equal to mid, then we can place m balls in the array
            if(position[i] - last_p >= mid){
                last_p = position[i];
                cnt++;
                if(cnt >= m)return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        //time complexity: O(nlogn) + O(nlog(max-min)) = O(nlogn)
        //space complexity: O(1)
        sort(position.begin(), position.end());
        int right = 1, left = position.back() - position[0], res = 1;
        while(right <= left){
            //we are using binary search to find the maximum distance between two balls
            int mid = right + (left - right)/2;
            //if the distance between two balls is greater than or equal to mid, then we can place m balls in the array
            if(check(position, m, mid)){
                res = mid;
                right = mid + 1;
            }
            //if the distance between two balls is less than mid, then we cannot place m balls in the array
            else{
                left = mid - 1;
            }
        }
        return res;
    }
};

//test case 1: arranged in increasing order
//[1,2,3,4,7] 3
//Ans: 3

//test case 2: having a large number in the array and arranged in decreasing order
//[5,4,3,2,1,1000000000] 2
//Ans: 999999999

//test case 3: not arranged in increasing order and having a large number in the array
//[1,10,5,3,8] 3
//Ans: 4
