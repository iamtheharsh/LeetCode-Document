class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int,int> freq,mpp;
        for(auto& p:planks) freq[p]++;
        vector<pair<int,int>> v(freq.begin(),freq.end());
        sort(v.begin(),v.end());
        int ans = 0;
        for(auto& it:v){
            mpp[it.first] = it.second;
            ans = max(ans,mpp[it.first]);
        }
        int n = v.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int val = v[i].first + v[j].first;
                if(i==j) mpp[val] += v[i].second/2;
                else mpp[val] += min(v[i].second,v[j].second);
                ans = max(ans,mpp[val]);
            }
        }
        return ans;
    }
};