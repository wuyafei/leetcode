#include<vector>
#include<stack>
using namespace std;

/*
	Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
	find the area of largest rectangle in the histogram.
*/

int largestRectangleArea(vector<int> &height) {
	stack<int> s;
	int top, i, max_area, area_with_top;
	max_area = 0;
	i = 0;
	while (i < height.size()){
		if (s.empty() || height[s.top()] <= height[i]){
			s.push(i);
			i++;
		}
		else{
			top = s.top();
			s.pop();
			area_with_top = height[top] * (s.empty() ? i : i - s.top() - 1);
			if (area_with_top>max_area)
				max_area = area_with_top;
		}
	}
	while (!s.empty()){
		top = s.top();
		s.pop();
		area_with_top = height[top] * (s.empty() ? i : i - s.top() - 1);
		if (max_area < area_with_top)
			max_area = area_with_top;
	}
	return max_area;
}