//link to the problem: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
class Solution {
public:
    bool check(vector<int>&weights, int days, int mid){
        int cnt = 1, cur = 0;
        //we are checking if we can ship all the packages within days with a capacity of mid
        for(auto w : weights){
            if(cur + w > mid){
                cnt++;
                cur = w;
            }
            else{
                cur += w;
            }
        }
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        //time complexity: O(nlog(sum of weights - max weight)) = O(nlogn)
        //space complexity: O(1)
        int low = 0, high = 0;
        //we are using binary search to find the minimum capacity of the ship that can ship all the packages within days
        for(auto w : weights){
            low = max(low, w);
            high += w;
        }
        int res = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            //if the capacity of the ship is greater than or equal to mid, then we can ship all the packages within days
            if(check(weights, days, mid)){
                res = mid;
                high = mid - 1;
            }
            //if the capacity of the ship is less than mid, then we cannot ship all the packages within days
            else{
                low = mid + 1;
            }
        }
        return res;
    }
};

//test case 1: arranged in increasing order
//[1,2,3,4,5,6,7,8,9,10] 5
//Ans: 15

//test case 2: having a large number in the array and arranged in decreasing order
//[3,2,2,4,1,4] 3
//Ans: 6

//test case 3: not arranged in increasing order and having a large number in the array
//[1,2,3,1,1] 4
//Ans: 3