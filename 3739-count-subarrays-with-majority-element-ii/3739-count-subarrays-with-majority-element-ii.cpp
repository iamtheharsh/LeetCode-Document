class Solution {
public:
    using ll = long long;
    vector<int> pref;

    ll merge(int l,int mid,int r){
        vector<int> temp;
        int i=l,j=mid+1;
        ll cnt=0;
        int p = l;
        for(int j = mid + 1; j <= r; j++){
            while(p<=mid && pref[p]<pref[j]) p++;
            cnt += (p-l);
        }
        
        while(i<=mid && j<=r){
            if(pref[j]>pref[i]){
                temp.push_back(pref[i++]);
            }
            else{
                temp.push_back(pref[j++]);
            }
        }

        while(i<=mid) temp.push_back(pref[i++]);
        while(j<=r) temp.push_back(pref[j++]);

        i=0;
        for(int k=l;k<=r;k++) pref[k]=temp[i++];
        return cnt;
    }

    ll solve(int l,int r){
        if(l>=r) return 0;
        int mid=(l+r)/2;

        ll ans=0;
        ans+=solve(l,mid);
        ans+=solve(mid+1,r);
        ans+=merge(l,mid,r);

        return ans;
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();

        vector<int> temp;
        for(auto num:nums){
            if(num==target) temp.push_back(1);
            else temp.push_back(-1);
        }

        pref.resize(n+1);
        pref[0]=0;

        for(int i=0;i<n;i++) pref[i+1]=pref[i]+temp[i];

        return solve(0,n);
    }
};