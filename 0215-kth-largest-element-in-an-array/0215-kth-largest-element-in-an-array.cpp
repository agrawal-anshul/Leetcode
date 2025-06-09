class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>mh;  //minHeap
        for(auto x:nums){
            mh.push(x);
        }

        while(mh.size()>k){
            mh.pop();
        }
        return mh.top();
        
    }
};