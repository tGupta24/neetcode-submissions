class Solution {
public:
    bool valid(unordered_map<char,int>&mp){
        for(auto &i:mp){
            if(i.second>0) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char,int>mp;
        int len= INT_MAX;
        int start = 0;
        for(auto i:t){
            mp[i]++;
        }
        int i=0;
        int j=0;

        int mapsize = mp.size();

        while(j<n){
            if(mp.count(s[j])){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    mapsize--;
                }
            }

            while(mapsize==0){
                if(len>j-i+1){
                len = j-i+1;
                start = i;
                }
                    
                if(mp.count(s[i])){
                    mp[s[i]]++;
                    if(mp[s[i]]>0){
                        mapsize++;
                    }
                    
                }
                i++;
            }
            j++;
        }
        if(len == INT_MAX) return "";
        return s.substr(start,len);
    }
};


// x1
// y1
// z1


// OUZODYXAZV
//       j
//    i
// while(valid){
//     shrink
// }