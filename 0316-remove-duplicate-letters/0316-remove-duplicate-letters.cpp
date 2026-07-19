class Solution {
public:
    string removeDuplicateLetters(string s) {
int n = s.size();
        stack<char> st;
        vector<int> freq(26,0);
        vector<bool> temp(26,false);

        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }

        for(int i=0;i<n;i++){
            char ch = s[i];
            int idx = ch-'a';

            freq[idx]--;

            if(temp[idx]) continue;

            while(!st.empty() && st.top()>ch && freq[st.top()-'a']>0){
                temp[st.top()-'a'] = false;
                st.pop();
            }

            st.push(ch);
            temp[idx] = true;
        }

        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};