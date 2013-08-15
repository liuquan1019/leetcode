//想到动归思路，但发现分两种大情况讨论且难以整合在一个递推式中，则作为参数传入新的函数以统一处理，贪心
class Solution {
public:
	string findPal(string &s, int left, int right){
		if (left < 0)return s.substr(left+1, 1);
		if (right >= s.size())return s.substr(right-1, 1);
		while(0 <= left && right < s.size()){
			if (s[left] != s[right])break;
			left--;
			right++;
		}
		left++;
		right--;
		return s.substr(left, right - left + 1);        
	}
	string longestPalindrome(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (s.size() == 0)return "";
		string ret;
		for(int i = 0; i < s.size(); i++){
			string str = findPal(s, i - 1, i + 1);
			if (str.size() > ret.size())ret = str;
			str = findPal(s, i, i + 1);
			if (str.size() > ret.size())ret = str;
		}
		return ret;
	}
};
//更巧妙O(n)做法
http://www.felix021.com/blog/read.php?2040

//second edition
class Solution {
public:
	string longestPalindrome(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = s.length();
		int len = 1,begin = 0,end = n - 1,j;
		for(int i = 1;i < n;i++){
			if(i < n - 1 && s[i-1] == s[i+1]){
				j = 2;
				while(i - j >= 0 && i + j < n && s[i-j] == s[i+j])j++;
				if(len < 2 * j - 1){
					len = 2 *j - 1;
					begin = i - j + 1;
					end = i + j - 1;
				}
			}
			if(s[i-1] == s[i]){
				j = 2;
				while(i - j >= 0 && i + j - 1 < n && s[i-j] == s[i+j-1])j++;
				if(len < 2 * j - 2){
					len = 2 * j - 2;
					begin = i - j + 1;
					end = i + j - 2;
				}
			}
		}
		return s.substr(begin,end - begin + 1);
	}
};