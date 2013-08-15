//���Ƽ�ȴ���ѷ��������������facebook
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
/*����
ÿ�ζ��ڵ�ǰ���ַ��ж��Ƿ�����1-9��0�϶����У���Ϊ0����1-26�У���������ڣ���ô��ǰ���ַ����Ա�decode�����Һ�f[n-1]��ϣ�f[n] += f[n-1]
Ȼ����ڵ�ǰ�ַ���ǰһ���ַ���ɵ��ַ����ж��Ƿ�����10-26��������ڣ���ô�������ַ����Ա�decode�����Һ�f[n-2]��ϣ�f[n] += f[n-2]
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
					else f[i] += 1;//i == 1��û��i - 2���index
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
//second edition�ݹ�����ݳ�ʱ
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
//��һ����Ϊ����
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