class Solution {
public:
    using ll = long long;
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(),nums.end());
        vector<ll> freq(mx+1,0),divCnt(mx+1,0);
        vector<ll> exact(mx+1,0);
        for(auto num:nums) freq[num]++;

        for(int g = mx;g>=1;g--){
            for(int x = g;x<=mx;x+=g){
                divCnt[g] += freq[x];
            }
        }

        for(int i=mx;i>=1;i--){
            exact[i] = 1LL*divCnt[i]*(divCnt[i]-1)/2;
            for(int j=2*i;j<=mx;j+=i){
                exact[i] -= exact[j];
            }
        }

        vector<ll> v;
        vector<int> ans;
        vector<ll> pref;
        ll sum = 0;
        for(int i=1;i<=mx;i++){
            if(exact[i]>0){
                v.push_back(i);
                sum += exact[i];
                pref.push_back(sum);
            }
        }

        for(auto q:queries){
            auto idx = upper_bound(pref.begin(),pref.end(),q) - pref.begin();
            ans.push_back(v[idx]);
        }

        return ans;
    }
};