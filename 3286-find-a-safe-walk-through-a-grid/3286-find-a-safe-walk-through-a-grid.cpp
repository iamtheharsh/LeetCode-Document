typedef tuple<int, int, int> iii;
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size() , n = grid[0].size();
        priority_queue<iii,vector<iii> , greater<iii>> pq;
        pq.push({grid[0][0],0,0});

        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        dp[0][0] = grid[0][0];

        while(!pq.empty()){
            auto [curr,r,c] = pq.top();
            pq.pop();
            if(curr>dp[r][c]) continue;

            for(int i=0;i<4;i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(nr>=0 && nc>=0 && nr<m && nc<n){
                    if((curr + grid[nr][nc]) < dp[nr][nc]){
                        dp[nr][nc] = curr + grid[nr][nc];
                        pq.push({dp[nr][nc],nr,nc});
                    }
                }
            }
        }

        return health > dp[m-1][n-1];

    }
};