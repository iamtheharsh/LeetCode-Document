class Solution {
public:
    using ll = long long;
    vector<ll> num;

    void precompute(){
        for(int mask=1;mask<(1<<9);mask++){
            int odd = 0,len = 0,mid = -1;
            for(int i=1;i<=9;i++){
                if(mask&(1<<(i-1))){
                    len += i;
                    if(i%2){
                        odd++;
                        mid = i;
                    }
                }
            }
            if(odd>1 || len>17) continue;

            string half = "";

            for(int d=1;d<=9;d++){
                if(mask&(1<<(d-1))){
                    half += string(d/2,'0'+d);
                }
            }

            if(half.empty()){
                if(mid!=-1){
                    num.push_back(mid);
                }
                continue;
            }

            sort(half.begin(),half.end());

            while(true){
                string rev = half;
                reverse(rev.begin(),rev.end());

                string full = half;
                if(mid!=-1){
                    full += char('0'+mid);
                }
                full += rev;

                num.push_back(stoll(full));

                if(!next_permutation(half.begin(),half.end())){
                    break;
                }
            }
        }

        sort(num.begin(),num.end());
    }

    long long specialPalindrome(long long n) {
        if(num.empty()){
            precompute();
        }

        auto it = upper_bound(num.begin(),num.end(),n);
        return *it;
    }
};