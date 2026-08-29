class DisjointSet{
    vector<int> parent,size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i] = i;
    }

    int find(int u){
        if(u==parent[u]) return u;
        return parent[u] =find(parent[u]);
    }

    void unite(int u,int v){
        int pu = find(u);
        int pv = find(v);
        if(pu==pv) return;
        else if(size[pu]>=size[pv]){
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        else{
            size[pv] += size[pu];
            parent[pu] = pv;
        }
    }
};
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        DisjointSet ds(n);
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        for(int i=1;i<n;i++){
            int diff = v[i].first - v[i-1].first;
            if(diff<=limit){
                ds.unite(v[i].second,v[i-1].second);
            }
        }
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            int up = ds.find(i);
            mpp[up].push_back(i);
        }
        for(auto it:mpp){
            auto& temp = it.second;
            vector<int> bt;
            for(int i=0;i<temp.size();i++){
                bt.push_back(nums[temp[i]]);
            }
            sort(bt.begin(),bt.end());
            for(int i=0;i<temp.size();i++){
                int idx = temp[i];
                nums[idx] = bt[i];
            }
        }
        return nums;
    }
};