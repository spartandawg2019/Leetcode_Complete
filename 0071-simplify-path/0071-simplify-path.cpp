class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs = split(path, '/');
        stack<string> stk;
        for (string dir : dirs) {
            if (dir == "." || dir == "") continue;
            else if (dir == "..") {
                if (!stk.empty()) stk.pop();
            } else {
                stk.push(dir);
            }
        }
        string ans = "";
        while (!stk.empty()) {
            ans = "/" + stk.top() + ans;
            stk.pop();
        }
        return ans.empty() ? "/" : ans;
    }
private:
    vector<string> split(string s, char delim) {
        vector<string> res;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            res.push_back(item);
        }
        return res;
    }
};
