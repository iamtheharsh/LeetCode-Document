class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq; 
        int ans = INT_MIN;

        for (auto &p : points) {
            int x = p[0];
            int y = p[1];
            while (!pq.empty() && x - pq.top().second > k) pq.pop();
            if (!pq.empty()) ans = max(ans,pq.top().first+x+y);
            pq.push({y-x,x});
        }
        return ans;
    }
};