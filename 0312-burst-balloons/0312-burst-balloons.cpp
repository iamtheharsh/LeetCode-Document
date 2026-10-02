class Solution {
public:
    vector<int> arr;
    int dp[301][301];

    int solve(int l,int r){
        if(l>r) return 0;
        
        auto& res = dp[l][r];
        if(res!=(-1)) return res;
        int ans = 0;
        for(int k=l+1;k<r;k++){
            int temp = arr[k]*arr[l]*arr[r] + solve(l,k) + solve(k,r);
            ans = max(ans,temp);
        }
        return  res = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        arr = nums;
        memset(dp,-1,sizeof(dp));
        return solve(0,arr.size()-1);
    }
};