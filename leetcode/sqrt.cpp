#include<iostream>
using namespace std;

int sqrt(int x){
	if (x == 0)
		return 0;
	double t = 1.;
	while (abs(x / t - t )> 0.00000001){
		
		t = (x / t + t) / 2;
		cout << t << endl;
	}
	return int(t);
}