class Solution {
public:
    using t = tuple<int,int,int>;
    int trapRainWater(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        priority_queue<t,vector<t>,greater<t>> pq;
        for(int i=0;i<m;i++){
            pq.push({h[i][0],i,0});
            vis[i][0] = true;
            pq.push({h[i][n-1],i,n-1});
            vis[i][n-1] = true;
        }
        for(int j=0;j<n;j++){
            if(!vis[0][j]){
                pq.push({h[0][j],0,j});
                vis[0][j] = true;
            }
            if(!vis[m-1][j]){
                pq.push({h[m-1][j],m-1,j});
                vis[m-1][j] = true;
            }
        }
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};

        int ans = 0;

        while(!pq.empty()){
            auto [hgt,r,c] = pq.top();
            pq.pop();
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || vis[nr][nc]) continue;
                vis[nr][nc] = true;
                int nh = h[nr][nc];
                if(hgt>nh) ans += hgt-nh;
                pq.push({max(nh,hgt),nr,nc});
            }
        }
        return ans;
    }
};