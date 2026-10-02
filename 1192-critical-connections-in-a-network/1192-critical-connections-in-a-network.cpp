class Solution {
public:

    vector<vector<int>> ans,adj;
    vector<int> vis,low;

    void dfs(int u,int p,int time){
        vis[u] = low[u] = time;

        for(auto v:adj[u]){
            if(v==p) continue;
            if(vis[v]==(-1)){
                dfs(v,u,time+1);
                low[u] = min(low[u],low[v]);
                if(low[v]>vis[u]){
                    ans.push_back({u,v});
                }
            }
            else low[u]=min(low[u],low[v]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        for(auto c:connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vis.assign(n, -1);
        low.assign(n, 0);
        dfs(0,-1,0);
        return ans;
    }
};