class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;
        int r= 0;
        int steps = 0;
        for(int i=0; i<n; i++){
            if(maxReach<i){
                maxReach = r;
                steps++;
            }
            r = max(r,i + nums[i]);
        }
        return steps;
    }
};
