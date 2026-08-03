class Solution {
public:
    int candy(vector<int>& rat) {
        int n = rat.size();
        vector<int> v(n,1);
        for(int i=1;i<n;i++){
            if(rat[i]>rat[i-1]) v[i] = v[i-1] + 1;
        }
        for(int i=n-2;i>=0;i--){
            if(rat[i]>rat[i+1]) v[i] = max(v[i],v[i+1]+1);
        }
        int ans = accumulate(v.begin(),v.end(),0);
        return ans;
    }
};