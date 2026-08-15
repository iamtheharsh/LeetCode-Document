class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(),e.end(),[](const vector<int>& a,const vector<int>& b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        }); 
        int n = e.size();
        vector<int> ans;
        ans.push_back(e[0][1]);

        for(int i=1;i<n;i++){
            if(e[i][1]>ans.back()) ans.push_back(e[i][1]);
            else{
                int idx = lower_bound(ans.begin(),ans.end(),e[i][1])-ans.begin();
                ans[idx] = e[i][1];
            }
        }

        return ans.size();
    }
};