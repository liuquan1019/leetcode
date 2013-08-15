/*
当我们要计算d(i,j)时，即计算A(i)到B(j)之间的编辑距离，此时，设A(i)形式是somestr1c；B(i)形如somestr2d的话，
将somestr1变成somestr2的编辑距离已知是d(i-1,j-1)

将somestr1c变成somestr2的编辑距离已知是d(i,j-1)
将somestr1变成somestr2d的编辑距离已知是d(i-1,j)
那么利用这三个变量，就可以递推出d(i,j)了：
如果c==d，显然编辑距离和d(i-1,j-1)是一样的
如果c!=d，情况稍微复杂一点，
如果将c替换成d，编辑距离是somestr1变成somestr2的编辑距离 + 1，也就是d(i-1,j-1) + 1
如果在c后面添加一个字d，编辑距离就应该是somestr1c变成somestr2的编辑距离 + 1，也就是d(i,j-1) + 1
如果将c删除了，那就是要将somestr1编辑成somestr2d，距离就是d(i-1,j) + 1
那最后只需要看着三种谁最小，就采用对应的编辑方案了。
递推公式出来了：
dp[i][j] =  dp[i-1][j-1]   if (A[i] == B[j])
or = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) +1;

初始条件： dp[0][j] = j and dp[i][0] = i   
*/class Solution {
public:
	int minDistance(string word1, string word2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(word1.length() == 0)return word2.length();
		if(word2.length() == 0)return word1.length();
		int f[1000][1000];
		int i,j;
		for(i = 1;i <= word1.length();i++)f[i][0] = i;
		for(i = 1;i <= word2.length();i++)f[0][i] = i;
		for(i = 1;i <= word1.length();i++)
			for(j = 1;j <= word2.length();j++){
				if(word1[i - 1] == word2[j - 1])f[i][j] = f[i - 1][j - 1];
				else
					f[i][j] = min(f[i - 1][j],f[i][j - 1],f[i - 1][j - 1]) + 1;
			}
			return f[word1.length()][word2.length()];
	}
	int min(int a,int b,int c){
		if(a <= b && a <= c)return a;
		if(b <= a && b <= c)return b;
		return c;
	}
};
//second edition:下标选从0开始，导致边界条件比较复杂
class Solution {
public:
	int minDistance(string word1, string word2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n1 = word1.length(),n2 = word2.length();
		if(n1 == 0)return n2;
		if(n2 == 0)return n1;
		vector<vector<int> > dp(n1,vector<int>(n2,0));
		int i;

		for(i = 0;i < n1;i++)
			if(word1[i] == word2[0]){dp[i][0] = i;break;}
			else dp[i][0] = i + 1;
			i++;
			for(;i < n1;i++)dp[i][0] = dp[i-1][0] + 1;

			for(i = 0;i < n2;i++)
				if(word2[i] == word1[0]){dp[0][i] = i;break;}
				else dp[0][i] = i + 1;
				i++;
				for(;i < n2;i++)dp[0][i] = dp[0][i-1] + 1;

				for(i = 1;i < n1;i++)
					for(int j = 1;j < n2;j++){
						if(word1[i] == word2[j])dp[i][j] = dp[i-1][j-1];
						else dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + 1;
					}
					return dp[n1-1][n2-1];
	}
	int min(int a,int b,int c){
		if(a <= b && a <= c)return a;
		if(b <= c)return b;
		return c;
	}
};