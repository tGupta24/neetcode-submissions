class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }

        int m = nums1.size(); // smaller
        int n = nums2.size();

        // bs on smaller nums


        int l = 0;
        int r = m;
        int firstHalf = (m+n+1)/2;

        while(l<=r){
            int px = l + (r-l)/2; // from nums1
            int py = firstHalf - px; // from nums2;

            int x1 = (px==0)?INT_MIN:nums1[px-1]; 
            int x2 = (py==0)?INT_MIN:nums2[py-1];
            int x3 = (px==m)?INT_MAX:nums1[px];
            int x4 = (py==n)?INT_MAX:nums2[py];

            if(x1<=x4 && x2<=x3){
                if((m+n)&1){
                    return max(x1,x2);
                } else{
                    return (max(x1,x2) + min(x3,x4))/2.0;
                }
            }

            if(x1>x4){
                r = px-1; // dec the num of elemnet in first half from the nums1
            } else if(x2>x3){
                l = px+1;
            }
        }

        return -1;
    }
};
