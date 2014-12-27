#include<vector>
#include<string>
using namespace std;

/*
	Given a string containing only digits, restore it by returning all possible valid IP address combinations.
*/

bool invalidNumber(string s, int start, int length){
	int sum = s[start] - '0';
	for (int i = 1; i<length; i++){
		sum = sum * 10 + s[start + i] - '0';
	}
	if (length == 2 && sum < 10)
		return true;
	else if (length == 3 && (sum < 100 || sum>255))
		return true;
	else
		return false;
}

bool checkAnswer(int a[], string s){
	if (a[0] == 0 || a[1] == 0 || a[2] == 0 || a[3] == 0)
		return false;
	if (a[0] + a[1] + a[2] + a[3] != s.size())
		return false;
	if (invalidNumber(s, 0, a[0]))
		return false;
	if (invalidNumber(s, a[0], a[1]))
		return false;
	if (invalidNumber(s, a[0] + a[1], a[2]))
		return false;
	if (invalidNumber(s, a[0] + a[1] + a[2], a[3]))
		return false;
	return true;

}
vector<string> restoreIpAddresses(string s) {
	vector<string> vs;
	int c[4] = { 0, 0, 0, 0 };
	//bool flag = false;
	int k = 0;
	while (k >= 0){
		while (c[k] < 3){
			c[k] = c[k] + 1;
			if (checkAnswer(c, s)){
				vs.push_back(s.substr(0, c[0])+"."+s.substr(c[0],c[1])+"."+s.substr(c[0]+c[1],c[2])+"."+s.substr(c[0]+c[1]+c[2],c[3]));
			}
			else if (k<3)
				k = k + 1;
		}
		c[k] = 0;
		k = k - 1;
	}
	return vs;
}
