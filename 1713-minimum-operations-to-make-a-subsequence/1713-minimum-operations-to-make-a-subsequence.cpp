class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mpp;
        int i=0;
        for(auto& num:target){
            mpp[num] = i++;
        }
        vector<int> temp;
        for(auto num:arr){
            if(mpp.find(num)!=mpp.end()){
                temp.push_back(mpp[num]);
            }
        }
        vector<int> ans;
        for(int i=0;i<temp.size();i++){
            if(ans.empty() || temp[i]>ans.back()) ans.push_back(temp[i]);
            else {
                int idx = lower_bound(ans.begin(),ans.end(),temp[i]) - ans.begin();
                ans[idx] = temp[i];
            }
        }
        return target.size()- ans.size();
    }
};