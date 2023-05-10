class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (find(current.begin(), current.end(), nums[i]) != current.end()) continue;
            current.push_back(nums[i]);
            backtrack(nums, current, result);
            current.pop_back();
        }
    }
};
