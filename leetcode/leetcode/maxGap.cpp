#include"util.h"
#include<stdlib.h>
using namespace std;

/*
given array arr, find the maximun of arr[j]-arr[i], for any j>i
*/

//brutal force method
int maxGap_bf(int arr[], int n){
	int max = arr[1] - arr[0];
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			int t = arr[j] - arr[i];
			if (t>max)
				max = t;
		}
	}
	return max;
}

/*divide conquer method
1. find the minimun element in arr and its value is v_min and index is i_min
2. find the maximun element in arr[i_min+1..n), and its value is v_max
3. now the maximun gap is eithor v_max-v_min or in arr[0..i_min-1], and we can recursively solve the latter one
*/
int max_(int a, int b){
	return a > b ? a : b;
}
int maxGap_dv(int arr[], int end){
	if (end < 1)
		return INT_MIN;
	if (end == 1)
		return arr[1] - arr[0];

	int v_min=arr[0], i_min=0;
	for (int i = 1; i < end; i++){
		if (arr[i] < v_min){
			v_min = arr[i];
			i_min = i;
		}
	}
	if (i_min == end - 1)
		return max_(arr[i_min] - arr[i_min - 1], maxGap_dv(arr, end - 1));
	int v_max = arr[i_min+1];
	for (int i = i_min + 2; i < end; i++){
		if (arr[i]>v_max)
			v_max = arr[i];
	}
	return max_(v_max - v_min, maxGap_dv(arr, i_min - 1));
}

/*
linear time method
define another array, c[i]=arr[i+1]-arr[i]
now the problem transformed to the maximun sum of subarray problem
*/
int maxGap_lin(int arr[], int n){
	int *c = new int[n - 1];
	for (int i = 0; i<n - 1; i++){
		c[i] = arr[i + 1] - arr[i];
	}
	int max = c[0], maxEndingHere = c[0];
	for (int i = 1; i<n - 1; i++){
		maxEndingHere = max_(c[i], maxEndingHere + c[i]);
		if (maxEndingHere > max)
			max = maxEndingHere;
	}
	delete[] c;
	return max;
}


int maxGap(){
	int *arr = new int[10000000];
	for (int i = 0; i<10000000; i++){
		arr[i] = rand() % 100000000;
	}
	return maxGap_lin(arr, 10000000);
}


