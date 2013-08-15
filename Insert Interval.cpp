/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(intervals.empty()){intervals.push_back(newInterval);return intervals;}
        int i,j;
        for(i = 0;i < intervals.size();i++)
            if(intervals[i].start > newInterval.start)break;
        if(i == intervals.size())intervals.push_back(newInterval);
        intervals.insert(intervals.begin() + i,newInterval);
        for(i = 0;i < intervals.size() - 1;i++){
            if(intervals[i].end < intervals[i + 1].start)continue;
            else{
                intervals[i].end = max(intervals[i].end,intervals[i + 1].end);
                for(j = i + 2;j < intervals.size();j++){
                    if(intervals[j].start > intervals[i].end)break;
                    else intervals[i].end = max(intervals[i].end,intervals[j].end);
                }
                break;
            }
        }
        if(i < intervals.size() - 1)
            intervals.erase(intervals.begin() + i + 1,intervals.begin() + j);
        return intervals;
    }
};
//second edition
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = intervals.size();
        if(n == 0 || newInterval.end < intervals[0].start){
            intervals.insert(intervals.begin(),newInterval);
            return intervals;
        }
        int i,j,s,e;
        for(i = 0;i < n;i++){
            if(intervals[i].start <= newInterval.start && intervals[i].end >= newInterval.end)break;
            if(intervals[i].end >= newInterval.start && intervals[i].start <= newInterval.end){
                s = min(intervals[i].start,newInterval.start);
                j = i + 1;
                while(j < n && intervals[j].start <= newInterval.end)j++;
                e = max(newInterval.end,intervals[j-1].end);
                intervals.erase(intervals.begin()+i,intervals.begin()+j);
                Interval temp(s,e);
                intervals.insert(intervals.begin()+i,temp);
                break;
            }
            if(i+1 < n &&intervals[i].end < newInterval.start && intervals[i+1].start > newInterval.end){
                intervals.insert(intervals.begin()+i+1,newInterval);
                break;
            }
        }
        if(i == n)intervals.push_back(newInterval);
        return intervals;
    }
};
//third edition
class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int i = 0;
		while(i < intervals.size() && intervals[i].end < newInterval.start)i++;
		intervals.insert(intervals.begin() + i,newInterval);
		for(int j = i + 1;j <intervals.size();){
			if(intervals[j].start > intervals[i].end)break;
			intervals[i].start = min(intervals[i].start,intervals[j].start);
			intervals[i].end = max(intervals[i].end,intervals[j].end);
			intervals.erase(intervals.begin() + j);
		}
		return intervals;
	}
};