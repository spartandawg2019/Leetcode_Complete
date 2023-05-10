class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0, count = 0;
        for (; j < nums.size(); j++) {
            if (j > 0 && nums[j] == nums[j - 1]) {
                count++;
            } else {
                count = 1;
            }
            if (count <= 2) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};
