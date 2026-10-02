class Solution {
public:
    map<pair<string,string>,int> dp;

    string reducing(string& s){
        bool flag = true;
        while(flag){
            flag = false;
            for(int i=0;i<s.size();i++){
                int j = i;
                while(j<s.size() && s[i]==s[j]){
                    j++;
                }
                if(j-i>=3){
                    s.erase(i,j-i);
                    flag = true;
                    break;
                }
            }
        }

        return s;
    }

    int solve(string board,string hand){
        board = reducing(board);
        if(board.empty()) return 0;
        if(hand.empty()) return 100;

        sort(hand.begin(),hand.end());
        pair<string,string> key = {board,hand};
        if(dp.count(key)) return dp[key];

        int ans = 100;

        for(int i=0;i<hand.size();i++){
            char c = hand[i];
            if (i > 0 && hand[i] == hand[i-1]) continue;
            string newHand = hand.substr(0,i) + hand.substr(i+1);
            for(int j=0;j<=board.size();j++){

                bool f1 = (j< board.size() && board[j] == c);
                bool f2 = (j > 0 && j < board.size() && board[j-1] == board[j] && board[j] != c);
                
                if (!f1 && !f2) {
                    continue;
                }

                
                string newBoard = board.substr(0,j) + c + board.substr(j);
                int temp = 1 + solve(newBoard,newHand);
                ans = min(ans,temp);
            }
        }
        return dp[key] = ans;
    }

    int findMinStep(string board, string hand) {
        int res = solve(board,hand);
        if(res>=100) return -1;
        return res;
    }
};