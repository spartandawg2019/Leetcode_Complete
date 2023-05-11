class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return NULL;
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        int k = 0;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootVal) {
                k = i;
                break;
            }
        }
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + (k - inStart), inorder, inStart, k - 1);
        root->right = buildTreeHelper(preorder, preStart + (k - inStart) + 1, preEnd, inorder, k + 1, inEnd);
        return root;
    }
};
 