using namespace std;

/*
Given an array and a value, remove all instances of that value in place and return the new length.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/
int removeElement(int A[], int n, int elem){
	int i = 0, j = n - 1;
	while (i <= j){
		if (A[i] != elem)
			i++;
		else{
			while (A[j] == elem)
				j--;
			if (j < i)
				return i;
			else
				A[i++] = A[j--];
		}
	}
	return i;
}