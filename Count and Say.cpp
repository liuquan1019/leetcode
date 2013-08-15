class Solution {
public:
	string countAndSay(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		string s = "1";
		for(int i = 2;i <= n;i++){
			string t = s;
			s.clear();
			string temp2(1,'1');
			for(int j = 0;j < t.length();j++){
				if(j < t.length() - 1 && t[j] == t[j + 1]){
					int k = j + 1;
					while(k < t.length() && t[j] == t[k])k++;
					temp2[0] = k - j + '0';
					s += temp2;
					temp2[0] = t[j];
					s += temp2;
					j = k - 1;
				}
				else {
					temp2[0] = '1';
					s += temp2;
					temp2[0] = t[j];
					s += temp2;
				}  
			}
		}
		return s;
	}
};
//second edition
class Solution {
public:
	string countAndSay(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		string s1 = "1",s2 = "1";
		for(int i = 2; i <= n;i++){
			s2 = "";
			for(int j = 0;j < s1.length();j++){
				int cnt = 1;
				while(s1[j] == s1[j+1]){cnt++;j++;}
				s2.push_back('0' + cnt);
				s2.push_back(s1[j]);
			}
			s1 = s2;
		}
		return s2;
	}
};