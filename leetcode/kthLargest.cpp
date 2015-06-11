class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q(nums.begin(), nums.begin()+k);
        for(auto itr=nums.begin()+k;itr!=nums.end();itr++){
            if(*itr>q.top()){
                q.pop();
                q.push(*itr);
            }
        }
        return q.top();
    }
};