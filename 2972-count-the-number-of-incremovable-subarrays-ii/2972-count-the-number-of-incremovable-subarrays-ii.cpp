class Solution {
public:
    using ll = long long;
    long long incremovableSubarrayCount(vector<int>& arr) {
        int n = arr.size();
        int p = 1;
        while(p<n && arr[p-1]<arr[p]) p++;
        int s = n-1;
        while(s>0 && arr[s-1]<arr[s]) s--;
        
        ll total = 0;
        int k = s;
        for(int i=0;i<=p;i++){
            if(k<(i+1)) k = i+1;
            if(i>0){
                int prev = arr[i-1];
                while(k<n && arr[k]<=prev) k++;
            }
            total += (ll)(n-k+1);
        }
        return total;
    }
};