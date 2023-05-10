class Solution {
public:
int countNodes(TreeNode* root) {
if(!root) return 0;
int lh = 0, rh = 0;
TreeNode *l = root, *r = root;
while(l) {
l = l->left;
lh++;
}
while(r) {
r = r->right;
rh++;
}
if(lh == rh) return pow(2, lh) - 1;
return 1 + countNodes(root->left) + countNodes(root->right);
}
};