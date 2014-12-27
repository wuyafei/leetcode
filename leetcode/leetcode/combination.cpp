#include<vector>
using namespace std;

/*
	Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
*/
vector<vector<int> > combine(int n, int k) {
	vector<vector<int> > rslt;
	vector<int> tmp;
	for (int i = 0; i < k; i++)
		tmp.push_back(i + 1);
	while (!tmp.empty()){
		if (tmp.back() > n - k + tmp.size()){
			tmp.pop_back();
			if (tmp.empty())
				break;
			tmp[tmp.size() - 1]++;
		}
		else if (tmp.size() == k){
			rslt.push_back(tmp);
			tmp[k - 1]++;
		}
		else{
			tmp.push_back(tmp.back() + 1);
		}
	}
	return rslt;
}