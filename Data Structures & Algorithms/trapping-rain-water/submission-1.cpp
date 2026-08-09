class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int leftMax = height[l];
        int rightMax = height[r];
        int ans = 0;
        while(l<r){
            if(leftMax<rightMax){
                l++;
                leftMax = max(leftMax,height[l]);
                ans += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax,height[r]);
                ans += rightMax- height[r];
            }
        }
        return ans;
    }
};
