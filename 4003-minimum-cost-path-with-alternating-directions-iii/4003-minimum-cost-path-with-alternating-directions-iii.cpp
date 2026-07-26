class Solution {
public:
    using ll = long long;
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        vector<vector<vector<ll>>> dp(m,vector<vector<ll>>(n,vector<ll>(2,1e16)));
        dp[0][0][0] = 1;
        set<tuple<ll,int,int,int>> st; // cost,r,c,paritu
        st.insert({1,0,0,0});
        int dr[4] = {0,0,-1,1};
        int dc[4] = {-1,1,0,0};
        while(!st.empty()){
            auto [cost,r,c,par] = *(st.begin());
            st.erase({cost,r,c,par});
            if(r==(m-1) && c==(n-1)) return cost;
            if(cost > dp[r][c][par]) continue;

            int np = par^1;
            ll wc = cost + penalty[r][c];
            if(dp[r][c][np]> wc){
                dp[r][c][np] = wc;
                st.insert({wc,r,c,np});
            }
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nc>=0 && nr<m && nc<n){
                    ll go = cost + (nr+1LL)*(nc+1LL);
                    if((np%2)!=(i%2)){
                        go += penalty[r][c];
                    }
                    if(dp[nr][nc][np]>go){
                        dp[nr][nc][np] = go;
                        st.insert({go,nr,nc,np});
                    }
                    
                }
            }
        }
        return -1;
    }
};