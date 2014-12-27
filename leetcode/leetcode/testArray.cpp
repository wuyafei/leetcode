#include<iostream>
#include<array>
#include<ctime>
#include<vector>
#include<deque>
using namespace std;

void test(){
	//array<int, 100000> arr1; //  5
	//int arr1[100000];   //2
	//vector<int> arr1;   //42
	//deque<int> arr1;    //66
	deque<int> arr1;
	int sum = 0;
	int t = clock();
	for (int i = 0; i < 100000; i++){
		arr1.push_back( rand()%1543);
	}
	sum = arr1[1852] % arr1[34] + arr1[5698] / arr1[733] + arr1[987] * arr1[73234] + arr1[835] / arr1[6893];
	t = clock() - t;
	cout << t << endl;
}