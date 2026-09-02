class Solution {
public:
    vector<vector<int>> adj,radj;
    vector<int> ans;

    int dfs(int u,int p){
        int res = 0;
        for(auto& v:adj[u]){
            if(v!=p){
                res += dfs(v,u);
            }
        }
        for(auto& v:radj[u]){
            if(v!=p){
                res += 1 + dfs(v,u);
            }
        }
        return res;
    }

    void dfs2(int u,int p){
        for(auto& v:adj[u]){
            if(v!=p){
                ans[v] = ans[u] + 1;
                dfs2(v,u);
            }
        }
        for(auto& v:radj[u]){
            if(v!=p){
                ans[v] = ans[u] - 1;
                dfs2(v,u);
            }
        }

    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        radj.resize(n);
        ans.resize(n);
        for(auto e:edges){
            int u = e[0],v = e[1];
            adj[u].push_back(v);
            radj[v].push_back(u);
        }
        ans[0] = dfs(0,-1);
        dfs2(0,-1);
        return ans; 
    }
};