class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        visited[0] = true;
        stack<int> st;
        st.push(0);
        while (!st.empty()) {
            int room = st.top();
            st.pop();
            for (int key : rooms[room]) {
                if (!visited[key]) {
                    st.push(key);
                    visited[key] = true;
                }
            }
        }
        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }
};
