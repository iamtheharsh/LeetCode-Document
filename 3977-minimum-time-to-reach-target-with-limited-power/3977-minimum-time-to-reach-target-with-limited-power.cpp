class Solution {
public:
    using ll = long long;
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int src, int dst) {

        vector<vector<pair<ll,ll>>> adj(n);
        for(auto e:edges){
            int u = e[0],v=e[1],w=e[2];
            adj[u].push_back({v,w});
        }

        vector<vector<ll>> dist(n,vector<ll>(power+1,1e18));
        dist[src][power] = 0;
        priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>>> pq;
        pq.push({0,src,power});

        while(!pq.empty()){
            auto [time,u,p] = pq.top();
            pq.pop();
            if(time!= dist[u][p] ) continue;
            if(u==dst) continue;
            if(p<cost[u]) continue;
            
            ll np = p - cost[u];

            for(auto [v,wt] : adj[u]){
                if(dist[v][np]>time + wt){
                    dist[v][np] = time + wt;
                    pq.push({dist[v][np],v,np});
                }
            }
        }
        ll mnt = 1e18 , mxp = -1;
        for(int i=0;i<=power;i++){
            if(dist[dst][i]<mnt){
                mnt = dist[dst][i];
                mxp = i;
            }
            else if(dist[dst][i]==(mnt)){
                mxp = i;
            }
        }
        if(mnt==(1e18)) return {-1,-1};
        return {mnt,mxp};
    }
};