class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(candidates, target, result, combination, 0);
        return result;
    }

    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& combination, int start) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) break;
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], result, combination, i + 1);
            combination.pop_back();
        }
    }
};
