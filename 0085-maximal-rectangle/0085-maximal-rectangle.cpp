class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> h(n, 0);
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') h[j]++;
                else h[j] = 0;
            }
            res = max(res, largestRectangleArea(h));
        }
        return res;
    }
    int largestRectangleArea(vector<int>& h) {
        h.push_back(0);
        int n = h.size();
        stack<int> s;
        int res = 0;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && h[s.top()] > h[i]) {
                int j = s.top(); s.pop();
                res = max(res, h[j] * (s.empty() ? i : (i - s.top() - 1)));
            }
            s.push(i);
        }
        return res;
    }
};
