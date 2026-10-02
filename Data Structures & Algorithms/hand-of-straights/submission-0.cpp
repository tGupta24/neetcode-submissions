class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize) return false;


        map<int,int>mp;
        for(auto i:hand){
            mp[i]++;
        }

        while(!mp.empty()){
            int val = mp.begin()->first;

            for(int i=val; i<val + groupSize; i++){
                if(!mp.count(i)){
                    return false;
                } else{
                    mp[i]--;
                    if(mp[i]==0){
                        mp.erase(i);
                    }
                }
            }
        }
        return true;
    }
};
