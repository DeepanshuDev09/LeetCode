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
    void solve(TreeNode* root, int& ans){
        if (root == nullptr) return;

        int currSum = root->val + sumTree(root->left) + sumTree(root->right);
        int nodeCount = 1 + countNodes(root->left) + countNodes(root->right);

        if (root->val == currSum/nodeCount) ans++;

        solve(root->right, ans);
        solve(root->left, ans);
    }

    int sumTree(TreeNode* root) {
        if (root == nullptr)
            return 0;

        return root->val + sumTree(root->left) + sumTree(root->right);
    }

    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};