class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
int n = heights.size();
stack<int> st;
int max_area = 0;
for(int i = 0; i <= n; i++) {
int h = (i == n ? 0 : heights[i]);
while(!st.empty() && h < heights[st.top()]) {
int height = heights[st.top()];
st.pop();
int width = (st.empty() ? i : i - st.top() - 1);
max_area = max(max_area, height * width);
}
st.push(i);
}
return max_area;
}
};