class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_freq;
        int t_size = t.size();
        int s_size = s.size();
        for(int i = 0; i < t_size; i++)
            t_freq[t[i]]++;
        
        int left = 0, right = 0, required = t_freq.size(), formed = 0;
        unordered_map<char, int> s_freq;
        int ans = INT_MAX, start = 0;
        
        while(right < s_size) {
            char c = s[right];
            if(t_freq.count(c)) {
                s_freq[c]++;
                if(s_freq[c] == t_freq[c])
                    formed++;
            }
            right++;
            
            while(required == formed) {
                if(right - left < ans) {
                    ans = right - left;
                    start = left;
                }
                char d = s[left];
                if(t_freq.count(d)) {
                    s_freq[d]--;
                    if(s_freq[d] < t_freq[d])
                        formed--;
                }
                left++;
            }
        }
        return ans == INT_MAX ? "" : s.substr(start, ans);
    }
};
