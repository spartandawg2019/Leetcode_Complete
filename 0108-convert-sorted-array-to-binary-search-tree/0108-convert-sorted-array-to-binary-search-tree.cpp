class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        int middle = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[middle]);
        vector<int> left(nums.begin(), nums.begin() + middle);
        vector<int> right(nums.begin() + middle + 1, nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};
