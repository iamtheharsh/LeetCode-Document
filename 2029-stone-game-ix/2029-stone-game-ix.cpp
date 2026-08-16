class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();
        vector<int> temp = {0,0,0};
        for(auto& s:stones){
            temp[s%3]++;
        }
        if(temp[0]%2==0) return temp[1]>=1 && temp[2]>=1;
        return abs(temp[1]-temp[2])>2;
    }
};