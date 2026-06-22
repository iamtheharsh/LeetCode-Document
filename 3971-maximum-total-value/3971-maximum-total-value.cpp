class Solution {
public:
    using ll = long long;
    ll mod = 1e9+7;
    int n,m;
    vector<int> vals,decay;

    bool check(ll mid){
        ll temp = 0;
        for(int i=0;i<n;i++){
            if(vals[i]<mid) continue;
            temp += max(0LL,(vals[i]-mid)/decay[i] + 1);
            if(temp>=(ll)m) return true;
        }
        return false;
    }

    ll solve(ll th){
        ll sum = 0;
        ll cnt = 0;
        for(int i=0;i<n;i++){
            if(vals[i]<=th) continue;
            ll temp =  max(0LL,(vals[i]-(th+1))/decay[i] + 1);
            cnt += temp;
            ll add = temp*(2LL*vals[i] - (temp-1)*1LL*decay[i])/2;
            sum = (sum + add)%mod;
        }
        ll diff = (ll)m - cnt;
        ll add = (diff*th)%mod;
        sum = (sum + add)%mod;
        return sum;
    }
    
    int maxTotalValue(vector<int>& vals, vector<int>& decay, int m) {
        this->m = m;
        this->vals = vals;
        this->decay = decay;
        n = vals.size();
        ll l = 0, h = 1e9;
        ll threshold = 0;
        while(l<=h){
            ll mid = l + (h-l)/2;
            if(check(mid)){
                threshold = mid;
                l = mid+1;
            }
            else h = mid-1;
        }
        cout<<threshold<<endl;
        return solve(threshold);
    }
};