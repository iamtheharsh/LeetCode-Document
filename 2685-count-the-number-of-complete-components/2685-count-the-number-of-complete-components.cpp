class DisjointSet{
    vector<int> sz,parent;
    public:
    DisjointSet(int n){
        sz.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findUP(int u){
        if(u==parent[u]) return u;
        return parent[u] = findUP(parent[u]);
    }
    void unionBySize(int u,int v){
        int pu = findUP(u);
        int pv = findUP(v);
        if(pu==pv) return;
        else if(sz[pu]>=sz[pv]){
            sz[pu] += sz[pv];
            parent[pv] = pu; 
        }
        else {
            sz[pv] += sz[pu];
            parent[pu] = pv; 
        }
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        map<pair<int,int>,int> mpp;
        unordered_map<int,vector<int>> temp;
        for(auto e:edges){
            ds.unionBySize(e[0],e[1]);
            mpp[{e[0],e[1]}]++;
            mpp[{e[1],e[0]}]++;
        }
        for(int i=0;i<n;i++){
            int pu = ds.findUP(i);
            temp[pu].push_back(i);
        }
        int ans = 0;
        for(auto& it:temp){
            auto& v = it.second;
            if(v.size()==1) {
                ans++;
                continue;
            }
            int m = v.size();
            bool flag = true;
            for(int i=0;i<m;i++){
                if(!flag) break;
                for(int j=i+1;j<m;j++){
                    if(mpp.find({v[i],v[j]})!=mpp.end() || mpp.find({v[j],v[i]})!=mpp.end()) continue;
                    else {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};