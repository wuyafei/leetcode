#include<vector>
using namespace std;
/*
	Given an index k, return the kth row of the Pascal's triangle.
*/
vector<int> getRow(int rowIndex) {
	int t = rowIndex / 2;
	vector<int> v;
	if (rowIndex < 0)
		return v;
	v.reserve(rowIndex + 1);
	v.push_back(1);
	for (int i = 1; i <= t; i++)
		v.push_back(v[i - 1] * (rowIndex - i + 1) / i);
	for (int i = t + 1; i <= rowIndex; i++)
		v.push_back(v[rowIndex - i]);
	return v;
}