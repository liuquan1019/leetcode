//�ݹ鴦��*��ƥ�䣬�����ݳ�ʱ
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
				while(j < plen && p[j] == '*')j++;//��֦һ
				int jj = plen - 1,ii = slen - 1;
				while(ii >= i && jj >= j && p[jj] != '*'){//��֦��
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
//������̰�ķ�
class Solution {  
public:  
	bool isMatch(const char *s, const char *p) {   
		const char *str, *pat;  
		bool star = false;  
		for (str = s, pat = p; *str != '\0'; ++str, ++pat){  
			switch(*pat) {  
				// ����'?',��ô����*str���κ���ĸ����ƥ��  
			case '?': break;  
			case '*':  
				star = true;  
				// ��ʱ���ԡ�*��  
				s = str, p = pat;  
				do{  
					++p;  
				}while(*p == '*');  
				// ���'*'֮��pat�ǿյģ�ֱ�ӷ���true  
				if (!*p)return true;  
				// ���¿�ʼƥ��  
				str = s - 1;  
				pat = p - 1;  
				break;  
			default:  
				if (*str != *pat){  
					// ���ǰ��û��'*'����ƥ�䲻�ɹ�  
					if (!star) return false;  
					// ��s����һλ��'*'֮���p���¿�ʼƥ��  
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