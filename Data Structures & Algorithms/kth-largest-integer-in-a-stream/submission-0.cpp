class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>minHeap;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto i:nums)
         minHeap.push(i);
    }
    
    int add(int val) {
        minHeap.push(val);
        while(minHeap.size()>K){
            minHeap.pop();
        }
        return minHeap.top();
    }
};
