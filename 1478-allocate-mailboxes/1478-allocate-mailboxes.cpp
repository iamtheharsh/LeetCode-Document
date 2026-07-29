class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> cost;
    int n,k;

    int solve(int idx,int left){
        if(idx==n && left==0) return 0;
        if(idx==n || left==0) return 1e8;

        int ans = 1e9;
        if(dp[idx][left]!=(-1)) return dp[idx][left];
 
        for(int i=idx;i<n;i++){
            ans = min(ans,cost[idx][i] + solve(i+1,left-1));
        }
        return dp[idx][left] =  ans;
    }

    int minDistance(vector<int>& houses, int k) {
        n = houses.size();
        cost.resize(n,vector<int>(n,0));
        this->k = k;
        sort(houses.begin(),houses.end());

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int mid = (i+j)/2;
                int temp = 0;
                for(int k=i;k<=j;k++){
                    temp += abs(houses[k]-houses[mid]);
                }
                cost[i][j] = temp;
            }
        }
        dp.assign(n, vector<int>(k+1,-1));
        return solve(0,k);
    }
};