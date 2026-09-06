class Solution {
public:
    int n,m;
    string s,t;
    int dp[1000][1000];

    int solve(int i,int j){
        if(j<0) return 1;
        if(i<0) return 0;
        int ans = 0;
        auto& res = dp[i][j];
        if(res!=(-1)) return res;
        if(s[i]==t[j]){
            ans += solve(i-1,j-1);
        }
        ans += solve(i-1,j);
        return res = ans;
    }
    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();
        this->s = s;
        this->t = t;
        memset(dp,-1,sizeof(dp));
        return solve(n-1,m-1);
    }
};