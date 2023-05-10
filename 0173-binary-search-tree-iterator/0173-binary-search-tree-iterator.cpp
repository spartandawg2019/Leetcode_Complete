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
class BSTIterator {
public:
BSTIterator(TreeNode* root) {
// initialize the stack with all left nodes of the tree
while (root) {
s.push(root);
root = root->left;
}
}
int next() {
    // get the next smallest element
    TreeNode* curr = s.top();
    s.pop();
    int val = curr->val;
    
    // if there's a right child, add all left nodes of the right child
    curr = curr->right;
    while (curr) {
        s.push(curr);
        curr = curr->left;
    }
    
    return val;
}

bool hasNext() {
    return !s.empty();
}
private:
stack<TreeNode*> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */