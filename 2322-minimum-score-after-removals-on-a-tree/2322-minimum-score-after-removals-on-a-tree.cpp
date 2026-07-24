class Solution {
public:
    int n,m;
    vector<vector<int>> adj;
    vector<int> xrs;
    vector<int> nums,tin,tout;
    int ans,time;

    void dfs(int u,int p){
        xrs[u] = nums[u];
        time++;
        tin[u] = time;
        for(auto v:adj[u]){
            if(v==p) continue;
            dfs(v,u);
            xrs[u] = xrs[u]^xrs[v];
        }
        tout[u] = time;
    }

    void calc(int x1,int x2,int x3){
        vector<int> temp = {x1,x2,x3};
        sort(temp.begin(),temp.end());
        ans = min(ans,temp[2]-temp[0]);
    }

    bool isAncestor(int a,int b){
        return tin[a]<=tin[b] && tout[b]<=tout[a];
    }

    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        adj.resize(n);
        xrs.resize(n);
        tin.resize(n);
        tout.resize(n);
        ans = 1e9;
        this->nums = nums;
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        time = 0;
        dfs(0,-1);
        m = edges.size();
        
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                int total = xrs[0];
                if(isAncestor(i,j)){
                    calc(xrs[j], xrs[i]^xrs[j], total^xrs[i]);
                } else if(isAncestor(j,i)){
                    calc(xrs[i], xrs[j]^xrs[i], total^xrs[j]);
                } else {
                    calc(xrs[i], xrs[j], total^xrs[i]^xrs[j]);
                }
            }
        }
        return ans;
    }
};