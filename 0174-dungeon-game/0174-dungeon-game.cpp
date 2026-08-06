class Solution {
public:
    vector<vector<int>> mat;
    int m,n;

    bool check(int mid){
        vector<vector<int>> dp(m,vector<int>(n,INT_MIN));

        if(mid+mat[0][0]<=0) return false;
        dp[0][0] = mid + mat[0][0];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]<=0) continue;

                if(i+1<m){
                    int nxt = dp[i][j] + mat[i+1][j];
                    if(nxt>0)
                        dp[i+1][j] = max(dp[i+1][j],nxt);
                }

                if(j+1<n){
                    int nxt = dp[i][j] + mat[i][j+1];
                    if(nxt>0)
                        dp[i][j+1] = max(dp[i][j+1],nxt);
                }
            }
        }
        return dp[m-1][n-1]>0;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        mat = dungeon;
        m = mat.size();
        n = mat[0].size();
        int l = 1, h = 1e9;
        int ans = h;
        while(l<=h){
            int m = l + (h-l)/2;
            if(check(m)){
                ans = m;
                h = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};