class Solution {
public:
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
vector<vector<int>> result;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> min_heap;
int m = nums1.size(), n = nums2.size();
if (m == 0 || n == 0 || k == 0) {
return result;
}
for (int i = 0; i < min(k, n); i++) {
min_heap.push({nums1[0] + nums2[i], {0, i}});
}
while (k > 0 && !min_heap.empty()) {
auto [sum, indices] = min_heap.top();
min_heap.pop();
int i = indices.first, j = indices.second;
result.push_back({nums1[i], nums2[j]});
if (i + 1 < m) {
min_heap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
}
k--;
}
return result;
}
};