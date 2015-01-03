#include "leetcode.h"
#include<iostream>
#include<time.h>

int main(){
	int A[] = { 1, 1, 1, 3, 3};

	int t = clock();
	int len = removeDuplicates(A, 4);
	for (int i = 0; i < len; i++)
		cout << A[i] << endl;
	t = clock() - t;
	cout << "time=" << t << endl;
	getchar();
	return 0;
}