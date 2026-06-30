class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> fr(256, 0);

        int i = 0;
        int ans = 0;

        for (int j = 0; j < s.size(); j++) {

            fr[s[j]]++;

            while (fr[s[j]] > 1) {
                fr[s[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};