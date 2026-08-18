class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xr = 0;
        for(auto& num:arr2){
            xr= xr^num;
        }
        int ans = 0;
        for(auto& num:arr1){
            int temp = num&(xr);
            ans = ans^temp;
        }
        return ans;
    }
};