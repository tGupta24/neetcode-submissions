class Solution {
public:
    int n;
    vector<int>dp;
    bool f(int i,string s,unordered_set<string>&words){
        // bae case
        if(i>=n){
            return true;
        }

        if(dp[i]!=-1) return dp[i];

        bool isFound = false;
        string str = "";
        for(int j=i; j<n; j++){
            str += s[j];
            if(words.count(str) && f(j+1,s,words)){
                return dp[i] = true;
            }
        }
        return  dp[i] = false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
         n = s.size();
         dp.assign(n,-1);
        unordered_set<string>words(wordDict.begin(),wordDict.end());
        return f(0,s,words);
    }
};
