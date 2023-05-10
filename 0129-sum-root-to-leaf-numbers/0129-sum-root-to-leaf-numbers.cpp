class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        helper(root, 0, res);
        return res;
    }
    
    void helper(TreeNode* node, int sum, int& res) {
        sum = sum * 10 + node->val;
        if (!node->left && !node->right) {
            res += sum;
            return;
        }
        if (node->left) helper(node->left, sum, res);
        if (node->right) helper(node->right, sum, res);
    }
};
