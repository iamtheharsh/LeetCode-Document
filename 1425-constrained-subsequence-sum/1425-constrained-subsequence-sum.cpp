class Solution {
public:
    int n,k;
    vector<int> nums;
    int constrainedSubsetSum(vector<int>& nums, int k) {
        this->nums = nums;
        this->k = k;
        n = nums.size();
        vector<int> dp(n);
        for(int i=0;i<n;i++) dp[i] = nums[i];
        deque<int> dq;
        for(int i=0;i<n;i++){
            while(!dq.empty() && i-dq.front()>k) dq.pop_front();
            int temp = 0;
            if(!dq.empty()) temp = max(temp,dp[dq.front()]);
            dp[i] += temp;
            while(!dq.empty() && dp[dq.back()]<=dp[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return *max_element(dp.begin(),dp.end());
    }
};