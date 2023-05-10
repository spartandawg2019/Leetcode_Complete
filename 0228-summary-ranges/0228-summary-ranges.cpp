#include <vector>
#include <string>
#include <sstream>

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if (n == 0) return res;
        int start = nums[0], end = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                end = nums[i];
            } else {
                if (start == end) {
                    res.push_back(to_string(start));
                } else {
                    stringstream ss;
                    ss << start << "->" << end;
                    res.push_back(ss.str());
                }
                start = end = nums[i];
            }
        }
        if (start == end) {
            res.push_back(to_string(start));
        } else {
            stringstream ss;
            ss << start << "->" << end;
            res.push_back(ss.str());
        }
        return res;
    }
};
