class Solution {
public:
    vector<vector<int>> adj = {
        {1,3},{0,2,4},{1,5},{0,4}, {1,3,5} , {2,4} 
    };
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string start = "";

        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                start += char('0' + board[i][j]);
            }
        }

        set<string> vis;
        queue<pair<string,int>> q;
        q.push({start,0});
        vis.insert(start);

        while(!q.empty()){
            auto [curr,moves] = q.front();
            q.pop();

            if(curr==target) return moves;

            int i;
            for(int idx = 0;idx<curr.size();idx++){
                if(curr[idx]=='0') i = idx;
            }

            for(auto j:adj[i]){
                string next = curr;
                swap(next[i],next[j]);
                if(vis.find(next)==vis.end()){
                    vis.insert(next);
                    q.push({next,moves+1});
                }
            }
        }
        return -1;

    }
};