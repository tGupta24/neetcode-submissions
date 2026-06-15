class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int res = 0;
        for(int len = 1; len<=n; len++){
            for(int i=0; i<n-len+1; i++){
                int j = i + len -1;
                if(len==1){
                    res++;
                    dp[i][j] = true;
                } else if(len==2 && s[i]==s[j]){
                    res++;
                    dp[i][j]=true;
                } else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j] = true;
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
