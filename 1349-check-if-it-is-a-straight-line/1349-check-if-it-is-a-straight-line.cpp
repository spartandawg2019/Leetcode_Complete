class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) return true;
        int x1 = coordinates[0][0], y1 = coordinates[0][1], x2 = coordinates[1][0], y2 = coordinates[1][1];
        double slope = (x2 - x1) == 0 ? INT_MAX : 1.0 * (y2 - y1) / (x2 - x1);
        for (int i = 2; i < coordinates.size(); i++) {
            x2 = coordinates[i][0], y2 = coordinates[i][1];
            double curSlope = (x2 - x1) == 0 ? INT_MAX : 1.0 * (y2 - y1) / (x2 - x1);
            if (curSlope != slope) return false;
        }
        return true;
    }
};
