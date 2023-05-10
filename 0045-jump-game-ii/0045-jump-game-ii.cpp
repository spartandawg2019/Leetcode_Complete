class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int currMax = 0, nextMax = 0, jumps = 0;
        for (int i = 0; i < n; i++) {
            if (i > currMax) {
                jumps++;
                currMax = nextMax;
            }
            nextMax = max(nextMax, i + nums[i]);
        }
        return jumps;
    }
};
