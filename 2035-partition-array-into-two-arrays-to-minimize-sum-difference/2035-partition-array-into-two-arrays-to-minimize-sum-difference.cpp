class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int m = n/2;
        vector<vector<int>> dp1(m+1),dp2(m+1);

        for (int mask=0;mask<(1<<m);mask++) {
            int sum1 = 0, sum2 = 0;
            int cnt = __builtin_popcount(mask);
            for (int i=0;i<m;i++) {
                if (mask&(1<<i)) {
                    sum1 += nums[i];
                    sum2 += nums[i + m];
                }
            }
            dp1[cnt].push_back(sum1);
            dp2[cnt].push_back(sum2);
        }

        int total = accumulate(nums.begin(), nums.end(),0);
        int ans = INT_MAX;
        for(int i=0;i<=m;i++){
            sort(dp2[i].begin(),dp2[i].end());
        }

        for (int k=0;k<=m;k++) {
            auto &a = dp1[k];
            auto &b = dp2[m-k];

            for (auto x:a) {
                int need = total/2 - x;
                auto idx = lower_bound(b.begin(),b.end(),need) - b.begin();
                if(idx!=b.size()) {
                    int bt = x + b[idx];
                    ans = min(ans, abs(total-2*bt));
                }
                if(idx!=0){
                    idx--;
                    int bt = x + b[idx];
                    ans = min(ans,abs(total-2*bt));
                }

            }
        }

        return ans;
    }
};