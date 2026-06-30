class Solution {
   public:
    int n;
    vector<int> nse(vector<int>& h) {
        stack<int> st;
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && h[st.top()] >= h[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = n;
            } else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }
    vector<int> pse(vector<int>& h) {
        stack<int> st;
        vector<int> ans(n, 0);
        for (int i = 0; i <n; i++) {
            while (!st.empty() && h[st.top()] >= h[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        n = heights.size();
        vector<int> nextSmaller = nse(heights);
        vector<int> prevSmaller = pse(heights);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, (nextSmaller[i] - prevSmaller[i] - 1) * heights[i]);
        }
        return ans;
    }
};

// 7 1 7 2 2 4

//     | | | | | | | | | | | | | | | | | | | | | | | -1 0 1 2 3 4 5 6
