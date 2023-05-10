class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out;
        backtrack(n, k, 1, out, res);
        return res;
    }
    
    void backtrack(int n, int k, int start, vector<int>& out, vector<vector<int>>& res) {
        if (out.size() == k) {
            res.push_back(out);
            return;
        }
        for (int i = start; i <= n; i++) {
            out.push_back(i);
            backtrack(n, k, i + 1, out, res);
            out.pop_back();
        }
    }
};