class Solution {
public:
    using ll = long long;
    ll mod = 1e9 + 7;
    int n;
    int solve(int i,int state){
        if(i>n) return 0;
        if(i==n){
            if(state==0 || state==3) return 1;
            return 0;
        }
        ll ans = 0;

        if(state==0){
            ans += solve(i+1,0) + solve(i+1,1) + solve(i+1,2) + solve(i+1,3);
        }
        if(state==1){
            ans += solve(i+1,3) + solve(i+1,2);
        }
        if(state ==2){
            ans += solve(i+1,3) + solve(i+1,1); 
        }
        if(state==3){
            ans += solve(i+1,0);
        }
        return ans%mod;
    }
    int numTilings(int n) {
        this->n = n;
        //0,1,2,3
        // return solve(1,0);
        vector<vector<ll>> dp(n+2,vector<ll>(4,0));
        dp[n][0] = dp[n][3] = 1;
        for(int i=n-1;i>=1;i--){
            for(int state = 0;state<4;state++){
                if(state==0){
                    dp[i][state] = (dp[i+1][0] + dp[i+1][1] + dp[i+1][2] + dp[i+1][3])%mod;
                }
                if(state==1){
                    dp[i][state] = (dp[i+1][2] + dp[i+1][3])%mod;
                }
                if(state ==2){
                    dp[i][state]  = (dp[i+1][3] + dp[i+1][1])%mod; 
                }
                if(state==3){
                    dp[i][state]  = dp[i+1][0]%mod;
                }
            }
        }
        return dp[1][0];
    }
};