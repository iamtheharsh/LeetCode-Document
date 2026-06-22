class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string word = "balloon";
        vector<int> need(26,0);
        for(auto w:word){
            need[w-'a']++;
        }
        vector<int> hash(26,0);
        for(auto c:text){
            hash[c-'a']++;
        }
        int ans = INT_MAX;
        for(auto w:word){
            int temp = hash[w-'a']/need[w-'a'];
            ans = min(ans,temp);
        }
        return ans;
    }
};