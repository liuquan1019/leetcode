class Solution {
public:
	bool isPalindrome(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(s.empty())return true;
		int i,j;
		for(i = 0,j = s.size() - 1;i < j;){
			if(!isValid(s[i]))i++;
			else if(!isValid(s[j]))j--;
			else if(s[i] != s[j])return false;
			else {i++;j--;}
		}
		return true;
	}
private:
	bool isValid(char &t){
		if(t >= 'A' && t <= 'Z')t = t + 'a' - 'A';
		if(t >= '0' && t <= '9')return true;
		else if(t >= 'a' && t <= 'z')return true;
		return false;
	}
};
//second edition
class Solution {
public:
	bool isPalindrome(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(s.length() == 0)return true;
		int n = 0,i,j;
		for(i = 0;i < s.length();i++){
			if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z'))s[n++] = s[i];
			else if((s[i] >= 'A' && s[i] <= 'Z'))s[n++] = s[i] + 'a' - 'A';
		}
		i = 0;j = n - 1;
		while(i < j){
			if(s[i] == s[j]){i++;j--;}
			else return false;
		}
		return true;
	}
};