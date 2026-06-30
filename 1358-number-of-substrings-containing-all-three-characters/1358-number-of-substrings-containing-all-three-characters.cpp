class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        vector<int> temp = {-1,-1,-1};
        int n = s.size();
        for(int i=0;i<n;i++){
            temp[s[i]-'a'] = i;
            ans += min(min(temp[0],temp[1]),temp[2]) +1;
        }
        return ans;
    }
};