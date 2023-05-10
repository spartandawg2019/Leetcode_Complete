class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Create graph
        unordered_map<string, int> varIndex;
        int index = 0;
        for (auto& eq : equations) {
            string v1 = eq[0];
            string v2 = eq[1];
            if (!varIndex.count(v1)) varIndex[v1] = index++;
            if (!varIndex.count(v2)) varIndex[v2] = index++;
        }
        vector<vector<pair<int, double>>> graph(index);
        for (int i = 0; i < equations.size(); i++) {
            string v1 = equations[i][0];
            string v2 = equations[i][1];
            int i1 = varIndex[v1];
            int i2 = varIndex[v2];
            double val = values[i];
            graph[i1].push_back({i2, val});
            graph[i2].push_back({i1, 1 / val});
        }
        // Answer queries
        vector<double> ans;
        for (auto& q : queries) {
            string v1 = q[0];
            string v2 = q[1];
            if (!varIndex.count(v1) || !varIndex.count(v2)) {
                ans.push_back(-1.0);
                continue;
            }
            int i1 = varIndex[v1];
            int i2 = varIndex[v2];
            unordered_set<int> visited;
            double res = dfs(graph, i1, i2, 1.0, visited);
            ans.push_back(res);
        }
        return ans;
    }
    
    double dfs(vector<vector<pair<int, double>>>& graph, int curr, int dest, double val, unordered_set<int>& visited) {
        if (curr == dest) return val;
        visited.insert(curr);
        for (auto& neigh : graph[curr]) {
            int next = neigh.first;
            double nextVal = neigh.second;
            if (visited.count(next)) continue;
            double res = dfs(graph, next, dest, val * nextVal, visited);
            if (res != -1.0) return res;
        }
        return -1.0;
    }
};
