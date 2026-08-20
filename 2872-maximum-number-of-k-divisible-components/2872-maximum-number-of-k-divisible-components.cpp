class Solution {
public:
    using ll = long long;
    int ans = 0;
    vector<vector<int>> adj;
    vector<ll > sum;
    vector<int> values;

    ll dfs1(int u,int p){
        sum[u] = values[u];
        for(auto v:adj[u]){
            if(v!=p){
                sum[u] += dfs1(v,u);
            }
        }
        return sum[u];
    }

    void dfs2(int u,int p,int k){
        for(auto& v:adj[u]){
            if(v==p) continue;
            dfs2(v,u,k);
            if(sum[v]%k==0) ans++;
        }
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj.assign(n, {});
        sum.assign(n, 0);
        ans = 0;
        this->values = values;

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs1(0,-1);
        if(sum[0]%k!=0) return 1;
        dfs2(0,-1,k);
        return ans+1;
    }
};