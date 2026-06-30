class Solution {
public:

    vector<int> minInterval(vector<vector<int>>& inter, vector<int>& q) {
        int n = inter.size();
        int m = q.size();

        vector<vector<int>>events;
        for(int i=0; i<n; i++){
            events.push_back({inter[i][0],0,inter[i][1]-inter[i][0] + 1,i});
            events.push_back({inter[i][1],2,inter[i][1]-inter[i][0] + 1,i});
        }

        for(int i=0; i<m; i++){
            events.push_back({q[i],1,i});
        }

    
        sort(events.begin(),events.end());

        vector<int>ans(m,-1);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>inactive(n,0);
        for(auto event:events){
            if(event[1]==0){  // start
                pq.push({event[2],event[3]}); 
            } else if(event[1]==2){
                inactive[event[3]] = 1;
            } else {
                int qi = event[2];

                while(!pq.empty() && inactive[pq.top().second]){
                    pq.pop();
                }

                if(!pq.empty()){
                    ans[qi] = pq.top().first; // length
                }
            }
        }
        return ans;
    }
};
