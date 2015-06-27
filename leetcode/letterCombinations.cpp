class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> vs={" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> *rt=new vector<string>;
        if(digits.size()==0)
            return *rt;
        rt->push_back("");
        for(int i=0;i<digits.size();i++){
            vector<string> *tmp=new vector<string>;
            for(auto itr=rt->begin();itr!=rt->end();itr++){
                int idx=digits[i]-'0';
                string str=vs[idx];
                for(int j=0;j<str.size();j++){
                    tmp->push_back(*itr+str[j]);
                }
            }
            delete rt;
            rt=tmp;
        }
        return *rt;
        
    }
};