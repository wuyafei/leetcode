using namespace std;

/*
	Given an array of non-negative integers, you are initially positioned at the first index of the array.
	Each element in the array represents your maximum jump length at that position.
	Determine if you are able to reach the last index.
*/
bool canJump_recursive(int curr_idx, int A[], int n){
	if (curr_idx + A[curr_idx] >= n - 1)
		return true;
	bool result = false;
	for (int i = 0; i < A[curr_idx]; i++){
		result = result || canJump_recursive(curr_idx + i + 1, A, n);
		if (result)
			return true;
	}
	return false;
}
bool canJump_dp(int A[], int n){
	bool result = false;
	bool* d;
	d = new bool[n];
	d[n - 1] = true;
	for (int i = n - 2; i >= 0; i--){
		d[i] = false;
		if (i != n - 2 && result == false)
			continue;
		for (int j = 0; j<A[i] && i + j + 1<n; j++)
			d[i] = d[i] || d[i + j + 1];
		result = result || d[i];
	}
	return d[0];
}
bool canJump_cool(int A[], int n){
	int last = n - 1;
	for (int i = n - 2; i >= 0; i--){
		if (A[i] + i >= last)
			last = i;
	}
	return last == 0;
}


bool canJump(int A[], int n){
	return canJump_dp(A, n);
}