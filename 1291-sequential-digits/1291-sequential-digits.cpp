class Solution {
public:
    using ll  = long long;
    vector<ll> digits;
    
    void compute(ll num){
        if(num>=(1e9)) return;
        digits.push_back(num);
        int ld = num%10;
        if(ld==9) return;
        ll newNum = num*10 + (ld+1);
        compute(newNum);
    }
    vector<int> sequentialDigits(int low, int high) {
        for(int i=1;i<=9;i++){
            compute(i);
        }
        vector<int> ans;
        for(int i=0;i<digits.size();i++){
            if(digits[i]>=low && digits[i]<=high){
                ans.push_back(digits[i]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};