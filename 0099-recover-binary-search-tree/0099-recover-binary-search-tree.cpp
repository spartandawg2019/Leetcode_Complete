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
    void recoverTree(TreeNode* root) {
        TreeNode *first = NULL, *second = NULL, *prev = new TreeNode(INT_MIN);
        dfs(root, prev, first, second);
        swap(first->val, second->val);
    }
    void dfs(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &second) {
        if (!root) return;
        dfs(root->left, prev, first, second);
        if (prev && prev->val > root->val) {
            if (!first) first = prev;
            second = root;
        }
        prev = root;
        dfs(root->right, prev, first, second);
    }
};
