//递归，大数据超时；
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    
		if(s3.length() != s1.length() + s2.length())return false;
		if(s3.length() == 0)return true;
		if(s1.length() != 0){
			if(s3[0] == s1[0]){
				string s33 = s3;
				s33.erase(s33.begin());
				string s11 = s1;
				s11.erase(s11.begin());
				if(isInterleave(s11,s2,s33))return true;
			}
		}
		if(s2.length() != 0){
			if(s3[0] == s2[0]){
				string s33 = s3;
				s33.erase(s33.begin());
				string s22 = s2;
				s22.erase(s22.begin());
				if(isInterleave(s1,s22,s33))return true;
			}
		}
		return false;
	}
};
//但递归是可以过这个题的。只注意了字符串头的比较，没有注意字符串尾的比较。同时考虑字符串尾可以剪掉很多不必要的分支。
//同时注意不要每次生成新的字符串，递归情况下非常耗时会导致仍然超时，可改为传下标

/*从易想的递归可以总结出:
isInterleaving(s1,len1,s2,len2,s3,len3) = 
(s3.lastChar == s1.lastChar) && isInterleaving(s1,len1 - 1,s2,len2,s3,len3 - 1)||
(s3.lastChar == s2.lastChar) && isInterleaving(s1,len1,s2,len2 - 1,s3,len3 - 1)
其中子问题：si取前leni个字符。
问题里面实际上存在着两个变量，是一个二维动态规划题目。
从矩阵的角度来看的话，每一个元素的值，依赖于它的上边和左边两个值
定义 match[i][j] 意味着，S1的(0, i)和S2的(0,j)，匹配与S3的(i+j)
如果 ai == c(i+j), 那么 match[i][j] = match[i-1][j]，
同理，如果bj = c(i+j), 那么match[i][j] = match[i][j-1];

Match[i][j]
=   (s3.lastChar == s1.lastChar) && Match[i-1][j]
||(s3.lastChar == s2.lastChar) && Match[i][j-1]
初始条件：
i=0 && j=0时，Match[0][0] = true;
i=0时， s3[j] = s2[j], Match[0][j] |= Match[0][j-1]
s3[j] != s2[j], Match[0][j] = false;

j=0时， s3[i] = s1[i], Match[i][0] |= Match[i-1][0]
s3[i] != s1[i], Match[i][0] = false;

*/
class Solution {
private:
	bool f[1000][1000];
public:
	bool isInterleave(string s1, string s2, string s3) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function 
		if (s1.size() + s2.size() != s3.size())
			return false;

		f[0][0] = true;
		for(int i = 1; i <= s1.size(); i++)
			f[i][0] = f[i-1][0] && (s3[i-1] == s1[i-1]);

		for(int j = 1; j <= s2.size(); j++)
			f[0][j] = f[0][j-1] && (s3[j-1] == s2[j-1]);

		for(int i = 1; i <= s1.size(); i++)
			for(int j = 1; j <= s2.size(); j++)
				f[i][j] = (f[i][j-1] && s2[j-1] == s3[i+j-1]) || (f[i-1][j] && s1[i-1] == s3[i+j-1]);

		return f[s1.size()][s2.size()];
	}
};
//second edition
class Solution {
	int n1,n2,n3;
	string s1,s2,s3;
public:
	bool isInterleave(string S1, string S2, string S3) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    
		s1 = S1;s2 = S2;s3 = S3;
		n1 = s1.length();n2 = s2.length();n3 = s3.length();
		if(n3 != n1 + n2)return false;
		return isInter(0,0,0);
	}
	bool isInter(int i,int j,int k){
		if(k == n3)return true;
		if(i == n1)return s2.substr(j) == s3.substr(k);
		if(j == n2)return s1.substr(i) == s3.substr(k);
		if(s3[k] != s1[i] && s3[k] != s2[j])return false;
		if(s1[i] == s2[j])return isInter(i+1,j,k+1) || isInter(i,j+1,k+1);
		if(s1[i] == s3[k])return isInter(i+1,j,k+1);
		return isInter(i,j+1,k+1);
	}
};
//大数据超时，又改为动归
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    
		int n1 = s1.length(),n2 = s2.length(),n3 = s3.length();
		if(n1+n2 != n3)return false;
		vector<vector<bool> > dp(n1+1,vector<bool>(n2+1,false));
		dp[n1][n2] = true;
		for(int i = n1-1;i>=0;i--)dp[i][n2] = dp[i+1][n2] && (s1[i] == s3[n3-n1+i]);
		for(int i = n2-1;i>=0;i--)dp[n1][i] = dp[n1][i+1] && (s2[i] == s3[n3-n2+i]);
		for(int i = n1-1;i >= 0;i--)
			for(int j = n2-1;j >= 0;j--){
				if(dp[i+1][j] && s1[i] == s3[n3-n1-n2+i+j])dp[i][j] = true;
				if(dp[i][j+1] && s2[j] == s3[n3-n1-n2+i+j])dp[i][j] = true;
			}
			return dp[0][0];
	}
};