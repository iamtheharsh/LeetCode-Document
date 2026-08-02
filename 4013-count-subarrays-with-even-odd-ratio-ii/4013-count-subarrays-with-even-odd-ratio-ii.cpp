class Solution {
public:
    using ll = long long;
    vector<ll> pref;

    ll merge(int l,int mid,int r){
        ll cnt = 0;
        int i = l, j = mid+1;
        for(i=l;i<=mid;i++){
            while(j<=r && pref[j]<=pref[i]){
                j++;
            }
            cnt += (j-mid-1);
        }
        vector<ll> temp;
        i = l,j = mid+1;
        while(i<=mid && j<=r){
            if(pref[i]<=pref[j]){
                temp.push_back(pref[i]);
                i++;
            }
            else {
                temp.push_back(pref[j]);
                j++;
            }
        }
        while(i <= mid) {
            temp.push_back(pref[i]);
            i++;
        }
        while(j <= r) {
            temp.push_back(pref[j]);
            j++;
        }

        for(int k=0;k<temp.size();k++){
            pref[l+k] = temp[k];
        }
        return cnt;
    }


    ll solve(int i,int j){
        if(i==j) return 0;
        int mid = (i+j)/2; 
        ll ans = 0;
        ans += solve(i,mid);
        ans += solve(mid+1,j);
        ans += merge(i,mid,j);
        return ans;
    }
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        pref.resize(n+1,0);
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) pref[i+1] = pref[i] + b;
            else pref[i+1] = pref[i] -a;
        }
        return solve(0,n);
    }
};