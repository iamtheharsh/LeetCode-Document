class Solution {
public:
    using ll = long long;
    ll mod = 1e9 + 7;
    vector<int> nums;
    int n;
    ll dp[100005][3][4];
    
    ll solve(int i,int lp,int k){
        if(k==0) return 0;
        if(i>=n) return 1;
        auto& res = dp[i][lp+1][k];
        if(res!=(-1)) return res;
        int skip = solve(i+1,lp,k);
        int take = 0;
        int cp = nums[i]%2;
        if(cp==lp){
            take = solve(i+1,cp,k-1);
        }
        else {
            take = solve(i+1,cp,2);
        }
        return res = (skip + take)%mod;
    }
    int countStableSubsequences(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,3)-1;
    }
};