class Solution {
public:
    vector<vector<int>> mat;
    vector<vector<int>> vis;
    vector<vector<int>> deg;
    int m,n;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    void dfs(int i,int j){
        vis[i][j] = 1;
        for(int k=0;k<4;k++){
            int x = i+dx[k];
            int y = j+dy[k];
            if(x>=0 && x<m && y>=0 && y<n && mat[x][y]>mat[i][j]){
                if(!vis[x][y]){
                    dfs(x,y);
                }
                deg[x][y]++;
            }
        }
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        this->mat = mat;
        vis = vector<vector<int>>(m,vector<int>(n,0));
        deg = vector<vector<int>>(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    dfs(i,j);
                }
            }
        }
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(deg[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            ans++;
            for(int i=0;i<sz;i++){
                auto [x,y] = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && mat[nx][ny]>mat[x][y]){
                        deg[nx][ny]--;
                        if(deg[nx][ny]==0){
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
        return ans;
    }
};