#include"util.h"
using namespace std;

int min(int x, int y){
	return x < y ? x : y;
}
int max(int x, int y){
	return x>y ? x : y;
}
void swap(int x, int y){
	int tmp = x;
	x = y;
	y = tmp;
}