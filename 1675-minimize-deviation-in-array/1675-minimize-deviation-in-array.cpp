class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        for(auto &num:nums){
            if(num%2) num = num*2;
        }
        int mini = *min_element(nums.begin(),nums.end());
        priority_queue<int> pq;
        for(auto num:nums){
            pq.push(num);
        }
        int ans = INT_MAX;
        while(pq.top()%2==0){
            int maxi = pq.top();
            pq.pop();
            ans = min(ans,abs(maxi-mini));
            maxi = maxi/2;
            mini = min(maxi,mini);
            pq.push(maxi);
        }
        ans = min(ans,pq.top()-mini);
        return ans;
    }
};