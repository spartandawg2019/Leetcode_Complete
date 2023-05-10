class Solution {
    bool isScramble(string s1, string s2, int i, int j, int len, vector<vector<vector<int>>> &dp) {
        if (dp[i][j][len] != -1) return dp[i][j][len];
        if (s1.substr(i, len) == s2.substr(j, len)) return dp[i][j][len] = 1;
        string t1 = s1.substr(i, len), t2 = s2.substr(j, len);
        sort(t1.begin(), t1.end()); sort(t2.begin(), t2.end());
        if (t1 != t2) return dp[i][j][len] = 0;
        for (int k = 1; k < len; k++) {
            if (isScramble(s1, s2, i, j, k, dp) && isScramble(s1, s2, i + k, j + k, len - k, dp)) return dp[i][j][len] = 1;
            if (isScramble(s1, s2, i, j + len - k, k, dp) && isScramble(s1, s2, i + k, j, len - k, dp)) return dp[i][j][len] = 1;
        }
        return dp[i][j][len] = 0;
    }
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int n = s1.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return isScramble(s1, s2, 0, 0, n, dp);
    }
};
