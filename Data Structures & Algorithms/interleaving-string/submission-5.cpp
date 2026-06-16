class Solution {
public:
    vector<vector<int>>dp;
    int n,m;
    bool f(int i,int j,string a,string b,string final){
        // base ccase
        if((i+j)>=final.size()){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool option1 = false;
        bool option2 = false;
        if(final[i+j]==a[i]){
            option1 = f(i+1,j,a,b,final);
        }
        if(final[i+j]==b[j]){
            option2 = f(i,j+1,a,b,final);
        }

        return dp[i][j] = (option1 || option2);
    }
    bool isInterleave(string a, string b, string final) { 
        n = a.size();
        m = b.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        if(a.size() + b.size() != final.size()){
            return false;
        }
        return f(0,0,a,b,final);
    }
};
