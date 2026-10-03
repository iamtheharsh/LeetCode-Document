class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<pair<char,int>> st;
        vector<int> dp(n+1,0);
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push({'(',i});
            else{
                if(!st.empty()){
                    auto [c,idx] = st.top();
                    st.pop();
                    int len = i-idx+1;
                    dp[i] += len;
                    if(idx!=0) dp[i] += dp[idx-1];
                }
            }
        }
        return  *max_element(dp.begin(),dp.end());

    }
};