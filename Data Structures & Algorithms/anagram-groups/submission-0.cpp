class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>>mp;
        for(int i=0; i<n; i++){
            string s = strs[i];
            string sorteds = s;
            sort(sorteds.begin(),sorteds.end());
            mp[sorteds].push_back(s);
        }

        vector<vector<string>>ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;


    }
};
