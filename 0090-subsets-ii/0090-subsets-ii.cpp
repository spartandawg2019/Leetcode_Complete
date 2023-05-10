class Solution {
public:
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
sort(nums.begin(), nums.end());
vector<vector<int>> result;
vector<int> subset;
backtrack(nums, subset, result, 0);
return result;
}
private:
void backtrack(vector<int>& nums, vector<int>& subset, vector<vector<int>>& result, int start) {
result.push_back(subset);
for (int i = start; i < nums.size(); i++) {
if (i > start && nums[i] == nums[i - 1]) continue; //skip duplicates
subset.push_back(nums[i]);
backtrack(nums, subset, result, i + 1);
subset.pop_back();
}
}
};

