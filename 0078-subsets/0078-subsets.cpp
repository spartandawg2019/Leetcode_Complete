class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(nums, 0, subset, res);
        return res;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& res) {
        res.push_back(subset);
        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            backtrack(nums, i + 1, subset, res);
            subset.pop_back();
        }
    }
};
