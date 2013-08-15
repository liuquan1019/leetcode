//用unordered_map作hash，O(1)时间代价。本题因为只判断一个数有没有，无需键值对，故可进一步简化为unordered_set
class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = num.size();
		if(n <= 1)return n;
		unordered_map<int,int> m;
		unordered_map<int,int>::iterator it;
		int i,ans = 1,cnt;
		for(i = 0;i < n;i++)m[num[i]] = i;
		for(i = 0;i < m.size();i++){
			cnt = 0;
			int t = m.begin() -> first;
			m.erase(m.begin());
			int t1 = t + 1;
			t--;
			while((it = m.find(t1)) != m.end()){m.erase(it);t1++;}
			while((it = m.find(t)) != m.end()){m.erase(it);t--;}
			ans = max(ans,t1 - t - 1);
		}
		return ans;
	}
};