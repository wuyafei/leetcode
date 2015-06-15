class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> rt;
        vector<int> r(n,-1);
        int i=0;
        while(i>=0){
            while(r[i]<n-1){
                r[i]=r[i]+1;
                if(isSolution(r, i+1)){
                    if(i==n-1){
                        addToRt(rt,r);
                        break;
                    }
                    else{
                        i++;
                    }
                }
            }
            r[i]=-1;
            i--;
        }
        return rt;
        
    }
private:
    bool isSolution(vector<int> &r, int n){
        //int n=r.size();
        for(int i=0;i<n;i++){
            if(r[i]<0) continue;
            for(int j=i+1;j<n;j++){
                if(r[j]<0) continue;
                if(r[i]==r[j]) return false;
            }
        }
        for(int i=0;i<n;i++){
            if(r[i]<0) continue;
            for(int j=i+1;j<n;j++){
                if(r[j]<0) continue;
                if(abs(r[i]-r[j])==abs(i-j)) return false;
            }
        }
        return true;
    }
    
    void addToRt(vector<vector<string>> &rt, vector<int> &r){
        int n=r.size();
        vector<string> vs;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<r[i];j++)
                s=s+".";
            s=s+"Q";
            for(int j=r[i]+1;j<n;j++)
                s=s+".";
            vs.push_back(s);
        }
        rt.push_back(vs);
    }
};