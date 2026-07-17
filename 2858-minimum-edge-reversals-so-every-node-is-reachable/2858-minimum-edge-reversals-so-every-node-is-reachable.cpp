class Solution {
public:
    vector<set<int>> adj,radj;
    vector<int> down,ans;
    
    void dfs1(int u, int p) {
        down[u] = 0;
        for(auto v:adj[u]){
            if(v==p) continue;
            dfs1(v,u);
            down[u] += down[v];
        }
        for(auto v:radj[u]){
            if(v==p) continue;
            dfs1(v,u);
            down[u] += down[v]+1;
        }
    }

    void dfs2(int u, int p) {
        for(auto v:adj[u]){
            if(v==p) continue;
            ans[v] = ans[u]+1;
            dfs2(v,u);
        }
        for(auto v:radj[u]){
            if(v==p) continue;
            ans[v] = ans[u]-1;
            dfs2(v,u);
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        radj.resize(n);
        for(auto e:edges){
            int u = e[0], v = e[1];
            adj[u].insert(v);
            radj[v].insert(u);
        }
        down.resize(n,0);
        ans.resize(n,0);
        dfs1(0,-1);
        ans[0] = down[0];
        dfs2(0,-1);
        return ans;
    }
};
