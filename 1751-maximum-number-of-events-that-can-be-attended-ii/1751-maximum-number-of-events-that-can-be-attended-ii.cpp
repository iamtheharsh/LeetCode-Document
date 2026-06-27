class Solution {
public:
    vector<vector<int>> events;
    int k,n;
    vector<vector<int>> dp;

    int getIdx(int i){
        vector<int> temp = {events[i][1] + 1, 0, 0};
        return lower_bound(events.begin(), events.end(), temp) - events.begin();
    }

    int solve(int i,int k){
        if(k==0) return 0;
        if(i>=n) return 0;
        auto &res = dp[i][k];
        if(res!=(-1)) return res;
        int skip = solve(i+1,k);
        int idx = getIdx(i); 
        int take = events[i][2] + solve(idx,k-1);
        return dp[i][k] =  max(skip,take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        this->events = events;
        this->k = k;
        n = events.size();
        dp.assign(n,vector<int>(k+1,-1));
        sort(this->events.begin(),this->events.end());
        return solve(0,k);
    }
};