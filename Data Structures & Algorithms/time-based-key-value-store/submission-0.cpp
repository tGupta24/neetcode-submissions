class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        int n = mp[key].size();
        int s = 0;
        int e = n-1;
        string ans  = "";
        while(s<=e){
            int mid = s + (e-s)/2;

            if(mp[key][mid].second <= timestamp){
                ans = mp[key][mid].first;
                s = mid+1;
            } else{
                e = mid-1;
            }
        }
        return ans;
    }
};
