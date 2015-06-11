class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0)
            return false;
        unordered_set<int> s;
        s.insert(nums[0]);
        for(auto itr=nums.begin()+1;itr!=nums.end();itr++){
            if(s.count(*itr)>0)
                return true;
            else
                s.insert(*itr);
        }
        return false;
    }
};