class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n==-2147483648){
            double t=myPow_(x, -(n/2));
            return t*t;
        }
        if(n>0) return myPow_(x,n);
        else return 1.0/myPow(x, -n);
    }
private:
    double myPow_(double x, int n){
        if(n==1) return x;
        double y=myPow(x, n/2);
        y=y*y;
        if(n%2==0) return y;
        else return y*x;
    } 
};