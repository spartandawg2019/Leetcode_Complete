class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int pivotIndex = partition(nums, left, right);
            if (pivotIndex == k - 1) {
                return nums[pivotIndex];
            } else if (pivotIndex > k - 1) {
                right = pivotIndex - 1;
            } else {
                left = pivotIndex + 1;
            }
        }
        return -1;
    }

private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int i = left + 1;
        int j = right;
        while (i <= j) {
            if (nums[i] < pivot && nums[j] > pivot) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if (nums[i] >= pivot) i++;
            if (nums[j] <= pivot) j--;
        }
        swap(nums[left], nums[j]);
        return j;
    }
};
