//dfs solution
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> rt;
        vector<int> tmp;
        combine(rt, tmp, n, k, 1);
        return rt;
    }
private:
    void combine(vector<vector<int>> &rt, vector<int> &tmp, int n, int k, int start){
        if(k==0){
            if(n==0)
                rt.push_back(tmp);
            return;
        }
        for(int i=start;i<=n/k && i<10;i++){
            tmp.push_back(i);
            combine(rt, tmp, n-i, k-1, i+1);
            tmp.pop_back();
        }
        
    }
};