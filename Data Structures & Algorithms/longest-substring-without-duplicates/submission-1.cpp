class Solution {
public:
    bool isInvalid(unordered_map<char,int>&fr){
        for(auto i:fr){
            if(i.second>1) return true;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        int i =0;
        int j = 0;

        int n = s.size();
        unordered_map<char,int>fr;
        int ans = 0;

        while(j<n){
            fr[s[j]-'a']++;

            while(isInvalid(fr)){
                fr[s[i]-'a']--;
                i++;
            }

            ans = max(ans,j-i+1);
            j++;
        }
      
        return ans;
    }
};
