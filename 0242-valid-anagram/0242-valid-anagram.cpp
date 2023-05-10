class Solution {
public:
    bool isAnagram(string s, string t) {
        // Initialize a hash table to store the frequency of each character
        unordered_map<char, int> freq;
        // Iterate through the first string and increase the frequency of each character
        for (char c : s) {
            freq[c]++;
        }
        // Iterate through the second string and decrease the frequency of each character
        for (char c : t) {
            if (freq.find(c) == freq.end() || freq[c] == 0) {
                return false;
            }
            freq[c]--;
        }
        // Iterate through the hash table and check if all the frequencies are zero
        for (auto pair : freq) {
            if (pair.second != 0) {
                return false;
            }
        }
        return true;
    }
};
