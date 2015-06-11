using namespace std;
/*
 *Given two sorted integer arrays A and B, merge B into A as one sorted array.
 */
void merge(int A[], int m, int B[], int n) {
    int *C=new int[m+n];
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(A[i]<B[j])
            C[k]=A[i++];
        else
            C[k]=B[j++];
        k++;
    }
    if(i==m){
        while(j<n)
            C[k++]=B[j++];
    }else{
        while(i<m)
            C[k++]=A[i++];
    }
    i=0;
    while(i<k){
        A[i]=C[i];
        i++;
    }
}

