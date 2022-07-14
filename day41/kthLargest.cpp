class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto it : nums) pq.push(it);
        
        int remove = k-1;
        while(remove--){
            pq.pop();
        }
        return pq.top();
    }
};
