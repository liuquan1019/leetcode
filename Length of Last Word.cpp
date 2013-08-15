class Solution {
public:
	int lengthOfLastWord(const char *s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len = strlen(s);
		int i = len - 1;
		if(len == 0)return 0;
		while(i >= 0 && s[i] == ' ')i--;
		if(i == -1)return 0;
		int j;
		for(j = i - 1;j >= 0;j--)
			if(s[j] == ' ')break;
		return i - j;    

	}
};
//second edition
class Solution {
public:
	int lengthOfLastWord(const char *s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int cnt = 0;
		while(*s != '\0'){
			if(*s != ' '){cnt++;s++;}
			else{
				while(*s == ' ')s++;
				if(*s != '\0')cnt = 0;
			}
		}
		return cnt;
	}
};