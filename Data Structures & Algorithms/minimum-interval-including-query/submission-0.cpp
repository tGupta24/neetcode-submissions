class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& range, vector<int>& q) {
        int n = q.size();
        int m = range.size();

        vector<int>ans(n,-1);

        for(int i=0; i<n; i++){
            int val = INT_MAX;
            for(int j = 0; j<m; j++){
               if(range[j][0] <=q[i] && range[j][1]>=q[i]){
                  val =min(val,range[j][1]-range[j][0]+1);
               }
             }
            if(val!=INT_MAX)
            ans[i] = val;
        }
        return ans;
    }
};
