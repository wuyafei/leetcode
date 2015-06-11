#include<string>
using namespace std;

string addBinary(string a, string b){
    string s="";
    int carry=0;
    int pa=a.size()-1;
    int pb=b.size()-1;
    while(pa>=0 || pb>=0){
        int ia=pa>=0?a[pa]-'0':0;
        int ib=pb>=0?b[pb]-'0':0;
        int bit=ia+ib+carry;
        carry=bit>1?1:0;
        bit=carry==1?bit-2:bit;
        s=(char)(bit+'0')+s;
        pa--;
        pb--;
    }
    if(carry==1)
        s='1'+s;
    return s;

}
