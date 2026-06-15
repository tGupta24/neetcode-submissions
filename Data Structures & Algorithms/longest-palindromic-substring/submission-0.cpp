class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int maxi = INT_MIN;
        int start = 0;
        for(int len =1 ; len<=n; len++){
            for(int i=0; i<n-len+1; i++){
                int j = len + i -1;

                if(len==1){
                    dp[i][j] =1;
                }else if(len==2){
                    dp[i][j] = (s[i]==s[j]);
                } else{
                    dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
                }

                if(dp[i][j]==1){
                    maxi = max(maxi,len);
                    start = i;
                }
            }
        }
        return s.substr(start,maxi);
    }
};

