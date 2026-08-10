class Solution {
public:
    vector<int> nums;
    int n;
    vector<vector<int>> dp;

    int solve(int i, int j) {
        if(j>=n) return nums[i]; 
        
        if(j==n-1) {
            return max(nums[i],nums[j]);
        }
        
        if(dp[i][j]!=-1) return dp[i][j];

        int k = j + 1;

        int t12 = max(nums[i],nums[j]) + solve(k,k + 1);
        int t13 = max(nums[i],nums[k]) + solve(j,k + 1);
        int t23 = max(nums[j],nums[k]) + solve(i,k + 1);

        return dp[i][j] = min({t12, t13, t23}); 
    }

    int minCost(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        dp.assign(n + 1, vector<int>(n + 1, -1)); 
        if(n == 1) {
            return nums[0];
        }
        if(n==2) {
            return max(nums[0], nums[1]);
        }
        return solve(0,1);
    }
};