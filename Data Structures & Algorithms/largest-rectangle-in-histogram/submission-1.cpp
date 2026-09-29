class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int mx = 0, n = heights.size();
        for (int i = 0; i <= n; i++) {
            int h = (i == n ? 0 : heights[i]);
            while (!st.empty() && heights[st.top()] > h) {
                int height = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;
                mx = max(mx, height * width);
            }
            st.push(i);
        }
        return mx;
    }
};