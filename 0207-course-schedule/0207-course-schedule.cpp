class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<bool> todo(numCourses, false), done(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!done[i] && !acyclic(g, todo, done, i)) {
                return false;
            }
        }
        return true;
    }
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p[1]].push_back(p[0]);
        }
        return g;
    }
    
    bool acyclic(graph& g, vector<bool>& todo, vector<bool>& done, int u) {
        if (todo[u]) {
            return false;
        }
        if (done[u]) {
            return true;
        }
        todo[u] = done[u] = true;
        for (int v : g[u]) {
            if (!acyclic(g, todo, done, v)) {
                return false;
            }
        }
        todo[u] = false;
        return true;
    }
};
