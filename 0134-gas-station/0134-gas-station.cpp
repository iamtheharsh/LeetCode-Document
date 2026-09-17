class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sg = 0,sc = 0;
        for(int i=0;i<n;i++){
            sg += gas[i];
            sc += cost[i];
        }
        if(sc>sg) return -1;
        int curr = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(i==curr){
                sum = gas[i]-cost[i];

            }
            else if(i!=curr) sum += gas[i]-cost[i];
            if(sum<0){
                curr = i+1;
                sum = 0;
            }
        }
        return curr;
    }
};