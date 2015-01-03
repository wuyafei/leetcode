using namespace std;

/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
*/
int removeDuplicates(int A[], int n){
	if (n == 0)
		return 0;
	int i = 1, j = 1;
	while (j < n && i < n){
		if (A[i]>A[i - 1]){
			i++;
			continue;
		}
		while (j < n && A[j] <= A[i-1]){
			j++;
		}
		if (j == n)
			return i;
		A[i] = A[j];
		i++;
		j++;
	}
	return i;
}