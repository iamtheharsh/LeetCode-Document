class Solution {
public:
    using ll = long long;
    int maximumLength(vector<int>& nums) {
        unordered_map<ll,int> freq;
        for(auto num:nums){
            freq[num]++;
        }
        ll ans = 0;
        for(auto it:freq){
            ll curr = it.first;
            if(curr==1) continue;
            int cnt = 0;
            while(freq.count(curr) && freq[curr]>1){
                curr = curr*curr;
                cnt+=2;
                if(curr>(1LL*1e9)) break;
            }
            if(freq.count(curr)){
                ans = max(ans,1LL*cnt + 1);
            }
            else ans = max(ans,1LL*cnt-1);
        }
        int cnt = freq[1];
        ans = max(ans,1LL*( cnt % 2 ? cnt : cnt - 1));
        return ans;
    }
};