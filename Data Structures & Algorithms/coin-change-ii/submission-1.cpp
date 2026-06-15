class Solution {
public:
    vector<vector<int>>dp;
    int f(int amount,int n,vector<int>&coins){
        // base 
        if(amount==0) return 1;
        if(n==0){
            if(amount==0) return 1;
            return 0;
        }
        if(dp[amount][n]!=-1) return dp[amount][n]; 
        int take = 0;
        if(amount-coins[n-1]>=0) {
            take = f(amount-coins[n-1],n,coins);
        }
        int skip = f(amount,n-1,coins);
        return  dp[amount][n]  = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(amount+1,vector<int>(n+1,-1));
        return f(amount,n,coins);
    }
};



