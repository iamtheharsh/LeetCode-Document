class Solution {
public:
    vector<vector<int>> mat;
    int m,n,k;
    int dp[255][255];

    bool check(int i,int j){
        for(int r = 0;r<m;r++){
            int diff = abs(mat[r][i] - mat[r][j]);
            if(diff>k) return false;
        }
        return true;
    }

    int solve(int i,int prev){
        if(i>=n) return 0;

        auto& res = dp[i+1][prev+1];
        if(res!=(-1)) return res;
        
        int skip = solve(i+1,prev);
        int take = 0;

        if(prev==(-1) || check(i,prev)){
            take = 1 + solve(i+1,i);
        }
        return res = max(take,skip);
    }

    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        m = grid.size();
        n = grid[0].size();
        mat = grid;
        k = limit;
        
        memset(dp,-1,sizeof(dp));

        return solve(0,-1);
    }
};