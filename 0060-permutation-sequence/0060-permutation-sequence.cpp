class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        int fact = 1;
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        k--;
        for (int i = n - 1; i >= 0; i--) {
            fact /= (i + 1);
            int idx = k / fact;
            k %= fact;
            result += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);
        }
        return result;
    }
};
