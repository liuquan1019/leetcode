class Solution {
private:
	string letter[10];
	vector<string> ans;
	string digit;
public:
	vector<string> letterCombinations(string digits) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		digit = digits;
		letter[2] = "abc";letter[3] = "def";letter[4] = "ghi";
		letter[5] = "jkl";letter[6] = "mno";letter[7] = "pqrs";
		letter[8] = "tuv";letter[9] = "wxyz";
		ans.clear();
		cat("",0);
		return ans;
	}
	void cat(string s,int index){
		if(index == digit.length()){
			ans.push_back(s);
			return;
		}
		for(int i = 0;i < letter[digit[index] - '0'].length();i++){
			s.push_back(letter[digit[index] - '0'][i]);
			cat(s,index + 1);
			s.pop_back();
		}
	}
};
//third edition
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = digits.length(),i = 0;
		string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		string s = "";
		for(i = 0;i < n;i++)s.push_back(map[digits[i] - '0'][0]);
		vector<string> ans;
		ans.push_back(s);
		while(i >= 0){
			for(i = n - 1;i >= 0;i--){
				if(s[i] == map[digits[i] - '0'][map[digits[i] - '0'].length() - 1])
					s[i] = map[digits[i] - '0'][0];
				else{
					int j = 0;
					for(;j < map[digits[i] - '0'].length();j++)
						if(map[digits[i] - '0'][j] == s[i])break;
					s[i] = map[digits[i] - '0'][j + 1];
					ans.push_back(s);
					break;
				}
			}
		}
		return ans;
	}
};