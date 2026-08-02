class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> pref(n),suff(n);
        int mx = h[0];
        pref[0] = 0;
        suff[n-1] = 0;
        for(int i=1;i<n;i++){
            pref[i] = mx;
            mx = max(mx,h[i]);
        }
        mx = h[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i] = mx;
            mx = max(mx,h[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(pref[i]>=h[i] && suff[i]>=h[i]){
                ans += min(pref[i],suff[i]) - h[i];
            }
        }
        return ans;
    }
};