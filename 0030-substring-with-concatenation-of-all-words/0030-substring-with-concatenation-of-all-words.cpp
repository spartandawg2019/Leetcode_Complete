class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        int m = words.size();
        int wl = words[0].length();

        unordered_map<string, int> permutations;
        for (int i = 0; i < m; i++) {
            permutations[words[i]]++;
        }

        vector<int> result;
        for (int i = 0; i <= n - m * wl; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < m; j++) {
                string word = s.substr(i + j * wl, wl);
                if (permutations.find(word) != permutations.end()) {
                    seen[word]++;
                    if (seen[word] > permutations[word]) break;
                } else break;
            }
            if (j == m) result.push_back(i);
        }
        return result;
    }
};
