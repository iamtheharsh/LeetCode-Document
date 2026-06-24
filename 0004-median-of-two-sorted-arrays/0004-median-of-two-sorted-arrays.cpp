class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        if(n>m) return findMedianSortedArrays(b,a);
        int low = 0, high = n;
        int tot = (n+m);
        bool isOdd = (n+m)%2;
        
        while(low<=high){
            int cnt1 = low + (high-low)/2;
            int cnt2 = (n + m + 1) / 2 - cnt1;
            
            int l1 = (cnt1==0)? INT_MIN:a[cnt1-1];
            int r1 = (cnt1==n)? INT_MAX:a[cnt1];

            int l2 = (cnt2==0)? INT_MIN:b[cnt2-1];
            int r2 = (cnt2==m)? INT_MAX:b[cnt2];

            if(l1<=r2 && l2<=r1){
                if(isOdd) return max(l1,l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            else if(l1>r2){
                high = cnt1 -1;
            }
            else low = cnt1+1;
        }
        return -1;
    }
};