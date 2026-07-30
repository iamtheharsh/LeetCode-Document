class Solution {
public:
    using ll = long long;

    const int mod = 1e9+7;
    int fact[200006];

    void compute() {
        fact[0] = 1;
        for (int i=1;i<200006;i++) fact[i] = (1LL*fact[i-1]*i) % mod;
    }

    ll modpow(ll base,ll exp) {
        ll res = 1;
        while (exp){
            if (exp&1) res = (res*base)%mod;
            base = (base*base)%mod;
            exp /= 2;
        }
        return res;
    }

    ll modInverse(ll num) {
        return modpow(num,mod-2);
    }

    ll findncr(ll n, ll r) {
        if (r < 0 || r > n) return 0;

        ll num = fact[n];
        ll den = (modInverse(fact[r]) * modInverse(fact[n - r])) % mod;
        return (num * den) % mod;
    }

    int countKSubsequencesWithMaxBeauty(string s, int k) {
        compute();

        unordered_map<char,int> freq;
        for (auto c:s) freq[c]++;

        if (k>freq.size()) return 0;

        vector<int> v;
        for (auto it : freq) v.push_back(it.second);

        sort(v.begin(),v.end(),greater<int>());

        ll ans = 1;
        int threshold = v[k-1];
        int bigger = 0;
        int equal = 0;
        int need = 0;

        for (auto x:v) {
            if (x>threshold) {
                ans = (ans * x) % mod;
                bigger++;
            } else if (x==threshold) {
                equal++;
            }
        }

        need = k-bigger;

        for (int i=0;i<need;i++)
            ans = (ans * threshold) % mod;

        ans = (ans * findncr(equal, need)) % mod;

        return ans;
    }
};