class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 3) return n;
        int res = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<string, int> m;
            int same = 1, ver = 0;
            for (int j = i + 1; j < n; j++) {
                if (points[j][0] == points[i][0] && points[j][1] == points[i][1]) {
                    same++;
                } else if (points[j][0] == points[i][0]) {
                    ver++;
                } else {
                    int dy = points[j][1] - points[i][1], dx = points[j][0] - points[i][0];
                    int g = __gcd(dx, dy);
                    dy /= g, dx /= g;
                    m[to_string(dy) + ":" + to_string(dx)]++;
                }
            }
            res = max(res, ver + same);
            for (auto& [k, v] : m) {
                res = max(res, v + same);
            }
        }
        return res;
    }
};
