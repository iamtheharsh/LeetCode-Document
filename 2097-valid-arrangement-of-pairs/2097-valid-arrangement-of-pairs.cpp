class Solution {
public:
    unordered_map<int,int> indg,outdg;
    unordered_map<int,vector<int>> adj;
    set<int> vis;
    set<int> vertices;
    vector<vector<int>> ans;

    void dfs(int u){
        while(adj[u].size()){
            int v = adj[u].back();
            adj[u].pop_back();
            dfs(v);
            ans.push_back({u,v});
        }
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();

        for(auto p:pairs){
            indg[p[1]]++;
            outdg[p[0]]++;
            adj[p[0]].push_back(p[1]);
            vertices.insert(p[0]);
            vertices.insert(p[1]);
        }

        bool flag = false;

        for(auto u:vertices){
            if(outdg[u]-indg[u]==1){
                dfs(u);
                flag = true;
                break;
            }
        }

        if(!flag){
            dfs(pairs[0][0]);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};