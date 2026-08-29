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
    unordered_map<TreeNode*,bool> isBst;
    unordered_map<TreeNode*,int> sum;
    int ans = 0;
    tuple<bool,int,int> helper(TreeNode* root){
        if(root==nullptr) return {true, INT_MAX, INT_MIN};

        bool flag = true;

        auto [leftBst, leftMin, leftMax] = helper(root->left);
        auto [rightBst, rightMin, rightMax] = helper(root->right);

        if(!leftBst || !rightBst) flag = false;

        if(root->left!=nullptr){
            if(leftMax >= root->val) flag = false;
        }

        if(root->right!=nullptr){
            if(rightMin <= root->val) flag = false;
        }

        int mn = min(root->val, leftMin);
        int mx = max(root->val, rightMax);

        isBst[root] = flag;

        return {flag, mn, mx};
    }
    int solve(TreeNode* root){
        if(root==nullptr) return 0;
        return sum[root] = root->val + solve(root->left) + solve(root->right);
    }
    void helper2(TreeNode* root){
        if(root==nullptr) return;
        if(isBst[root]) ans = max(ans,sum[root]);
        helper2(root->left);
        helper2(root->right);
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        solve(root);
        helper2(root);
        for(auto it:isBst){
            cout<<it.first->val<<" "<<it.second<<" "<<sum[it.first]<<endl;
        }
        return ans;
    }
};