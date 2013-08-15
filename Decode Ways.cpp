//看似简单却很难分析清所有情况，facebook
class Solution {
public:
	int numDecodings(string s) {
		int n = s.size();
		if(n == 0) return 0;
		vector<int> v(n+1, 1);
		for(int i = n-1; i >= 0 ; i--) {
			if(s[i] == '0') v[i] = 0;
			else v[i] = v[i+1];
			if((i < n-1) &&((s[i] == '1') || ((s[i] == '2'))&&((s[i+1] >= '0') && (s[i+1] <= '6'))))
				v[i]+=v[i+2];
		}
		return v[0];
	}
};
/*另法：
每次对于当前的字符判断是否属于1-9（0肯定不行，因为0不在1-26中），如果属于，那么当前的字符可以被decode，并且和f[n-1]组合，f[n] += f[n-1]
然后对于当前字符和前一个字符组成的字符串判断是否属于10-26，如果属于，那么这两个字符可以被decode，并且和f[n-2]组合，f[n] += f[n-2]
*/
class Solution {
public:
	int numDecodings(string s) {
		if (s == "")return 0;
		vector<int> f;
		f.resize(s.length());
		int i = 0;
		for (; i < s.length(); i++){
			f[i] = 0;
			if (i >= 1){
				string tmp(s, i-1, 2);
				if ("10" <= tmp && tmp <= "26")
					if (i > 1)f[i] += f[i-2];
					else f[i] += 1;//i == 1，没有i - 2这个index
				if ('1' <= s[i] && s[i] <= '9')
					f[i] += f[i-1];
			}
			else{//i == 0
				if ('1' <= s[i] && s[i] <= '9')
					f[i] = 1;
			}
		}
		return f[i-1];
	}
};
//second edition递归大数据超时
class Solution {
public:
	int numDecodings(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(s.length() == 0)return 0;
		const char *t = s.c_str();
		return number(t);
	}
	int number(const char  *t){
		if(*t == '\0')return 1;
		if(*t == '0')return 0;
		if(*(t+1) != '\0' && (*t == '1' || (*t == '2' && *(t+1) <= '6')))return number(t+1)+number(t+2);
		else return number(t+1);
	}
};
//进一步改为动归
class Solution {
public:
	int numDecodings(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = s.length();
		if(n == 0)return 0;
		int next1 = 1,next2 = 1,tmp;
		for(int i = n - 1;i >= 0;i--){
			if(s[i] == '0'){
				next2 = next1;
				next1 = 0;
			}
			else if(i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))){
				tmp = next1;next1 += next2;next2 = tmp;
			}
			else next2 = next1;
		}
		return next1;
	}
};