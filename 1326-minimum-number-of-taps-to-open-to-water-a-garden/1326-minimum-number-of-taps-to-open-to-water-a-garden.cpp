class Solution {
public:
    int getIdx(int maxi, vector<pair<int,int>>& intervals) {
        return upper_bound(intervals.begin(),intervals.end(),make_pair(maxi,INT_MAX))- intervals.begin()-1;
    }
   
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> intervals;
        for(int i=0;i<=n;i++){
            int l = i-ranges[i];
            int r = i+ranges[i];
            intervals.push_back({l,r});
        }
        sort(intervals.begin(),intervals.end());
        int maxi = -1;
        int cnt = 1;
        
        int i = 0;
        while (i<=n && intervals[i].first <= 0) {
            maxi = max(maxi, intervals[i].second);
            i++;
        }
        if(maxi>=n) return 1;
        if(maxi==(-1)) return -1;

        while(true){
            int nm = maxi;
            int ni = getIdx(maxi,intervals); //upper bound maxi ka
            
            while(i<=ni){
                nm = max(nm,intervals[i].second);
                i++;
            }
            if(nm==maxi) return -1;
            cnt++;
            maxi = nm;
            if(nm>=n) return cnt;
        }
        return -1;
    }
};