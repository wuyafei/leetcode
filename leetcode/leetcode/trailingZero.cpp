using namespace std;

/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

int trailingZeroes(int n){
	int sum = 0;
	for (int i = 5; n/i > 0; i*=5){
		sum += (n / i);
	}
	return sum;
}