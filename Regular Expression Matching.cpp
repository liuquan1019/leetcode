//匹配问题做得不好，小数据bug不断，大数据递归超时
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    
		int slen = strlen(s),plen = strlen(p);
		if(slen == 0 && plen == 0)return true;
		if(plen == 0)return false;
		int i = 0,j = 0,k;
		if(slen == 0){
			if(p[j] == '*' || (j < plen - 1 && p[j + 1] == '*'))j++;
			while(j < plen && p[j] == '*')j++;
			if(j == plen)return true;
			return false;
		}
		while(i < slen && j < plen){
			if(s[i] == p[j] || p[i] == '.'){
				if(j < plen - 2 && p[j + 1] == '*' && isMatch(s + i,p + j + 2))return true;
				i++;j++;
			}
			else if(p[j] != '*'){
				if(j < plen - 1 && p[j + 1] == '*'){j += 2;continue;}
				return false;
			}
			else{
				if(j == 0)j++;
				else if(p[j - 1] == '.'){
					for(k = i - 1;k < slen;k++)
						if(isMatch(s + k,p + j + 1))return true;
					if(k == slen && j == plen - 1)return true;
					return false;
				}
				else{
					for(k = i - 1;k < slen && s[k] == p[j - 1];k++)
						if(isMatch(s + k,p + j + 1))return true;
					if(isMatch(s + k,p + j + 1))return true;
					if(k == slen && j == plen - 1)return true;
					return false;
				}
			}
		}
		if(i == slen){
			if(j == plen)return true;
			if(p[j] == '*' || (j < plen - 1 && p[j + 1] == '*'))j++;
			while(j < plen && p[j] == '*')j++;
			if(j == plen)return true;
		}
		return false;
	}
};
//参考
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    
		if(s == NULL || p == NULL || *p == '*') return false;
		if(*p == '\0') return *s == '\0';
		if(*(p+1) != '*') {
			if(*s == '\0') return false;
			if(*p != '.' && *p != *s) return false;
			return isMatch(s+1,p+1);
		} else {
			int slen = strlen(s);
			if(isMatch(s,p+2)) return true;
			for(int i = 0; i < slen; ++i) {
				if(*p!='.' && *p != *(s+i)) return false;//先行剪枝
				if(isMatch(s+i+1,p+2)) return true;
			}
			return false;
		}
	}
};
//另
assert(p!=null && (p.length()==0 || p.charAt(0)!='*'));
if(p.length()==0) return s.length()==0;
if(p.length()==1 || p.charAt(1)!='*'){
	if(s.length()<1 || (p.charAt(0)!='.' && p.charAt(0)!=s.charAt(0)))return false;
	return isMatch(s.substring(1),p.substring(1));
}
else{
	int i=-1;
	while(i<s.length() && (i<0 || p.charAt(0)=='.' || p.charAt(0)==s.charAt(i))){
		if(isMatch(s.substring(i+1),p.substring(2)))return true;
		i++;
}
return false;