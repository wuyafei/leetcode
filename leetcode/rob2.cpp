class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size()==1)
            return nums[0];
        int max0=rob_helper(nums,0,nums.size()-2);
        int maxn=rob_helper(nums, 1, nums.size()-1);
        return max0>maxn?max0:maxn;
    }
private:
    int rob_helper(vector<int> &nums, int l, int h){
        if(l==h)
            return nums[l];
        if(l+1==h)
            return nums[l]>nums[h]?nums[l]:nums[h];
        int max_1=nums[l+1];
        int max_2=nums[l];
        for(int i=l+2;i<=h;i++){
            int tmp=max_2+nums[i];
            if(max_1>max_2)
                max_2=max_1;
            if(tmp>max_1)
                max_1=tmp;
        }
        return max_1;
    }
};