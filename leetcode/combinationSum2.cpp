class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> rt;
        vector<int> v;
        combine(0, candidates, target, v, rt);
        return move(rt);
    }
    
private:
    void combine(int start, vector<int> &candidates, int target, vector<int> &v, vector<vector<int>> &rt){
        if(target==0){
            rt.push_back(v);
            return;
        }
        if(target<0) return;
        for(int i=start;i<candidates.size();i++){
            if(candidates[i]>target)
                break;
            if(i!=start && candidates[i]==candidates[i-1])
                continue;
            v.push_back(candidates[i]);
            combine(i+1, candidates, target-candidates[i], v, rt);
            v.pop_back();
        }
        
        
    }
};