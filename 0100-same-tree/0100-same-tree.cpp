class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base case: both nodes are null
        if (!p && !q) return true;
        // base case: one node is null, the other isn't
        if (!p || !q) return false;
        // base case: both nodes have different values
        if (p->val != q->val) return false;
        // recursively check the left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
