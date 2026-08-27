class Solution {
public:
    string s,t;
    int n,m;

    string solve(int i,int j,bool tight,string& curr,vector<int>& freq){
        if(i == n) return tight ? "~" : curr;

        if(j == m){
            string res = curr;
            for(int c = 0; c < 26; c++)
                res += string(freq[c], 'a' + c);
            return res;
        }

        if(!tight){
            string res = curr;
            for(int c = 0; c < 26; c++)
                res += string(freq[c], 'a' + c);
            return res;
        }

        int x = t[j] - 'a';

        if(freq[x]){
            freq[x]--;
            curr += char('a' + x);

            string same = solve(i + 1, j + 1, true, curr, freq);

            curr.pop_back();
            freq[x]++;

            if(same != "~") return same;
        }

        for(int c = x + 1; c < 26; c++){
            if(freq[c]){
                freq[c]--;
                curr += char('a' + c);

                string ans = curr;
                for(int k = 0; k < 26; k++)
                    ans += string(freq[k], 'a' + k);

                return ans;
            }
        }

        return "~";
    }

    string lexGreaterPermutation(string ss, string target) {
        s = ss;
        t = target;
        n = s.size();
        m = t.size();

        vector<int> freq(26, 0);
        for(char c : s)
            freq[c - 'a']++;

        string curr;
        string ans = solve(0, 0, true, curr, freq);

        return ans == "~" ? "" : ans;
    }
};