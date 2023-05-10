class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        for (int i = 1; i <= 3; i++) {
            for (int j = i + 1; j <= i + 3; j++) {
                for (int k = j + 1; k <= j + 3; k++) {
                    if (k < s.length()) {
                        string s1 = s.substr(0, i), s2 = s.substr(i, j - i), s3 = s.substr(j, k - j), s4 = s.substr(k);
                        if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)) {
                            ans.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                        }
                    }
                }
            }
        }
        return ans;
    }
    bool isValid(string s) {
    if (s.length() > 3 || s.length() == 0 || (s[0] == '0' && s.length() > 1) || stoi(s) > 255) return false;
    return true;
    }
};
