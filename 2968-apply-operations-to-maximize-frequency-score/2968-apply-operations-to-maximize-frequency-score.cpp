class Solution {
public:
    using ll = long long;
    vector<ll> pref;
    ll k,n;

    ll helper(int m,int l,int r,vector<int>& nums){
        int lenl = m-l+1 , lenr = r-m+1;

        ll left = 1LL*nums[m]*lenl - (pref[m+1]-pref[l]);
        ll right =  (pref[r+1]-pref[m]) - 1LL*nums[m]*lenr;

        return left + right;
    }

    bool check(int mid,vector<int>& nums){
        for(int i=0;i<=n-mid;i++){
            int j = i+mid-1;
            if(mid%2){
                int m = (i+j)/2;
                ll sum = helper(m,i,j,nums);
                if(k>=sum) return true;
            }
            else{
                int m1 = (i+j)/2;
                int m2 = m1+1;
                ll sum1 = helper(m1,i,j,nums);
                ll sum2 = helper(m2,i,j,nums);
                if(k>=sum1 || k>=sum2) return true;
            }
        }
        return false;
    }
    int maxFrequencyScore(vector<int>& nums, long long k) {
        n = nums.size();
        this->k = k;
        sort(nums.begin(),nums.end());

        pref.resize(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1] = pref[i] + nums[i];
        }

        int l = 1, h = n;
        int ans = l;
        while(l<=h){
            int m = l + (h-l)/2;
            if(check(m,nums)){
                ans = m;
                l = m+1;
            }
            else h = m-1;
        }
        return ans;
    }
};