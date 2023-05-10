class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        for (int num : nums) {
            if (!s.count(num - 1)) {
                int currentNum = num;
                int currentLength = 1;
                while (s.count(currentNum + 1)) {
                    currentNum++;
                    currentLength++;
                }
                longest = max(longest, currentLength);
            }
        }
        return longest;
    }
};
