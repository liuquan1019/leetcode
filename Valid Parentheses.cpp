class Solution {
public:
	bool isValid(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(s.length() <= 1)return false;
		stack<char> st;
		for(int i = 0;i < s.length();i++){
			if(s[i] == '(' || s[i] == '[' || s[i] == '{')st.push(s[i]);
			else{
				if(st.empty())return false;
				if(s[i] == ')' && st.top() != '(')return false;
				if(s[i] == ']' && st.top() != '[')return false;
				if(s[i] == '}' && st.top() != '{')return false;
				st.pop();
			}
		}
		return st.empty();
	}
};
//third edition
class Solution {
public:
	bool isValid(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		stack<char> st;
		for(int i = 0;i < s.length();i++){
			if(s[i] == '(' || s[i] == '[' || s[i] == '{')st.push(s[i]);
			else if(!st.empty() && ((s[i] == ')' && st.top() == '(') ||
				(s[i] == ']' && st.top() == '[') ||
				(s[i] == '}' && st.top() == '{')) )st.pop();
			else return false;
		}
		return st.empty();
	}
};