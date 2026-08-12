class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<vector<int>> temp;
        // time , 0/1 D/A , idx;
        int n = times.size();
        set<int> st;
        for(int i=0;i<n;i++){
            temp.push_back({times[i][0],1,i});
            temp.push_back({times[i][1],0,i});
            st.insert(i);
        }
        sort(temp.begin(),temp.end());
        unordered_map<int,int> mpp;
        for(int i=0;i<(2*n);i++){
            int t = temp[i][0];
            bool flag = temp[i][1];
            int idx = temp[i][2];
            if(flag){
                int tt = *(st.begin());
                if(idx==targetFriend) return tt;
                st.erase(tt);
                mpp[idx] = tt;
            }
            else{
                st.insert(mpp[idx]);
            }
        }
        return -1;
    }
};