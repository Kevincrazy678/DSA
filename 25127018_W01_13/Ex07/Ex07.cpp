class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for(auto x : operations){
            if(x[0] == '+' || x[2] == '+')res++;
            else if(x[0] == '-' || x[2] == '-')res--;
        }
        return res;
    }
};
