class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        vector<pair<int,int>> v;
        int n= r1.size();
        for(int i=0;i<n;i++){
            v.push_back({r1[i]-r2[i],i});
        }
        sort(v.begin(),v.end());
        vector<bool> taken(n,false);
        int ans = 0;
        int i = n-1;
        while(k>0){
            int diff = v[i].first;
            int idx = v[i].second;
            ans += r1[idx];
            taken[idx] = true;
            i--;
            k--;
        }
        for(i=0;i<n;i++){
            if(!taken[i]) ans += r2[i];
        }
        return ans;
    }
};