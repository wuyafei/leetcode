#include<vector>
using namespace std;

vector<vector<int> > generatePascal(int numRows){
    vector<vector<int> > rslt;
    vector<int> *cur_row;
    vector<int> *pre_row;
    if(numRows==0)
        return rslt;
    pre_row=new vector<int>();
    (*pre_row).push_back(1);
    rslt.push_back(*pre_row);

    for(int i=1;i<numRows;i++){
        cur_row=new vector<int>();
        (*cur_row).push_back(1);
        int j=1;
        while(j<(*pre_row).size()){
            (*cur_row).push_back((*pre_row).at(j-1)+(*pre_row).at(j));
        }
        (*cur_row).push_back(1);
        rslt.push_back(*cur_row);
        pre_row=cur_row;
        cur_row=NULL;
    }
    return rslt;
}

