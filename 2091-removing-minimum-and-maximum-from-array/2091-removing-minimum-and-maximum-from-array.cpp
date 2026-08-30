class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mni = -1, mxi = -1;
        int mn = INT_MAX , mx = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]<mn){
                mn = nums[i];
                mni = i;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>mx){
                mx = nums[i];
                mxi = i;
            }
        }
        int ans = max(mni,mxi) + 1;
        int temp = n - min(mni,mxi);
        ans = min(ans,temp);
        temp = min(mni,mxi) + 1 + n - max(mni,mxi);
        ans = min(ans,temp);
        return ans; 
    }
};