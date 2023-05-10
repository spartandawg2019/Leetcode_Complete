/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }

private:
    vector<int> dfs(TreeNode* node) {
        if (!node) return vector<int>(2, 0);
        vector<int> left = dfs(node->left);
        vector<int> right = dfs(node->right);
        vector<int> res(2);
        res[0] = left[1] + right[1] + node->val;
        res[1] = max(left[0], left[1]) + max(right[0], right[1]);
        return res;
    }
};
