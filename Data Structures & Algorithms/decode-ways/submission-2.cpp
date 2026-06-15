class Solution {
public:
    vector<int>dp;
    int f(int i,string s){
        // basecase
        if(i>=s.size()) return 1;
        if(s[i]=='0') return 0;

        if(dp[i]!=-1) return dp[i]; 
        int res = 0;
        int ans = 0;
        for(int j = i; j<s.size(); j++){
            res = res*10 + s[j]-'0';
            if(res >=1 && res<=26)
               ans += f(j+1,s);
        }
        return  dp[i] = ans;
    } 
    int numDecodings(string s) {
        int n = s.size();
        dp.assign(n,-1);
        return f(0,s);
    }
};
