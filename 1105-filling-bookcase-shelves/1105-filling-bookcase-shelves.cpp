class Solution {
public:
    vector<vector<int>> books;
    int n;
    int sw;
    int dp[1001];
    int solve(int i){
        if(i>=n) return 0;
        int mx = 0;
        int curr = 0;
        int ans = INT_MAX;
        if(dp[i]!=(-1)) return dp[i];
        for(int j =i;j<n;j++){
            int w = books[j][0];
            int h = books[j][1];
            if((curr+w)<=sw){
                curr += w;
                mx = max(mx,h);
            }
            else break;
            ans = min(ans,mx + solve(j+1));
        }
        return dp[i] =  ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int sww) {
        sw = sww;
        this->books = books;
        n = books.size();
        memset(dp,-1,sizeof(dp));
        return solve(0);
    }
};