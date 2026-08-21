class Solution {
public:
    using ll = long long;
    vector<int> coins;
    int n,k;

    bool check(ll mid){
        ll ans = 0;

        for(int mask = 1;mask<(1<<n);mask++){
            int cnt = 0;
            ll lcm = 1;

            for(int i=0;i<n;i++){
                if(!(mask&(1<<i))) continue;
                cnt++;
                ll g = gcd(1LL*coins[i],lcm);
                lcm = (lcm/g)*coins[i];
                if(lcm>mid) break;
            }
            if(lcm>mid) continue;
            ll temp = mid/lcm;
            if(cnt%2) ans += temp;
            else ans -= temp;
        }
        
        return ans>=k;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        this->coins = coins;
        this->k = k;
        n = coins.size();
        ll l = 1, h = 1LL*k*coins[0];
        ll ans = h;
        while(l<=h){
            ll mid = l + (h-l)/2;
            if(check(mid)){
                ans = mid;
                h = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};