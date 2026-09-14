class Solution {
public:
    double mincostToHireWorkers(vector<int>& qt, vector<int>& wg, int k) {
        double sum = 0;
        vector<pair<double,int>> v;
        int n = qt.size();

        for(int i=0;i<n;i++){
            double temp = (double)wg[i]/(double)qt[i];
            v.push_back({temp,i});
        }
        sort(v.begin(),v.end());

        priority_queue<int> pq;
        double ans = 1e14;

        for(int i=0;i<n;i++){
            int idx = v[i].second;
            double rate = v[i].first;
            if((int)pq.size()==(k-1)){
                sum += qt[idx];
                double temp = rate*sum;
                ans = min(ans,temp);
                sum -= qt[idx];

                if(!pq.empty() && pq.top()>(qt[idx])){
                    sum -= pq.top();
                    pq.pop();
                    pq.push(qt[idx]);
                    sum += qt[idx];
                }
            }
            else {
                pq.push(qt[idx]);
                sum += qt[idx];
            }
        }   

        return ans;
    }
};