class Solution {
public:
    int totalFruit(vector<int>& f) {
        int n = f.size();
        int c1 = 0, c2 = 0;
        int f1 = -1, f2 = -1;
        int i1 = -1, i2 = -1;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(f1 == -1) {
                f1 = f[i];
                c1++;
                i1 = i;
            }
            else if(f[i] == f1) {
                c1++;
                i1 = i;
            }
            else if(f2 == -1) {
                f2 = f[i];
                c2++;
                i2 = i;
            }
            else if(f[i] == f2) {
                i2 = i;
                c2++;
            }
            else if(i1 > i2) {
                ans = max(ans, c1 + c2);
                c1 = i - 1 - i2; 
                c2 = 1;          
                f2 = f[i];
                i2 = i;
            }
            else {
                ans = max(ans, c1 + c2);
                c2 = i - 1 - i1; 
                c1 = 1;          
                f1 = f[i];
                i1 = i;
            }
            ans = max(ans, c1 + c2);
        }
        return ans;
    }
};