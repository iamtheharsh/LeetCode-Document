class Solution {
public:
    vector<int> days,costs;
    int n;
    int dp[370];

    int solve(int i){
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for(int j=0;j<3;j++){
            int cost = costs[j];
            int day;
            if(j==0) day = 1;
            else if(j==1) day = 7;
            else day = 30;
            int idx = lower_bound(days.begin(),days.end(),days[i]+day) - days.begin();
            int temp = cost + solve(idx);
            ans = min(ans,temp);
        }
        return dp[i] =  ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->days = days;
        this->costs = costs;
        memset(dp,-1,sizeof(dp));
        n = days.size();
        return solve(0);
    }
};