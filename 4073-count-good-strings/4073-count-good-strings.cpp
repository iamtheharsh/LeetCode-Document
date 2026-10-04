class Solution {
public:
    using ll = long long;
    ll mod = 1e9 + 7;

    pair<ll,ll> solve(ll n){
        if(n==0) return {0,1};
        auto temp = solve(n/2);
        ll a = temp.first;
        ll b = temp.second;
        ll aa = (a*(((2*b)%mod - a+mod)%mod))%mod;
        ll bb = ((a*a)%mod + (b*b)%mod)%mod;

        if(n%2==0) return {aa,bb};
        return {bb,(aa+bb)%mod};
    }

    int countGoodStrings(long long n) {
        if(n==1) return 2;
        return (2LL*solve(n).first)%mod;
    }
};