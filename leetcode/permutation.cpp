#include<vector>
using namespace std;

/*
	Given a collection of numbers, return all possible permutations.
*/
void swap(int i, int j, vector<int> &v){
	int tmp = v[j];
	v[j] = v[i];
	v[i] = tmp;
}

void perm(int k, int n, vector<int> &num, vector<vector<int> > &vec){
	if (k == n - 1){
		vector<int> *tmp = new vector<int>;
		(*tmp).insert((*tmp).begin(), num.begin(), num.end());
		vec.push_back(*tmp);
	}
	else{
		for (int i = k; i < n; i++){
			swap(i, k, num);
			perm(k + 1, n, num, vec);
			swap(i, k, num);
		}
	}

}

vector<vector<int> > permute(vector<int> &num) {
	int n = num.size();
	vector<vector<int> > vec;
	perm(0, n, num, vec);
	return vec;
}