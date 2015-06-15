class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>> *rt=new vector<vector<string>>[n+1];
        vector<vector<bool>> isPalid(n, vector<bool>(n, false));
        rt[0].push_back(vector<string>());
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(i==j || (s[i]==s[j] && (i==j+1 || isPalid[j+1][i-1]))){
                    isPalid[j][i]=true;
                    for(auto itr=rt[j].begin();itr!=rt[j].end();itr++){
                        vector<string> vs(*itr);
                        vs.push_back(s.substr(j,i-j+1));
                        rt[i+1].push_back(vs);
                    }
                }
                else{
                    isPalid[j][i]=false;
                }
            }
        }
        return rt[n];
    }
};