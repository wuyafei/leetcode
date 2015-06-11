class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> rslt={{}};
        sort(nums.begin(), nums.end());
        int n=nums.size();
        for(int i=0;i<n;){
            int cnt=1;
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j])
                    cnt++;
                else
                    break;
            }
            int m=rslt.size();
            for(int j=0;j<m;j++){
                vector<int> v=rslt[j];
                for(int k=0;k<cnt;k++){
                    v.push_back(nums[i]);
                    rslt.push_back(v);
                }
            }
            i+=cnt;
        }
        return rslt;
    }
};