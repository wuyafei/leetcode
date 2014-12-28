#include<string>
#include<vector>
#include<iostream>
using namespace std;

string fractionToDecimal(int numerator, int denominator){
	if (numerator<0)
		numerator = -numerator;
	if (denominator<0)
		denominator = -denominator;
	bool isPositive = (numerator < 0) ^ (denominator < 0);
	string str="";
	vector<int> d;
	vector<int> r;
	int intPart = numerator / denominator;
	int remainder = (numerator%denominator)*10;
	int i = 0;
	int recurPoint=0;
	bool findRecur = false;
	while (remainder != 0){
		int j = i - 1;
		while (j >= 0){
			if (r[j] == remainder){
				recurPoint = j;
				findRecur = true;
				break;
			}
			j--;
		}
		if (findRecur)
			break;
		r.push_back(remainder);
		if (remainder < denominator){
			d.push_back(0);
			//cout << d[i] << endl;
			i++;
			remainder *= 10;
			continue;
		}
		d.push_back( remainder / denominator);
		//cout << d[i] << endl;
		remainder = remainder % denominator;
		remainder *= 10;
		i++;
	}
	
	if (intPart == 0)
		str = '0' + str;
	while (intPart){
		str = (char)(intPart % 10 + '0') + str;
		intPart /= 10;
	}
	if(i==0)
		return str;
	str = str + '.';
	if (findRecur){
		for (int k = 0; k < recurPoint; k++){
			str = str + (char)(d[k] + '0');
		}
		str = str + '(';
		for (int k = recurPoint; k < i; k++){
			str = str + (char)(d[k] + '0');
		}
		str = str + ')';
	}
	else{
		for (int k = 0; k < i; k++){
			str = str + (char)(d[k] + '0');
		}
	}
	if (!isPositive)
		str = '-' + str;
	return str;
}