class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> nums;

    int solve(int i, int j){
        if(i == j) return nums[i];

        auto &res = dp[i][j];
        if(res != -1e9) return res;

        int left = nums[i] - solve(i + 1, j);
        int right = nums[j] - solve(i, j - 1);

        return res = max(left, right);
    }

    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;

        dp.assign(n, vector<int>(n, -1e9));

        return solve(0, n - 1) >= 0;
    }
};