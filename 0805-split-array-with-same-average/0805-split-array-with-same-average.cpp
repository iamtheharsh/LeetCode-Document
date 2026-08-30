
class Solution {
public:
    using ll = long long;
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int lh = n/2;
        int rh = n - lh;
        ll ls = 0 , rs = 0;

        vector<vector<ll>> left(lh+1),right(rh+1);
        
        for(int mask = 0;mask<(1<<lh);mask++){
            int cnt = 0;
            ll sum = 0;

            for(int i=0;i<lh;i++){
                if(mask &(1<<i)){
                    sum += nums[i];
                    cnt++;
                }
            }
            left[cnt].push_back(sum);
        }

        for(int mask = 0; mask<(1<<rh);mask++){
            int cnt = 0;
            ll sum = 0;
            for(int i=0;i<rh;i++){
                if(mask&(1<<i)){
                    sum += nums[lh+i];
                    cnt++;
                }
            }
            right[cnt].push_back(sum);
        }
    
        for(int i=0;i<left.size();i++) sort(left[i].begin(),left[i].end());
        for(int i=0;i<right.size();i++) sort(right[i].begin(),right[i].end());

        for(auto x:nums){
            ls += x;
        }

        for(int cnt = 0;cnt<=lh;cnt++){
            if(left[cnt].size()>0){
                for(int i=0;i<left[cnt].size();i++){
                    ll sum1 = left[cnt][i];
                    for(int cnt2=0;cnt2<=rh;cnt2++){
                        int cnt3 = cnt + cnt2;
                        if(cnt3==0 || cnt3==n) continue;
                        ll val = ls*cnt3 - sum1*n;
                        if(val%n != 0) continue;
                        ll need = val/n;
                        if(binary_search(right[cnt2].begin(),right[cnt2].end(),need)){
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
};
