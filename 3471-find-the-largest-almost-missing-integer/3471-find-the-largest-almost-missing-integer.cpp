class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<=(n-k);i++){
            unordered_map<int,int> temp;
            for(int j=i;j<(i+k);j++){
                temp[nums[j]]++;
            }
            for(auto it:temp) mpp[it.first]++;
        }
        int ans = -1;
        for(auto it:mpp){
            if(it.second==1){
                ans = max(ans,it.first);
            }
        }
        return ans;
    }
};