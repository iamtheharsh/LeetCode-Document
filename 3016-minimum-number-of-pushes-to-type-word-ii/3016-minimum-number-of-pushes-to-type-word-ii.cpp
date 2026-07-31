class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> freq(26,0);
        for(auto w:word){
            freq[w-'a']++;
        }
        sort(freq.begin(),freq.end());
        int ans = 0;
        int cnt = 0;
        for(int i=25;i>=0;i--){
            int num = cnt/8;
            ans += freq[i]*(num+1);
            cnt++;
        }
        return ans;
    }
};