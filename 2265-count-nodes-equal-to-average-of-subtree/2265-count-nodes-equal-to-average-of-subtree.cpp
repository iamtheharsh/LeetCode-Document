/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    unordered_map<TreeNode*, int> cnt;

    pair<int,int>  dfs(TreeNode* node){
        if(node==nullptr) return {0,0};
        pair<int,int> res = {node->val,1}; // sum,cnt
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        res.first += left.first + right.first;
        res.second += left.second + right.second;

        int avg = res.first/res.second;
        if(avg==node->val) ans++;
        return res;
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};