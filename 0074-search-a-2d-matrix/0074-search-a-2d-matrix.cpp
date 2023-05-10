class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
if(matrix.empty() || matrix[0].empty()) return false;
int m = matrix.size(), n = matrix[0].size();
int l = 0, r = m * n - 1;
while(l <= r) {
int mid = l + (r - l) / 2;
int midX = mid / n, midY = mid % n;
if(matrix[midX][midY] == target) return true;
else if(matrix[midX][midY] < target) l = mid + 1;
else r = mid - 1;
}
return false;
}
};