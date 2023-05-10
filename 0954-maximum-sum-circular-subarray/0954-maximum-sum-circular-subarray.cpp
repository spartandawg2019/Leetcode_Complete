class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int total = 0, maxSum = INT_MIN, curMax = 0, minSum = INT_MAX, curMin = 0;
        for (int i = 0; i < n; i++) {
            curMax = max(nums[i], curMax + nums[i]);
            maxSum = max(maxSum, curMax);
            curMin = min(nums[i], curMin + nums[i]);
            minSum = min(minSum, curMin);
            total += nums[i];
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};
