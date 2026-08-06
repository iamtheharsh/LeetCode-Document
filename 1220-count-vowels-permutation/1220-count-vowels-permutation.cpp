class Solution {
public:
    using ll = long long;
    ll mod = 1e9 + 7;
    int n;
    int dp[20000+2][5];

    int get(char c){
        if(c=='a') return 0;
        if(c=='e') return 1;
        if(c=='i') return 2;
        if(c=='o') return 3;
        return 4; 
    }
    ll solve(int i, char last) {
        if (i==n) return 1;

        int num = get(last);
        if (dp[i][num]!= -1) return dp[i][num];

        ll ans = 0;
        if (last=='a') {
            ans = solve(i + 1, 'e');
        }
        else if(last=='e'){
            ans = (solve(i+1,'a') + solve(i+1,'i'))% mod;
        }
        else if(last=='i'){
            ans = (solve(i+1,'a') +solve(i+1,'e') +solve(i+1,'o') +solve(i+1,'u')) % mod;
        }
        else if (last == 'o') {
            ans = (solve(i+1,'i') + solve(i+1,'u')) % mod;
        }
        else {
            ans = solve(i+1,'a');
        }

        return dp[i][num] = ans%mod;
    }
    int countVowelPermutation(int n) {
        this->n = n;
        if(n==1) return 5;
        memset(dp,-1,sizeof(dp));
        ll ans = 0;
        ans = (solve(1,'a') +solve(1,'e') + solve(1,'i') + solve(1,'o') + solve(1,'u')) % mod;
        return ans;
    }
};