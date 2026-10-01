class Solution {
public:
    int m,n;
    vector<vector<int>> grid;
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,-1,1};

    bool isValid(int r,int c){
        if(r<0 || r>=m || c<0 || c>=n) return false;
        if(grid[r][c]==0) return false;
        return true;
    }

    int bfs(int sr,int sc,int tr,int tc){
        vector<vector<int>> dp(m,vector<int>(n,1e9));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        dp[sr][sc] = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int r = it.first;
            int c = it.second;

            if(r==tr && c==tc){
                return dp[r][c];
            }

            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(isValid(nr,nc) && dp[nr][nc] == 1e9){
                    dp[nr][nc] = dp[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& f) {
        m = f.size();
        n = f[0].size();
        grid = f;
        vector<tuple<int,int,int>> trees;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(f[i][j]>1) trees.push_back({f[i][j],i,j});
            }
        }
        sort(trees.begin(),trees.end());
        if(f[0][0]==(0)) return -1;
        int lr = 0,lc = 0;
        int ans = 0;

        for(auto [val,r,c]:trees){
            int dist = bfs(lr,lc,r,c);
            lr = r;
            lc = c;
            if(dist==(-1)) return -1;
            ans += dist;
        }
        return ans;
    }
};