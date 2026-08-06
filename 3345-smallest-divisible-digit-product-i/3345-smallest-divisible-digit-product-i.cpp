class Solution {
public:
    bool check(int n,int t){
        int prod = 1;
        while(n!=0){
            prod = prod*(n%10);
            n = n/10;
        }
        return prod%t==0;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=1000;i++){
            if(check(i,t)) return i;
        }
        return -1;
    }
};