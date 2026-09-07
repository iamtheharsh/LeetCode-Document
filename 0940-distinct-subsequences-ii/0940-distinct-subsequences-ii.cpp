class Solution {
public:
    using ll = long long;
    ll mod = 1e9+ 7;
    int distinctSubseqII(string s) {
        ll ans = 0;
        vector<ll> freq(26,0);
        for(auto c:s){
            freq[c-'a'] = accumulate(freq.begin(),freq.end(),1LL)%mod;
        }
        ans = accumulate(freq.begin(),freq.end(),0LL)%mod;
        return ans;
    }
};