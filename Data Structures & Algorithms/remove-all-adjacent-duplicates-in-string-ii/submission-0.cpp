class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();

        vector<pair<char,int>>vp;

        for(int i=0; i<n; i++){
            if(vp.empty() || vp.back().first!=s[i]){
                vp.push_back({s[i],1});
            } else{
                vp.back().second++;

                if(vp.back().second==k){
                    vp.pop_back();
                }
            }
        }
         string res;
        for (auto& p : vp) {
            res.append(p.second, p.first);
        }
        return res;
    }
};