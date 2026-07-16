class Solution {
public:
    using ll = long long;

    vector<vector<int>> adj;
    vector<int> vals;
    vector<ll> down;
    ll ans;

    ll dfs1(int u, int p) {
        ll temp = 0;

        for (auto v : adj[u]) {
            if (v == p) continue;
            temp = max(temp, dfs1(v, u));
        }

        return down[u] = vals[u] + temp;
    }

    void dfs2(int u, int p, ll up) {
        ans = max({ans, up, down[u] - (ll)vals[u]});

        ll mx1 = 0, mx2 = 0;

        for (auto v : adj[u]) {
            if (v == p) continue;

            if (down[v] > mx1) {
                mx2 = mx1;
                mx1 = down[v];
            } else if (down[v] > mx2) {
                mx2 = down[v];
            }
        }

        for (auto v : adj[u]) {
            if (v == p) continue;

            ll best = (down[v] == mx1 ? mx2 : mx1);
            ll newUp = vals[u] + max(up, best);

            dfs2(v, u, newUp);
        }
    }

    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        adj.assign(n, {});
        vals = price;
        down.assign(n, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        ans = 0;

        dfs1(0, -1);
        dfs2(0, -1, 0);

        return ans;
    }
};