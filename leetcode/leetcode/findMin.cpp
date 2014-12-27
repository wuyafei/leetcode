#include<vector>
#include<iostream>
using namespace std;

/*
	Suppose a sorted array is rotated at some pivot unknown to you beforehand.
	(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
	Find the minimum element.
	You may assume no duplicate exists in the array.
*/


int findMin_(vector<int> &num, int low, int high){
	if (high - low == 1)
		return num[low] < num[high] ? num[low] : num[high];
	int mid = (low + high) / 2;
	if (num[low] < num[mid])
		return findMin_(num, mid, high);
	else
		return findMin_(num, low, mid);
}


int findMin(vector<int> &num) {
	int n = num.size();
	if (n == 1 || num[0] < num[n - 1])
		return num[0];
	return findMin_(num, 0, num.size()-1);
}