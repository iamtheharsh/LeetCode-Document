class Solution {
public:
    bool static comp(const vector<int>& a,const vector<int>& b){
        if(a[0]!=b[0]) return b[0]>a[0];
        return a[1]>b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int c= intervals[0][0],d = intervals[0][1];
        int n = intervals.size();
        int cnt = 0;
        for(int i=1;i<n;i++){
            int a= intervals[i][0],b =intervals[i][1];
            if(a>=c && d>=b){
                cnt++;
            }
            else {
                c = a;
                d = b;
            }
        }
        return n- cnt;
    }
};