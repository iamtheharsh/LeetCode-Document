class Solution {
public:
    using ll = long long;
    vector<ll> bit;
    int n;

    void update(int i,int val){
        while(i<=n){
            bit[i] += val;
            i += i&(-i);
        }
    }

    int query(int i){
        int sum = 0;
        while(i>0){
            sum += bit[i];
            i -= i&(-i);
        }
        return sum;
    }

    long long distantSubarrays(vector<int>& nums, int goal, int k) {
        int m = nums.size();
        if(k==0){
            return (1LL*m*(m+1))/2;
        }

        vector<ll> comp = {0};
        ll p =0;
        for(auto it:nums) {
            p += it;
            comp.push_back(p);
        }

        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        n = comp.size();
        bit.resize(n+1,0);

        ll ans =0, pref = 0;
        int idx = lower_bound(comp.begin(),comp.end(),0LL) - comp.begin();
        update(idx+1,1);

        for(int i=0;i<nums.size();i++){
            ll num = nums[i];
            pref += num;

            ll x1 = pref - goal + k;
            ll x2 = pref- goal - k;

            int i1 = lower_bound(comp.begin(),comp.end(),x1) - comp.begin();
            int i2 = upper_bound(comp.begin(),comp.end(),x2) - comp.begin();

            ll sum1 = query(n) - query(i1);
            ll sum2 = query(i2); 
            ans += sum1 + sum2;

            cout<<sum1<<" "<<sum2<<endl;

            i1 = lower_bound(comp.begin(),comp.end(),pref) - comp.begin();
            update(i1+1,1);
        }

        return ans;
    }

};