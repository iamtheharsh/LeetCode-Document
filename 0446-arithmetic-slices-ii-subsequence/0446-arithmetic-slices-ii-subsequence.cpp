class Solution {
public:
    using ll = long long ;
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<ll,ll>> dp(n);
        ll ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                ll diff = 1LL*nums[i]-1LL*nums[j];
                if(diff>INT_MAX || diff<INT_MIN) continue;
                dp[i][diff] += 1;
                if(dp[j].count(diff)) {
                    dp[i][diff] += dp[j][diff];
                    ans += dp[j][diff];
                }
            }
        }
        return ans;  
    }
};