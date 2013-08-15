class Solution {
public:
	vector<string> generateParenthesis(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<string> ans;
		if(n == 0)return ans;
		ans.push_back("()");
		if(n == 1)return ans;
		ans.clear();
		vector<string> temp = generateParenthesis(n - 1);
		for(int i = 0;i < temp.size();i++){
			ans.push_back("()" + temp[i]);
			for(int j = 1;j <= temp[i].size();j++){
				if(temp[i][j - 1] == '('){
					string t = temp[i];
					t.insert(j,")");
					t = "(" + t;
					ans.push_back(t);
				}
			}
		}
		sort(ans.begin(),ans.end());
		for(int i = 0;i < ans.size() - 1;)
			if(ans[i] == ans[i + 1])ans.erase(ans.begin() + i);
			else i++;
			return ans;
	}
};
//以上解法从降低n即问题的规模入手递归，也可直接递归生成字符串：
//当左括号出现次数<n时，就可以放置新的左括号。当右括号出现次数小于左括号出现次数时，就可以放置新的右括号
class Solution {
public:
	vector<string> result;
	void next(string str, int nl, int nr)
	{
		if((nl == 0) && (nr == 0)) result.push_back(str);
		if((nl > 0) && (nr >= nl)) next(str + "(", nl - 1, nr);
		if((nr > 0) && (nr >= nl)) next(str + ")", nl, nr - 1);
	}
	vector<string> generateParenthesis(int n) {
		result.clear();
		next("", n, n);
		return result;
	}
};
//second edition
class Solution {
	vector<string> ans;
public:
	vector<string> generateParenthesis(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ans.clear();
		generate(0,n,"");
		return ans;
	}
	void generate(int openLeftNum, int leftNum,string s){
		if(leftNum == 0){
			string temp(openLeftNum,')');
			ans.push_back(s + temp);
			return;
		}
		if(leftNum > 0)generate(openLeftNum + 1,leftNum - 1,s + '(');
		if(openLeftNum > 0)generate(openLeftNum - 1,leftNum,s + ')');
	}
};
//third edition
class Solution {
	vector<string> ans;
	int n;
public:
	vector<string> generateParenthesis(int m) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ans.clear();
		n = m;
		if(n == 0)return ans;
		generate(0,0,"");
		return ans;
	}
	void generate(int left,int right,string s){
		if(left == n){
			string tmp(n-right,')');
			ans.push_back(s + tmp);
			return;
		}
		generate(left+1,right,s+"(");
		if(left > right)generate(left,right+1,s+")");
	}
};
