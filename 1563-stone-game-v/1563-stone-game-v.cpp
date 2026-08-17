class Solution {
public:
    vector<int> pref;
    int n;
    int dp[501][501];
    int getSum(int l,int r){
        if(l==0) return pref[r];
        return pref[r] - pref[l-1];
    }

    int solve(int l,int r){
        if(l==r) return 0;
        int res = 0;
        auto& bt = dp[l][r];
        if(bt!=(-1)) return bt;
        for(int k=l+1;k<=r;k++){
            int left = getSum(l,k-1);
            int right = getSum(k,r);
            int ans;
            if(left>right){
                ans = right + solve(k,r);
            }
            else if(right>left){
                ans = left + solve(l,k-1);
            }
            else {
                ans = left + max(solve(k,r),solve(l,k-1));
            }
            res = max(res,ans);
        }
        return bt = res;
    }
    int stoneGameV(vector<int>& sv) {
        n = sv.size();
        pref.resize(n);
        pref[0] = sv[0];

        for (int i=1;i<n;i++) {
            pref[i] = pref[i-1] + sv[i];
        }
        memset(dp,-1,sizeof(dp));

        return solve(0,n-1);
    }
};