using namespace std;

int climbStairs(int n){
    int a=0,b=1;
    int rslt=0;
    while(n-- > 0){
        rslt=a+b;
        a=b;
        b=rslt;
    }
    return rslt;
}
