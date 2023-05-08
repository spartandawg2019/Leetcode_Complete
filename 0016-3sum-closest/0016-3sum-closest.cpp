class Solution {
public:
int threeSumClosest(vector<int>& nums, int target) {
int closest = INT_MAX;
int res = 0;
sort(nums.begin(), nums.end());
for (int i = 0; i < nums.size(); i++) {
int left = i + 1, right = nums.size() - 1;
while (left < right) {
int sum = nums[i] + nums[left] + nums[right];
if (sum == target) {
return sum;
} else if (sum < target) {
left++;
} else {
right--;
}
if (abs(sum - target) < closest) {
closest = abs(sum - target);
res = sum;
}
}
}
return res;
}
};