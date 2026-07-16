class Solution {
public:
    using ll = long long;
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefGcd;
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            int temp = gcd(nums[i],mx);
            prefGcd.push_back(temp);
        }
        int i=0, j=n-1;
        ll ans = 0;
        sort(prefGcd.begin(),prefGcd.end());
        while(i<j){
            int a = prefGcd[i];
            int b = prefGcd[j];
            ans += gcd(a,b);
            i++;
            j--;
        }
        return ans;
    }
};