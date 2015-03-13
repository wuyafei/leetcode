#include<string>
using namespace std;

int lengthOfLastWord(const char *s){
    int rslt=0;
    int idx=strlen(s)-1;
    while(idx>=0 && s[idx]==' ')
        idx--;
    while(idx>=0 && s[idx--]!=' ')
        rslt++;
    return rslt;
}
