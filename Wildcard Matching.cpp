//递归处理*的匹配，大数据超时
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int slen = strlen(s),plen = strlen(p);
		int i = 0,j = 0,k;
		if(slen == 0){
			if(plen == 0)return true;
			for(k = 0;k < plen;k++)if(p[k] != '*')break;
			if(k == plen)return true;
			return false;
		}
		while(i < slen && j < plen){
			if(p[j] == '?' || p[j] == s[i]){i++;j++;}
			else if(p[j] == '*'){
				j++;
				while(j < plen && p[j] == '*')j++;//剪枝一
				int jj = plen - 1,ii = slen - 1;
				while(ii >= i && jj >= j && p[jj] != '*'){//剪枝二
					if(p[jj] != '?' && p[jj] != s[ii])return false;
					jj--;
					ii--;
				}
				for(k = 0;k < slen - i + 1;k++)
					if(isMatch(s + i + k,p + j))return true;
				return false;
			}
			else return false;
		}
		if(i == slen){
			if(plen == j)return true;
			for(k = j;k < plen;k++)if(p[k] != '*')break;
			if(k == plen)return true;
			return false;
		}
		return false;
	}
};
//法二：贪心法
class Solution {  
public:  
	bool isMatch(const char *s, const char *p) {   
		const char *str, *pat;  
		bool star = false;  
		for (str = s, pat = p; *str != '\0'; ++str, ++pat){  
			switch(*pat) {  
				// 遇到'?',那么不管*str是任何字母都能匹配  
			case '?': break;  
			case '*':  
				star = true;  
				// 暂时忽略‘*’  
				s = str, p = pat;  
				do{  
					++p;  
				}while(*p == '*');  
				// 如果'*'之后，pat是空的，直接返回true  
				if (!*p)return true;  
				// 重新开始匹配  
				str = s - 1;  
				pat = p - 1;  
				break;  
			default:  
				if (*str != *pat){  
					// 如果前面没有'*'，则匹配不成功  
					if (!star) return false;  
					// 从s的下一位和'*'之后的p重新开始匹配  
					++s;  
					str = s - 1;  
					pat = p - 1;  
				}  
				break;  
			}  
		}  
		while (*pat == '*')++pat;  
		return (!*pat);  
	}  
}; 