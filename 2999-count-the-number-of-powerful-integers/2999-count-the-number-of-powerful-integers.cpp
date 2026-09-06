class Solution {
public:
    using ll = long long;
    string s;
    int limit;
    int n;
    ll dp[17][2];

    ll solve(int pos, bool t, string& temp){
        if(pos<0) return 1;
        ll ans = 0;

        auto& res = dp[pos][t];
        if(res!=(-1)) return res;

        int m = temp.size();
        if(n>m) return 0;

        if(pos>=n){
            int lim = t==true? temp[pos]-'0' : 9;
            lim = min(lim,limit);

            for(int i=0;i<=lim;i++){
                bool nt = t && (i==(temp[pos]-'0'));
                ans += solve(pos-1,nt,temp);
            }
        }
        else {
            int bt = s[n-1-pos]-'0';
            int lim = t==true? temp[pos]-'0' : 9;
            if(bt<=lim){
                bool nt = t && (bt==(temp[pos]-'0'));
                ans += solve(pos-1,nt,temp);
            }
        }
        return res= ans;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        this->s = s;
        n = s.size();
        this->limit = limit;

        memset(dp,-1,sizeof(dp));
        string temp = to_string(finish);
        reverse(temp.begin(),temp.end());
        ll res1 = solve(temp.size()-1,1,temp);

        memset(dp,-1,sizeof(dp));
        temp = to_string(start-1);
        reverse(temp.begin(),temp.end());
        ll res2;
        if((start-1)<=0) res2 = 0;
        else res2 = solve(temp.size()-1,1,temp);

        return res1-res2;
    }
};