class Solution {
public:
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
unordered_set<string> wordSet(wordList.begin(), wordList.end());
if (wordSet.count(endWord) == 0) return 0;
unordered_map<string, int> dist;
dist[beginWord] = 1;
queue<string> q{{beginWord}};
while (!q.empty()) {
auto t = q.front();
q.pop();
for (int i = 0; i < t.size(); ++i) {
auto str = t;
for (char ch = 'a'; ch <= 'z'; ++ch) {
str[i] = ch;
if (wordSet.count(str) && str == endWord) return dist[t] + 1;
if (wordSet.count(str) && !dist.count(str)) {
dist[str] = dist[t] + 1;
q.emplace(str);
}
}
}
}
return 0;
}
};



