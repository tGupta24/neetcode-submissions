class Solution {
public:
    vector<vector<vector<int>>>dp;
    int n,m;
    bool f(int i,int j,int k,string a,string b,string final){
        // base ccase
        if(i>=a.size() && j>=b.size()){
            return true;
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        bool option1 = false;
        bool option2 = false;
        if(final[k]==a[i]){
            option1 = f(i+1,j,k+1,a,b,final);
        }
        if(final[k]==b[j]){
            option2 = f(i,j+1,k+1,a,b,final);
        }

        return dp[i][j][k] = (option1 || option2);
    }
    bool isInterleave(string a, string b, string final) { 
        n = a.size();
        m = b.size();
        dp.assign(n+1,vector<vector<int>>(m+1,vector<int>(n+m+2,-1)));
        if(a.size() + b.size() != final.size()){
            return false;
        }
        return f(0,0,0,a,b,final);
    }
};
