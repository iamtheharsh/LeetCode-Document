class Solution {
public:
    using ll = long long;
    ll mod = 1e9 + 7;
    vector<vector<int>> v;
    int n,m;
    string target;
    vector<string> words;
    int dp[1001][1001];

    ll solve(int i,int j){
        if(j>=target.size()) return 1;
        if(i>=n) return 0;

        auto& res = dp[i][j];
        if(res!=(-1)) return res;
        ll ans = solve(i+1,j);

        int c = target[j]-'a';
        ans += 1LL*v[c][i]*solve(i+1,j+1);
        ans %= mod;

        return res= ans;
    }

    int numWays(vector<string>& words, string target) {
        this->words = words;
        this->target = target;
        m = words.size();
        n = words[0].size();

        v.assign(26,vector<int>(n,0));
        memset(dp,-1,sizeof(dp));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int w = words[j][i]-'a';
                v[w][i]++;
            }
        }


        return solve(0,0);
    }
};