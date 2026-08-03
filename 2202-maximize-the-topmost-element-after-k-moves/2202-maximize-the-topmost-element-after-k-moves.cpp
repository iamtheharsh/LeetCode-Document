class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0) return nums[0];
        if(n==1 && k%2==1) return -1;
        if(n==1 && k%2==0) return nums[0];
        if(k==1) return nums[1];
        int mx = *max_element(nums.begin(), nums.begin() + min(k-1,n));
        if(k<n) mx = max(mx,nums[k]);
        return mx;
    }
};