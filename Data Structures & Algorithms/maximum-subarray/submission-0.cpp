class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int bestAti = 0;
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++){
            int v1 = bestAti + nums[i];
            int v2 = nums[i];

            bestAti = max(v1,v2);
            ans = max(ans,bestAti);
        }
        return ans;
    }
};
