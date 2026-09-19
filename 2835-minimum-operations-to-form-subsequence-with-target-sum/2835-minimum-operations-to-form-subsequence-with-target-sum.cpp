class Solution {
public:
    using ll = long long;

    int minOperations(vector<int>& nums, int target) {
        ll sum = accumulate(nums.begin(),nums.end(),0LL);
        if(1LL*target>sum) return -1;

        vector<int> hash(33,0);
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<32;j++){
                if(nums[i]&(1<<j)){
                    hash[j]++;
                }
            }
        }

        int ans = 0;
        for(int i=0;i<32;i++){
            if((1<<i)&target){
                if(hash[i]>0){
                    hash[i]--;
                }
                else {
                    int j = i+1;
                    while(j<32 && hash[j]==0) j++;
                    ans += j-i;                  
                    hash[j]--;

                    for(int k=i+1;k<j;k++) hash[k]++;
                }
            }
            hash[i+1] += hash[i]/2;
        }

        return ans;
    }
};