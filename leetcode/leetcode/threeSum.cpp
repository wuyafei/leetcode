#include<vector>
#include<set>
using namespace std;

/*
	Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
	Find all unique triplets in the array which gives the sum of zero.
*/

int partition(vector<int> &num, int low, int high){
	if (low == high)
		return low;
	int pivot = num[low];
	int i = low;
	int j = low + 1;
	while (j != high + 1){
		if (num[j] < pivot){
			i++;
			if (i != j){
				int tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}
		j++;
	}
	int tmp = num[i];
	num[i] = num[low];
	num[low] = tmp;
	return i;
}
void quicksort(vector<int> &num, int low, int high){
	if (low > high)
		return;
	int i = partition(num, low, high);
	quicksort(num, low, i - 1);
	quicksort(num, i + 1, high);
}


vector<vector<int> > threeSum(vector<int> &num) {
	int n = num.size();
	set<vector<int> > res;
	quicksort(num, 0, n - 1);
	vector<int> tmp;

	for (int i = 0; i<n - 2; i++)     //left most index
	{
		if (i>0 && num[i] == num[i - 1])  //skip the first repeated elements
			continue;
		int j = i + 1;                 //middle index
		int k = n - 1;              //right index

			
		while (j<k)
		{
			int sum = num[i] + num[j] + num[k];
			if (sum>0)
				k--;
			else if (sum<0)
				j++;
			else{
				tmp.push_back(num[i]);
				tmp.push_back(num[j]);
				tmp.push_back(num[k]);
				res.insert(tmp);                          //store in set (uniqueness) 
				tmp.clear();
				j++;
				k--;
			}
		}
	}

	//copy the set's data into output vector
	set<vector<int> >::iterator it;
	vector<vector<int> > result;
	for (it = res.begin(); it != res.end(); it++)
	{
		result.push_back(*it);
	}
	return result;
}
