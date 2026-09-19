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
    void solve(TreeNode* root, int len, int& ans){
        if (root == NULL) return;

        ans = max(len, ans);
        solve(root->left, len+1, ans);
        solve(root->right, len+1, ans);
    }
public:
    int maxDepth(TreeNode* root) {
        int ans = 0;
        solve(root, 1, ans);

        return ans;
    }
};