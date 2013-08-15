class Solution {
public:
	bool isNumber(const char *s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len = strlen(s);
		if(len == 0)return false;
		int i = 0,j;
		while(i < len && s[i] == ' ')i++;
		if(i == len)return false;
		if(s[i] == '.'){
			if(i == len - 1)return false;
			i++;
			if(s[i] == ' ' || s[i] == 'e')return false;
			while(i < len && s[i] >= '0' && s[i] <= '9')i++;
			if(i == len)return true;
			if(s[i] == 'e'){
				if(i == len - 1)return false;
				i++;
				if(s[i] == '+' || s[i] == '-'){
					if(i == len - 1)return false;
					i++;
					while(i < len && s[i] >= '0' && s[i] <= '9')i++;
					if(i == len)return true;
					while(i < len && s[i] == ' ')i++;
					if(i == len)return true;
				}
				else{
					while(i < len && s[i] >= '0' && s[i] <= '9')i++;
					if(i == len)return true;
					while(i < len && s[i] == ' ')i++;
					if(i == len)return true;
				}
			}
			while(i < len && s[i] == ' ')i++;
			if(i == len)return true;
			return false;
		}
		else if(s[i] == '+' || s[i] == '-'){
			if(i == len - 1)return false;
			i++;
			if(s[i] == '.'){
				if(i == len - 1)return false;
				i++;
				if(s[i] == ' ')return false;
				while(i < len && s[i] >= '0' && s[i] <= '9')i++;
				if(i == len)return true;
				if(s[i] == 'e'){
					if(i == len - 1)return false;
					i++;
					if(s[i] == '+' || s[i] == '-'){
						if(i == len - 1)return false;
						i++;
						while(i < len && s[i] >= '0' && s[i] <= '9')i++;
						if(i == len)return true;
						while(i < len && s[i] == ' ')i++;
						if(i == len)return true;
					}
					else{
						while(i < len && s[i] >= '0' && s[i] <= '9')i++;
						if(i == len)return true;
						while(i < len && s[i] == ' ')i++;
						if(i == len)return true;
					}
				}

				while(i < len && s[i] == ' ')i++;
				if(i == len)return true;
			}
			if(s[i] < '0' || s[i] > '9')return false;
			i++;
			while(i < len && s[i] >= '0' && s[i] <= '9')i++;
			if(i == len)return true;
			if(s[i] == '.'){
				if(i == len - 1)return true;
				i++;
				j = i;
				while(j < len && s[j] == ' ')j++;
				if(j == len)return true;
				if(s[i] == ' ')return false;
				while(i < len && s[i] >= '0' && s[i] <= '9')i++;
				if(i == len)return true;
				if(s[i] == 'e'){
					if(i == len - 1)return false;
					i++;
					if(s[i] == '+' || s[i] == '-'){
						if(i == len - 1)return false;
						i++;
						while(i < len && s[i] >= '0' && s[i] <= '9')i++;
						if(i == len)return true;
						while(i < len && s[i] == ' ')i++;
						if(i == len)return true;
					}
					else{
						while(i < len && s[i] >= '0' && s[i] <= '9')i++;
						if(i == len)return true;
						while(i < len && s[i] == ' ')i++;
						if(i == len)return true;
					}
				}
				while(i < len && s[i] == ' ')i++;
				if(i == len)return true;
			}
			if(s[i] == 'e'){
				if(i == len - 1)return false;
				i++;
				if(s[i] == '+' || s[i] == '-'){
					if(i == len - 1)return false;
					i++;
					while(i < len && s[i] >= '0' && s[i] <= '9')i++;
					if(i == len)return true;
					while(i < len && s[i] == ' ')i++;
					if(i == len)return true;
				}
				else{
					while(i < len && s[i] >= '0' && s[i] <= '9')i++;
					if(i == len)return true;
					while(i < len && s[i] == ' ')i++;
					if(i == len)return true;
				}
			}
			while(i < len && s[i] == ' ')i++;
			if(i == len)return true;
			return false;
		}
		else if(s[i] >= '0' && s[i] <= '9'){
			if(i == len - 1)return true;
			while(i < len && s[i] >= '0' && s[i] <= '9')i++;
			if(i == len)return true;
			if(s[i] == '.'){
				if(i == len - 1)return true;
				i++;
				while(i < len && s[i] >= '0' && s[i] <= '9')i++;
				if(i == len)return true;
			}
			if(s[i] == 'e'){
				if(i == len - 1)return false;
				i++;
				if(s[i] == ' ')return false;
				if(s[i] == '+' || s[i] == '-'){
					if(i == len - 1)return false;
					i++;
					while(i < len && s[i] >= '0' && s[i] <= '9')i++;
					if(i == len)return true;
				}
				else{
					while(i < len && s[i] >= '0' && s[i] <= '9')i++;
					if(i == len)return true;
				}
			}
			while(i < len && s[i] == ' ')i++;
			if(i == len)return true;
			return false;
		}
		return false;
	}
};

//¼ò½à°æ
class Solution {
public:
	bool isNumber(const char *s) {
		if (s == NULL)return false;
		while(isspace(*s))s++;
		if (*s == '+' || *s == '-')s++;
		bool eAppear = false;
		bool dotAppear = false;
		bool firstPart = false;
		bool secondPart = false;
		bool spaceAppear = false;
		while(*s != '\0'){
			if (*s == '.'){
				if (dotAppear || eAppear || spaceAppear)return false;
				else dotAppear = true;
			}
			else if (*s == 'e' || *s == 'E'){
				if (eAppear || !firstPart || spaceAppear)return false;
				else eAppear = true;
			}
			else if (isdigit(*s)){
				if (spaceAppear)return false;
				if (!eAppear)firstPart = true;
				else secondPart = true;
			}
			else if (*s == '+' || *s == '-'){
				if (sapceAppear)return false;
				if (!eAppear || !(*(s-1) == 'e' || *(s-1) == 'E'))return false;
			}
			else if (isspace(*s))spaceAppear = true;
			else return false;
			s++;            
		}
		if (!firstPart)return false;
		else if (eAppear && !secondPart)return false;
		else return true;
	}
};
//second edition
class Solution {
public:
	bool isNumber(const char *s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		const char *s0 = s;
		while(*s != '\0' && *s == ' ')s++;
		if(*s == '\0')return false;
		bool sign = false,e = false,dot = false;
		while(*s != '\0'){
			if(*s == '+' || *s == '-'){
				if(sign || (e && *(s-1)!= 'e'))return false;
				sign = true;
				if( (s !=s0 && *(s-1) >= '0' && *(s-1) <= '9') ||
					*(s+1) == '\0' ||*(s+1) == 'e')return false;
			}
			else if(*s == '.'){
				if(dot || e)return false;
				dot = true;
				if( (s == s0 || *(s-1) < '0' || *(s-1) > '9') &&
					(*(s+1) == '\0' || *(s+1) < '0' || *(s+1) > '9') )return false;
			}
			else if(*s == 'e'){
				if(e)return false;
				e = true;
				if( (s == s0 || *(s-1) < '0' || *(s-1) > '9'
					|| *(s+1) == '.' || *(s+1) == ' ') && *(s-1) != '.' )return false;
				if(*(s+1) == '\0')return false;
				sign = false;
			}
			else if(*s == ' ')break;
			else if(*s < '0' || *s > '9')return false;
			s++;
		}
		while(*s != '\0' && *s == ' ')s++;
		return (*s == '\0');
	}
};
//ÓÐÏÞ×´Ì¬»ú£º×ªÒÆ¾ØÕóhttp://discuss.leetcode.com/questions/241/valid-number