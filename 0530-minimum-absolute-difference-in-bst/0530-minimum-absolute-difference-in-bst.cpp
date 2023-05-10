class Solution {
public:
int getMinimumDifference(TreeNode* root) {
int res = INT_MAX;
stack<TreeNode*> s;
TreeNode* cur = root;
int pre = -1;
while (cur || !s.empty()) {
while (cur) {
s.push(cur);
cur = cur->left;
}
cur = s.top();
s.pop();
if (pre != -1)
res = min(res, cur->val - pre);
pre = cur->val;
cur = cur->right;
}
return res;
}
};