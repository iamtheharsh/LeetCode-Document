class Solution {
public:
    string smallestPalindrome(string s) {
        string res;
        int n = s.size();
        vector<int> freq(26,0);

        for(auto &c : s){
            freq[c-'a']++;
        }

        char one = 'A';

        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            else if(freq[i]%2==1){
                one = (char)(i+'a');
            }

            int temp = freq[i]/2;
            while(temp>0){
                res += (char)(i+'a');
                temp--;
            }
        }

        string rev = res;
        reverse(rev.begin(), rev.end());

        if(one=='A') return res + rev;
        return res + one + rev;
    }
};