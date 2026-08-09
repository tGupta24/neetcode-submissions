class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            mp[nums1[i]] = i;
        }
        int m = nums2.size();
        vector<int> ans(n, -1);
        stack<int> st;  // indices
        for (int i = m - 1; i >= 0; i--) {
            while (!st.empty() && nums2[st.top()] < nums2[i]) {
                st.pop();
            }

            if (!st.empty()) {
                if (mp.count(nums2[i])) ans[mp[nums2[i]]] = nums2[st.top()];
            }

            st.push(i);
        }
        return ans;
    }
};