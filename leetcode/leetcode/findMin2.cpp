#include<vector>
using namespace std;

/*
	Suppose a sorted array is rotated at some pivot unknown to you beforehand.
	(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
	Find the minimum element.
	The array may contain duplicates.
*/

int findMin2(vector<int> &num) {
	int n = num.size();
	if (n == 1 || num[0] < num[n - 1])
		return num[0];
	int l = 0;
	int h = n - 1;
	while (l < h){
		int m = (l + h) / 2;
		if (num[m] < num[h]){
			h = m;
		}
		else if (num[h]<num[m]){
			l = m+1;
		}
		else{
			if (num[h] == num[l]){
				h--;
				l++;
			}
			else
				h = m;
		}
	}
	return num[h];
}