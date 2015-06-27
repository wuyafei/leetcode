class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        vector<vector<int>> rt;
        perm(0, nums, rt);
        return rt;
        
    }
private:
    void perm(int k, vector<int> &num, vector<vector<int> > &vec){
        if (k == num.size()-1){
            vec.push_back(num);
        }
        else{
            for (int i = k; i < num.size(); i++){
                bool flag=false;
                for(int j=i-1;j>=k;j--){
                    if(num[i]==num[j]){
                        flag=true;
                        break;
                    }
                }
                if(flag) continue;
                swap(i, k, num);
                perm(k + 1, num, vec);
                swap(i, k, num);
            }
        }
    }
    void swap(int i, int j, vector<int> &v){
        int tmp = v[j];
        v[j] = v[i];
        v[i] = tmp;
    }
};