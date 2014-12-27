using namespace std;

/*
	Given an unsorted integer array, find the first missing positive integer.
*/
int firstMissingPositive(int A[], int n) {
	for (int i = 0; i < n; i++){
		int tmp = A[i];
		if (tmp <= 0 || tmp>n || tmp == i + 1)
			continue;
		A[i] = A[tmp - 1];
		A[tmp - 1] = tmp;
		if (A[i] != tmp)
			i--;
	}
	for (int j = 0; j < n; j++){
		if (A[j] != j + 1)
			return j + 1;
	}
	return n + 1;
}