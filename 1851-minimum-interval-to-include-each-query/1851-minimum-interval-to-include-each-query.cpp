class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());

        vector<pair<int,int>> q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        int m = q.size();

        set<pi> st; // len,end
        vector<int> ans(m,-1);
        int i = 0;
        for(auto& [point,idx]:q){
            while(i<n && point>=intervals[i][0]){
                int len = intervals[i][1]-intervals[i][0]+1;
                st.insert({len,intervals[i][1]});
                i++;
            }   
            while(!st.empty()){
                auto [len,end] = *(st.begin());
                if(point>end) st.erase({len,end});
                else break;
            }
            if(st.empty()) continue;
            auto [len,end] = *(st.begin());
            ans[idx] = len;
        }
        return ans;

    }
};