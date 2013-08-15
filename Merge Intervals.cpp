/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
//自己写了冒泡排序结果大数据超时，原来可以在结构体外定义比较符号，如下示：
 bool comp(const Interval &l,const Interval &r){
     return l.start < r.start;
 }
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(intervals.empty())return intervals;
        int i,j;
        sort(intervals.begin(),intervals.end(),comp);
        /*for(i = 0;i < intervals.size() - 1;i++)
            for(j = 0;j < intervals.size() - i - 1;j++){
                if(intervals[j].start > intervals[j + 1].start){
                    Interval temp = intervals[j + 1];
                    intervals[j + 1] = intervals[j];
                    intervals[j] = temp;
                }
            }
        */
        for(i = 0;i < intervals.size() - 1;i++){
            if(intervals[i].end < intervals[i + 1].start)continue;
            else{
                intervals[i].end = max(intervals[i].end,intervals[i + 1].end);
                for(j = i + 2;j < intervals.size();j++){
                    if(intervals[j].start > intervals[i].end)break;
                    else intervals[i].end = max(intervals[i].end,intervals[j].end);
                }
                intervals.erase(intervals.begin() + i + 1,intervals.begin() + j);
            }
        }    
        return intervals;
    }
};
//second edition
class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = intervals.size();
		if(n <= 1)return intervals;
		sort(intervals.begin(),intervals.end(),cmp);
		vector<Interval> ans;
		for(int i = 0;i < n;i++){
			int s = intervals[i].start;
			int e = intervals[i].end;
			while(i + 1 < n && intervals[i+1].start <= e){
				e = max(e,intervals[i+1].end);
				i++;
			}
			Interval temp(s,e);
			ans.push_back(temp);
		}
		return ans;
	}
};
//third edition
bool comp(const Interval l1,const Interval l2){
	if(l1.start != l2.start)return l1.start < l2.start;
	return l1.end < l2.end;
}
class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		sort(intervals.begin(),intervals.end(),comp);
		for(int i = 0;i < intervals.size();){
			int far = intervals[i].end;
			int j = i + 1;
			while(j < intervals.size() && intervals[j].start <= far){
				far = max(far,intervals[j].end);
				intervals.erase(intervals.begin() + j);
			}
			intervals[i].end = far;
			i = j;
		}
		return intervals;
	}
};