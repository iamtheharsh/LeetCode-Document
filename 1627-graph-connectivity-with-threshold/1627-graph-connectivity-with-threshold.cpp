
class DisjointSet {
private:
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DisjointSet ds(n);
        unordered_map<int,vector<int>> mpp;
        for(int i=threshold+1;i<=n;i++){
            for(int j=i;j<=n;j+=i){
                mpp[i].push_back(j);
            }
        }
        for(auto& it:mpp){
            auto& temp = it.second;
            int m = temp.size();
            for(int i=1;i<m;i++){
                int u = temp[0],v= temp[i];
                ds.unionBySize(u,v);
            }
        }
        vector<bool> ans;
        for(auto& q:queries){
            int u = q[0];
            int v = q[1];
            ans.push_back(ds.findUPar(u)==ds.findUPar(v));
        }
        return ans;
    }
};