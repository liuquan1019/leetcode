//还可进一步优化：左往右扫描，当遇到重复字母时，以上一个重复字母的index +1，作为新的搜索起始位置，
//此时hash可以不仅存放0或1表示是否出现，而是存储出现的下标，-1为未出现
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len = s.length();
		if(len <= 1)return len;
		int m = 1;
		int i,j;
		for(i = 0;i <= len - m;i++){
			vector<bool> v(257,false);
			v[s[i]] = true;
			for(j = i + 1;j < len;j++){
				if(!v[s[j]])v[s[j]] = true;
				else break;
			}
			m = max(m,j - i);
			if(j == len)break;
		}
		return m;
	}
};
//second edition
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = s.length();
		int maxLength = 0;
		for(int i = 0;i < n;i++){
			int mask = 0,len = 0;
			while(i + len < n && (mask >> (s[i+len] - 'a') & 1) == 0){
				mask |= 1 << (s[i+len] - 'a');
				len ++;
			}
			maxLength = max(maxLength,len);
		}
		return maxLength;
	}
};