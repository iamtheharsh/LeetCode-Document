class Solution {
public:
    using ll = long long;

    string makePal(string s){
        int i = 0, j = s.size()-1;
        while(i <= j){
            s[j] = s[i];
            i++;
            j--;
        }
        return s;
    }

    string nearestPalindromic(string s) {
        int n = s.size();
        ll temp = stoll(s);

        vector<ll> cand;

        string t(n-1,'9');
        if(t.size()) cand.push_back(stoll(t));

        t = "1";
        for(int i=0;i<n-1;i++) t += "0";
        t += "1";
        cand.push_back(stoll(t));

        string pre = s.substr(0,(n+1)/2);
        ll p = stoll(pre);

        for(ll x=p-1;x<=p+1;x++){
            if(x<0) continue;

            string cur = to_string(x);
            string pal = cur;

            int st = (n&1)?cur.size()-2:cur.size()-1;
            for(int i=st;i>=0;i--) pal += cur[i];

            cand.push_back(stoll(pal));
        }

        ll ans = -1;

        for(auto x:cand){
            if(x==temp) continue;
            if(ans==-1) ans = x;
            else if(abs(x-temp)<abs(ans-temp)) ans = x;
            else if(abs(x-temp)==abs(ans-temp) && x<ans) ans = x;
        }

        return to_string(ans);
    }
};