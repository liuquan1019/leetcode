class Solution {
public:
	int numTrees(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n <= 2)return n;
		vector<int> f(100,0);
		f[0] = 1;
		f[1] = 1;
		for(int i = 2;i <= n;i++)
			for(int j = 1;j <= i;j++)
				f[i] += f[j - 1] * f[i - j];
		return f[n];
	}
};
//一般只求结果的数量而不要求所有可能的解就可能用DP来解决了
//second edition
class Solution {
public:
	int numTrees(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> dp(n+1,0);
		dp[0] = 1;dp[1] = 1;
		for(int i = 2;i <= n;i++)
			for(int j = 1;j <= i;j++)
				dp[i] += dp[j-1] * dp[i-j];
		return dp[n];
	}
};