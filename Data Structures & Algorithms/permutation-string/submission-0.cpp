class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        unordered_map<char,int>mp;

        for(auto  ch:s1 ){
            mp[ch]++;
        }

        int i=0;
        int j=s1.size()-1;
        for(int k=0; k<=j; k++){
           mp[s2[k]]--;
        }

        while(j<n){
            bool flag = true;
            for(auto k:mp){
                if(k.second!=0){
                    flag = false;
                }
            }
            if(flag) return true;

            for(auto i:mp){
                cout<<i.first<<" "<<i.second<<endl;
            }
            cout<<endl;
            j++;
            mp[s2[j]]--;
            mp[s2[i]]++;
            i++;
        }
        return false;
    }

};


// a0
// b0
// c0
// l0
// e0

