class Solution {
public:
    int n;
    vector<int> jd;
    int dp[300][1001][11];

    int solve(int i, int cm, int k){
        if(i == n){
            if(k == 0) return cm;
            return 1e6;
        }
        if(k < 0) return 1e6;
        auto& res = dp[i][cm][k];
        if(res!=(-1)) return res;
        int take = solve(i + 1, max(cm, jd[i]), k);
        int skip = 1e6;
        if(k >= 1){
            skip = cm + solve(i + 1, jd[i], k - 1);
        }

        return res =  min(take, skip);
    }

    int minDifficulty(vector<int>& jd, int d) {
        this->jd = jd;
        n = jd.size();
        if(d > n) return -1;
        memset(dp,-1,sizeof(dp));
        return solve(1, jd[0], d - 1);
    }
};