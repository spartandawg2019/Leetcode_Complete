class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> levelNodes;
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                levelNodes.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (level % 2 == 1) reverse(levelNodes.begin(), levelNodes.end());
            result.push_back(levelNodes);
            level++;
        }
        return result;
    }
};
