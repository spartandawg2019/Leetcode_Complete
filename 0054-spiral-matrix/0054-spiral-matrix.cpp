class Solution {
public:
vector<int> spiralOrder(vector<vector<int>>& matrix) {
vector<int> res;
if (matrix.empty()) return res;
int m = matrix.size(), n = matrix[0].size();
int up = 0, down = m - 1, left = 0, right = n - 1;
while (true) {
for (int j = left; j <= right; j++) res.push_back(matrix[up][j]);
if (++up > down) break;
for (int i = up; i <= down; i++) res.push_back(matrix[i][right]);
if (--right < left) break;
for (int j = right; j >= left; j--) res.push_back(matrix[down][j]);
if (--down < up) break;
for (int i = down; i >= up; i--) res.push_back(matrix[i][left]);
if (++left > right) break;
}
return res;
}
};