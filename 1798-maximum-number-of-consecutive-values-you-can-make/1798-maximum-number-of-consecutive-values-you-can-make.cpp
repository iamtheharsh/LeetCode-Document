class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int curr = 0;
        for(int i=0;i<coins.size();i++){
            int num = coins[i];
            if(num>(curr+1)) return curr+1;
            else curr = curr + num;
        }
        return curr+1;
    }
};