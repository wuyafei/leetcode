#include<string>
using namespace std;

bool isPalindrome(string s) {
    int l=0;
    int h=s.length()-1;
    while(l<h){
        while(l<h && !((s[l]>='a' && s[l]<='z') || (s[l]>='A' && s[l]<='Z') || (s[l]>='0' && s[l]<='9')))
            l++;
        while(h>l && !((s[h]>='a' && s[h]<='z') || (s[h]>='A' && s[h]<='Z') || (s[h]>='0' && s[h]<='9')))
            h--;
        if(s[h]!=s[l] && s[h]-'a'!=s[l]-'A' && s[h]-'A'!=s[l]-'a')
            return false;
        l++;
        h--;
    }
    return true;
}

