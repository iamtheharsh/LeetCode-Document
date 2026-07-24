class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int mx = 2048;
        vector<int> hash(mx+1,0);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int xr = nums[i]^nums[j];
                hash[xr] = 1;
            }
        }
        vector<int> ans(mx+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<=mx;j++){
                if(hash[j]){
                    int xr = j^nums[i];
                    ans[xr] =1;
                }
            }
        }
        int sum = accumulate(ans.begin(),ans.end(),0);
        return sum;
    }
};