class Solution {
public:
    bool isPalindrome(string& s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> arr(n,0);

        for(int i=0;i<=(n-k);i++){
            int left = (n-i);
            for(int len=k;len<=left;len++){
                if(isPalindrome(s,i,i+len-1)){
                    arr[i] = len;
                    break;
                }
            }
        }

        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            dp[i] = dp[i+1];
            if(arr[i]){
                dp[i] = max(dp[i],1 + dp[i+arr[i]]);
            }
        }
        return dp[0];
    }
};