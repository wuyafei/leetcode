#include<vector>
#include<unordered_map>
using namespace std;

/*
	Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
*/

int longestConsecutive(vector<int> &num) {
	int longest = 0;
	unordered_map<int,int> mp;
	for (int i = 0; i < num.size(); i++){
		if (mp.count(num[i]) != 0)
			continue;
		int low = num[i];
		int up = num[i];
		if (mp.count(num[i] - 1) != 0){
			low = mp[num[i] - 1];
		}
		if (mp.count(num[i] + 1) != 0){
			up = mp[num[i] + 1];
		}
		if (up - low + 1 > longest)
			longest = up - low + 1;
		mp[num[i]] = num[i];
		mp[low] = up;
		mp[up] = low;
	}
	return longest;
}