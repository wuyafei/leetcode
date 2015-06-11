#include<vector>
#include<algorithm>
#include"util.h"
using namespace std;

/*
	Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
	You may assume that the intervals were initially sorted according to their start times.
*/


vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	vector<Interval> vi;
	if (intervals.size() == 0){
		vi.push_back(newInterval);
		return vi;
	}
	if (newInterval.start > (*(intervals.end() - 1)).end){
		vi = intervals;
		vi.push_back(newInterval);
		return vi;
	}
	if (newInterval.end < intervals.front().start){
		vi.push_back(newInterval);
		vi.insert(vi.begin() + 1, intervals.begin(), intervals.end());
		return vi;
	}

	int new_start = 0;
	int new_end = 0;
		
	vector<Interval>::iterator itr = intervals.begin();
	while ( itr!=intervals.end() && (*itr).end <= newInterval.start){
		vi.push_back(*itr);
		itr++;
	}
	new_start = min((*itr).start,newInterval.start);
	while (itr != intervals.end() && (*itr).start <= newInterval.end)
		itr++;
	new_end = max((*(itr-1)).end,newInterval.end);
	Interval it(new_start, new_end);
	vi.push_back(it);
	while (itr != intervals.end()){
		vi.push_back(*itr);
		itr++;
	}
	return vi;
}