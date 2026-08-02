class Solution {
public:
    bool check(int m,int k,vector<int>& nums){
        int n= nums.size();
        int i=0;
        int cnt = 0;
        // bool last = false;
        while(i<n){
            if(nums[i]>m) {
                i++;
                continue;
            }
            int j = i;
            while(j<n && nums[j]<=m){
                j++;
            }
            int len = j-i;
            cnt += (len+1)/2;
            i = j;
        }
        return cnt>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        int n = nums.size();
        int l= *min_element(nums.begin(),nums.end());
        int h= *max_element(nums.begin(),nums.end());
        int ans = h;
        while(l<=h){
            int m = l + (h-l)/2;
            if(check(m,k,nums)){
                ans = m;
                h = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};