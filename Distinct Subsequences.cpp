//题意易理解错，of不仅表示“...的”，还表示“是...”,意思是T子串在S母串中出现的次数
//动归：长度为 i 的字串在长度为 j 的母串中出现的次数，设为 dp[i][j]，若母串的最后一个字符与子串的最后一个字符不同...
class Solution {
public:
	int numDistinct(string S, string T) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int sLen = S.length();
		int tLen = T.length();
		if(sLen < tLen)return 0;
		if(sLen == tLen && S == T)return 1;
		vector<vector<int> > dp(sLen + 1,vector<int>(tLen + 1,0));
		for(int i = 1;i <= sLen;i++)
			dp[i][1] = dp[i - 1][1] + (S[i - 1] == T[0]);
		for(int i = 2;i <= sLen;i++)
			for(int j = 2;j <= tLen;j++){
				if(S[i - 1] == T[j - 1])dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
				else dp[i][j] = dp[i - 1][j];
			}
			return dp[sLen][tLen];
	}
};

//另用滚动数组
class Solution {
public:
	int numDistinct(string S, string T) {
		vector<int> f(T.size()+1);
		f[T.size()] = 1;
		for (int i = S.size()-1; i >= 0; --i) {
			for (int j = 0; j < T.size(); ++j) {
				f[j] += (S[i]==T[j])*f[j+1];
			}
		}
		return f[0];
	}
};
//second edition:最先贪心，数重复元素的组合数，但是不够严谨，因为可能匹配源串后面的；可选可不选，改为递归
class Solution {
	string s,t;
	int n1,n2;
public:
	int numDistinct(string S, string T) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		s = S;t = T;
		n1 = s.length(),n2 = t.length();
		return num(0,0);
	}
	int num(int i,int j){
		if(j == n2)return 1;
		if(i == n1)return 0;
		if(n1 - i < n2 - j)return 0;
		if(n1 - i == n2 - j)return s.substr(i) == t.substr(j);
		int cnt = 0;
		for(;i < n1;i++)
			if(s[i] == t[j])cnt += num(i + 1,j + 1); 
		return cnt;
	}
};
//但大数据超时，递归单一路径降阶，按参数个数和内部循环数进行动归，矩阵维数为参数个数
class Solution {
public:
	int numDistinct(string S, string T) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n1 = S.length(),n2 = T.length();
		if(n1 < n2)return 0;
		if(n1 == n2)return S == T;
		vector<vector<int> > dp(n1+1,vector<int>(n2+1,0));
		for(int i = 0;i <= n1;i++)dp[i][n2] = 1;
		for(int i =n1 - 1;i >= 0;i--)
			for(int j = n2 - 1;j >= 0;j--){
				int k = i;
				for(;k < n1;k++)
					if(S[k] == T[j])dp[i][j] += dp[k+1][j+1];
				if(dp[i][j] == 0)break;
			}
			return dp[0][0];
	}
};
//O(n^3)仍超时，优化递归内部，修改动归方程变成O(n^2)
class Solution {
public:
	int numDistinct(string S, string T) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n1 = S.length(),n2 = T.length();
		if(n1 < n2)return 0;
		if(n1 == n2)return S == T;
		vector<vector<int> > dp(n1+1,vector<int>(n2+1,0));
		for(int i = 0;i <= n1;i++)dp[i][n2] = 1;
		for(int i =n1 - 1;i >= 0;i--)
			for(int j = n2 - 1;j >= 0;j--){
				if(S[i] == T[j])dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
				else dp[i][j] = dp[i+1][j];
			}
			return dp[0][0];
	}
};