#include<vector>
using namespace std;

/*
Given an array of size n, find the majority element.
The majority element is the element that appears more than floor(n/2) times.
You may assume that the array is non-empty and the majority element always exist in the array.
*/
int majorityElement(vector<int> &num){
	int maj = num[0];
	int cnt = 1;
	for (int i = 1; i < num.size(); i++){
		if (cnt == 0){
			maj = num[i];
			cnt = 1;
		}
		else if (maj != num[i]){
			cnt--;
		}
		else{
			cnt++;
		}
	}
	return maj;
}