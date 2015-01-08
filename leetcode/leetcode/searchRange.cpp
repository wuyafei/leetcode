#include<vector>
using namespace std;

vector<int> searchRange(int A[], int n, int target) {
        int l=0,h=n-1;
        bool targetFind=false;
        vector<int> rslt={-1,-1};
        while(l<=h){
            int m=l+(h-l)/2;
            if(A[m]==target){
                targetFind=true;
                break;
            }
            else if(A[m]<target)
                l=m+1;
            else
                h=m-1;
        }
        if(targetFind){
            while(l<=h && A[l]!=target)
                l++;
            while(h>=l && A[h]!=target)
                h--;
            rslt.clear();
            rslt.push_back(l);
            rslt.push_back(h);
        }
        return rslt;
    }
