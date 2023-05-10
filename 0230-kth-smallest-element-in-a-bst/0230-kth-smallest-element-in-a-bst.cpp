class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0, result = 0;
        inorder(root, k, count, result);
        return result;
    }
    void inorder(TreeNode* node, int k, int& count, int& result) {
        if (node == nullptr) return;
        inorder(node->left, k, count, result);
        count++;
        if (count == k) {
            result = node->val;
            return;
        }
        inorder(node->right, k, count, result);
    }
};
