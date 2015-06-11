using namespace std;

/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
*/
int removeDuplicates(int A[], int n){
	if (n == 0)
		return 0;
	int i = 0, j = 1;
	while (j < n){
		if (A[i] == A[j])
			j++;
		else
			A[++i] = A[j++];
	}
	return i+1;
}