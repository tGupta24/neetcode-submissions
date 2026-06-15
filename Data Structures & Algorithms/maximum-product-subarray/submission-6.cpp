class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        int mini = 1;
        int ans = INT_MIN;

        for(int i=0; i<n; i++){
            int v1 = maxi*nums[i];
            int v2 = mini*nums[i];
            int v3 = nums[i];

            maxi = max({v1,v2,v3});
            mini = min({v1,v2,v3});

            ans = max({ans,maxi,mini});
        }
        return ans;
    }
};
