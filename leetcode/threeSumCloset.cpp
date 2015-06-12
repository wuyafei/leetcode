class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int gap=1<<31-1;
        int rt=0;
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int tmp=nums[j]+nums[k]+nums[i];
                if(tmp == target) return target;
                else if(tmp>target){
                    if(gap>tmp-target){
                        gap=tmp-target;
                        rt=tmp;
                    }
                    k--;
                }
                else{
                    if(gap>target-tmp){
                        gap=target-tmp;
                        rt=tmp;
                    }
                    j++;
                }
            }
        }
        return rt;
    }
};