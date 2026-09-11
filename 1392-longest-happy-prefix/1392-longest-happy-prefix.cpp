class Solution {
public:
    using ll = long long;
    ll mod = 1e9 + 7;
    ll base = 211;
    vector<ll> power,pref;

    ll getHash(int l,int r){
        return (pref[r] -(pref[l-1]*power[r-l+1])%mod + mod)%mod; 
    }
    string longestPrefix(string s) {
        int n = s.size();
        power.resize(n+1,1);
        pref.resize(n+1,0);

        for(int i=1;i<=n;i++){
            power[i] = (power[i-1]*base)%mod;
            int val = s[i-1]-'a' + 1; 
            pref[i] = (pref[i-1]*base + val)%mod;
        }

        for(int len = n-1;len>=1;len--){
            int h1 = getHash(1,len);
            int h2 = getHash(n-len+1,n);
            if(h1==h2) {
                return s.substr(0,len);
            }
        }
        return "";
    }
};