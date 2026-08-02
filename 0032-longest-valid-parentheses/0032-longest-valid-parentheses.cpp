class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n==0) return 0;
        // int i = 0;
        // while(i<n && s[i]==')') i++;
        vector<int> dp(n,0);
        stack<pair<char,int>> st;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                if(!st.empty()){
                    auto [c,idx] = st.top();
                    st.pop();
                    int len = i-idx+1;
                    dp[i] += len;
                    if(idx!=0) dp[i] += dp[idx-1];
                }
            }
            else{
                st.push({'(',i});
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};