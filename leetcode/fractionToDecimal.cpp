#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

string fractionToDecimal(long long numerator, long long denominator){
	bool isNegative = (numerator < 0) ^ (denominator < 0);
	if (numerator<0)
		numerator = -numerator;
	if (denominator<0)
		denominator = -denominator;
	string str="";
	long long intPart = numerator / denominator;
	long long remainder = numerator%denominator;
	
	if (intPart == 0)
		str = '0' + str;
	while (intPart){
		str = (char)(intPart % 10 + '0') + str;
		intPart /= 10;
	}
	if (remainder != 0)
		str += '.';
	
	unordered_map<int, int> map;
	while (remainder != 0){
		if (map.count(remainder)>0){
			str.insert(map[remainder], 1, '(');
			str += ')';
			break;
		}
		map[remainder] = str.size();
		remainder *= 10;
		str += (char)('0' + remainder / denominator);
		remainder = remainder % denominator;
		
	}
	if (isNegative && numerator!=0)
		str = '-' + str;
	return str;
}