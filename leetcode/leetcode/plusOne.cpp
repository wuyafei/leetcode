#include<vector>
using namespace std;

vector<int> plusOne(vector<int> &digits){
    for(vector<int>::reverse_iterator itr=digits.rbegin();itr!=digits.rend();itr++){
        (*itr)++;
        if(*itr<10)
            return digits;
        else
            *itr -=10;
    }
    digits[0]=1;
    digits.push_back(0);
    return digits;
}
