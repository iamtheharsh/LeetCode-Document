class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
     int ans = n*2;
     int m = rs.size();
     sort(rs.begin(),rs.end());
     int i = 0;
     while(i<m){
        vector<int> seats;
        int j = i;
        while(j<m && rs[j][0]==rs[i][0]) {
            seats.push_back(rs[j][1]);
            j++;
        }
        bool first = true, mid = true , last = true;
        for(auto& s:seats){
            if(s>=2 && s<=5) first = false;
            if(s>=4 && s<=7) mid = false;
            if(s>=6 && s<=9) last = false;
        }
        ans -=2;
        if(first){
            if(last) ans += 2;
            else ans ++;
        }
        else if(last){
            ans++;
        }
        else {
            if(mid) ans++;
        }
        i = j;
     }
     return ans;
     
    }
};