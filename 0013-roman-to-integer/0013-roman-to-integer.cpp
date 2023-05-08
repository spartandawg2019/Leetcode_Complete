class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            int value = roman_map[s[i]];
            if (i + 1 < s.length() && value < roman_map[s[i + 1]]) {
                result -= value;
            } else {
                result += value;
            }
        }
        return result;
    }
};
