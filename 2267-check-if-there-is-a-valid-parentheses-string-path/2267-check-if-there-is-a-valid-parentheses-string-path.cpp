class Solution {
public:
    vector<vector<int>> mat;
    int m,n;
    int dp[101][101][203];
    
    bool solve(int i,int j,int curr){
        if(i>=m || j>=n){
            return false;
        }
        
        curr += mat[i][j];
        if(curr<0) return false;
        auto& key = dp[i][j][curr];
        if(key!=(-1)) return key;

        if(i==(m-1) && j==(n-1)) {
            return curr==0;
        }

        bool ans = false;
        bool right = solve(i,j+1,curr);
        bool down = solve(i+1,j,curr);
        ans = ans | right;
        ans = ans | down;

        return key = ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        mat.resize(m,vector<int>(n));
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='(') mat[i][j] = 1;
                else mat[i][j] = -1;
            }
        }

        if(grid[0][0]==')' || grid[m-1][n-1]=='(') return false;
        return solve(0,0,0);
    }
};