class Solution {
public:
    using ll = long long;
    ll mod = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(31,0);
        for(auto num:nums){
            for(int i=0;i<31;i++){
                if(num&(1<<i)) freq[i]++;
            }
        }
        ll ans = 0;
        for(int i=0;i<k;i++){
            ll num = 0;
            for(int i=0;i<31;i++){
                if(freq[i]>0){
                    num = num | (1<<i);
                    freq[i]--;
                }
            }
            ll temp = (num*num)%mod;
            ans = (ans + temp)%mod;
        }
        return ans;
    }
};