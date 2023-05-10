class Solution {
public:
int minSubArrayLen(int target, vector<int>& nums) {
int n = nums.size();
int l = 0, r = 0;
int cur_sum = 0, min_len = INT_MAX;
while (r < n) {
cur_sum += nums[r];
while (cur_sum >= target) {
min_len = min(min_len, r - l + 1);
cur_sum -= nums[l];
l++;
}
r++;
}
return min_len == INT_MAX ? 0 : min_len;
}
};