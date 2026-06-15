class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>>mp;
        for(int i=0; i<n; i++){
            string s = strs[i];
            vector<int>vec(26,0);
            for(int i=0; i<s.size(); i++){
                int ch = s[i]-'a';
                vec[ch]++;
            }
            string key = "";
            for(auto i:vec){
                key += to_string(i) + "#";
            }
            mp[key].push_back(s);
        }

        vector<vector<string>>ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
