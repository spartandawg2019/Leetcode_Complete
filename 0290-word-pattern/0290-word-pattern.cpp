class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map;
        unordered_map<string, char> rmap;
        stringstream ss(s);
        string word;
        int i = 0;
        while (ss >> word) {
            if (map.count(pattern[i]) && map[pattern[i]] != word) return false;
            if (rmap.count(word) && rmap[word] != pattern[i]) return false;
            map[pattern[i]] = word;
            rmap[word] = pattern[i];
            i++;
        }
        return i == pattern.size();
    }
};
