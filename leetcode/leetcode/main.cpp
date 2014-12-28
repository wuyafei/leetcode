#include "leetcode.h"
#include<iostream>
#include<string>
#include<time.h>

int main(){
	int t = clock();
	cout << fractionToDecimal(1, 21474) << endl;;
	t = clock() - t;
	cout << "time=" << t << endl;
	getchar();
	return 0;
}