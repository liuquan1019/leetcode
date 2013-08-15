/*
������Ҫ����d(i,j)ʱ��������A(i)��B(j)֮��ı༭���룬��ʱ����A(i)��ʽ��somestr1c��B(i)����somestr2d�Ļ���
��somestr1���somestr2�ı༭������֪��d(i-1,j-1)

��somestr1c���somestr2�ı༭������֪��d(i,j-1)
��somestr1���somestr2d�ı༭������֪��d(i-1,j)
��ô�����������������Ϳ��Ե��Ƴ�d(i,j)�ˣ�
���c==d����Ȼ�༭�����d(i-1,j-1)��һ����
���c!=d�������΢����һ�㣬
�����c�滻��d���༭������somestr1���somestr2�ı༭���� + 1��Ҳ����d(i-1,j-1) + 1
�����c�������һ����d���༭�����Ӧ����somestr1c���somestr2�ı༭���� + 1��Ҳ����d(i,j-1) + 1
�����cɾ���ˣ��Ǿ���Ҫ��somestr1�༭��somestr2d���������d(i-1,j) + 1
�����ֻ��Ҫ��������˭��С���Ͳ��ö�Ӧ�ı༭�����ˡ�
���ƹ�ʽ�����ˣ�
dp[i][j] =  dp[i-1][j-1]   if (A[i] == B[j])
or = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) +1;

��ʼ������ dp[0][j] = j and dp[i][0] = i   
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
//second edition:�±�ѡ��0��ʼ�����±߽������Ƚϸ���
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