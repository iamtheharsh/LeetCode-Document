class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        map<pair<int,int>,int> mpp;
        int ans = 0,mx = 0;

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                ans++;
            }
            else {
                int a = nums[i];
                int b = nums[i-1];
                if(a>b) swap(a,b);
                mpp[{a,b}]++;
                mx = max(mx,mpp[{a,b}]);
            }   
        }

        return ans + mx;
    }
};