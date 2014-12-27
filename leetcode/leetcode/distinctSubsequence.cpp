#include<string>
using namespace std;

/*
	Given a string S and a string T, count the number of distinct subsequences of T in S.
	A subsequence of a string is a new string which is formed from the original string by
	deleting some (can be none) of the characters without disturbing the relative positions
	of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
*/
int numDistinct_recursivie(string S, int si, string T, int ti){
	if (ti == T.length())
		return 1;
	if (si == S.length())
		return 0;
	int num = 0;
	for (int i = si; i < S.length(); i++){
		if (S[i] == T[ti]){
			num += numDistinct_recursivie(S, i + 1, T, ti + 1);
		}
	}
	return num;
}
int numDistinct_dp(string S, string T){
	int* d = new int[T.length()];
	for (int i = 0; i<T.length(); i++)
		d[i] = 0;
	for (int i = S.length() - 1; i >= 0; i--){
		for (int j = 0; j < T.length(); j++){
			if (S[i] == T[j]){
				if (j == T.length() - 1)
					d[j]++;
				else
					d[j] = d[j] + d[j + 1];
			}
		}
	}
	return d[0];
}

int numDistinct(string S, string T) {
	return numDistinct_recursivie(S, 0,T,0);
}