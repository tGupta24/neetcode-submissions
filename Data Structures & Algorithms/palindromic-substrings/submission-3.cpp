class Solution {
public:
    int len(int i,int j,string &s){
        int cnt =0;
        while(i>=0 && j<s.size()){
            
            if(s[i]==s[j]){
                i--;
                j++;
                cnt++;
            } else{
                break;
            }
        }
        return cnt;
        
    }
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        for(int i=0; i<n; i++){
            res += len(i,i,s)+len(i,i+1,s); 
        }
        return res;
    }
};
