class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> dp(n, 0);
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (dfs(graph, dp, i)) {
                res.push_back(i);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& dp, int node) {
        if (dp[node] != 0) {
            return dp[node] == 1;
        }
        dp[node] = 2;
        for (int next : graph[node]) {
            if (!dfs(graph, dp, next)) {
                return false;
            }
        }
        dp[node] = 1;
        return true;
    }
};
