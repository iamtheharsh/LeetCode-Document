class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> temp = mat[0];
        int m = mat.size();
        int n = mat[0].size();
        sort(temp.begin(),temp.end());
        for(int i=1;i<m;i++){
            vector<int> curr;
            for(int j=0;j<n;j++){
                for(int it=0;it<temp.size();it++){
                    curr.push_back(temp[it] + mat[i][j]);
                }
            }
            sort(curr.begin(),curr.end());
            temp.clear();
            for(int i=0;i<min(k+1,(int)curr.size());i++){
                temp.push_back(curr[i]);
            }
        }
        return temp[k-1];
    }
};