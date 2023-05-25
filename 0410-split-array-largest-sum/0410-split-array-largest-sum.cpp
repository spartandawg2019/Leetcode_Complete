class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int numSubarrays = 1;
            int sum = 0;
            for (int num : nums) {
                sum += num;
                if (sum > mid) {
                    numSubarrays++;
                    sum = num;
                }
            }
            if (numSubarrays > k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return right;
    }
};
