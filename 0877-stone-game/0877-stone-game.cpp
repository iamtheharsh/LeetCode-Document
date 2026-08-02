class Solution {
public:
    int n;
    vector<int> p;
    int dp[501][501];
    int solve(int i,int j){
        if(i==j) return p[i];
        if(dp[i][j]!=(-1)) return dp[i][j];
        int right = p[i] - solve(i+1,j);
        int left = p [j] - solve(i,j-1);
        return dp[i][j] =  max(right,left);
    }
    bool stoneGame(vector<int>& piles) {
        p = piles;
        memset(dp,-1,sizeof(dp));
        n = p.size();
        return solve(0,n-1) >= 0;
    }
};