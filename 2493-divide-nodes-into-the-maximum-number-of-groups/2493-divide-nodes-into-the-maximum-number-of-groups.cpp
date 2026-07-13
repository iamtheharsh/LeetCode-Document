class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<int>> components;

    bool dfs(vector<int>& vis,int i,vector<int>& color,int pvs,vector<int>& compo){
        vis[i] = 1;
        compo.push_back(i);

        if(pvs==-1) color[i] = 0;
        if(pvs==0) color[i] = 1;
        else if(pvs==1) color[i] = 0;

        int curr = color[i];

        for(int j=0;j<adj[i].size();j++){
            int nbr = adj[i][j];

            if(color[nbr]!=-1){
                if(curr==color[nbr]) return false;
            }
            else{
                if(!dfs(vis,nbr,color,curr,compo)) return false;
            }
        }
        return true;
    }

    bool isBipartite(int n){
        vector<int> vis(n,0);
        vector<int> color(n,-1);

        for(int i=1;i<n;i++){
            if(!vis[i]){
                vector<int> compo;

                if(!dfs(vis,i,color,-1,compo))
                    return false;

                components.push_back(compo);
            }
        }
        return true;
    }

    int bfs(int src,int n){
        queue<int> q;
        vector<int> dist(n,-1);
        q.push(src);
        dist[src]=1;
        int mx=1;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(int nbr:adj[node]){
                if(dist[nbr]==-1){
                    dist[nbr]=dist[node]+1;
                    mx=max(mx,dist[nbr]);
                    q.push(nbr);
                }
            }
        }
        return mx;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        n++;
        adj.resize(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        if(!isBipartite(n)) return -1;
        int ans=0;

        for(auto &compo:components){
            int best=0;
            for(int node:compo){
                best=max(best,bfs(node,n));
            }
            ans+=best;
        }
        return ans;
    }
};