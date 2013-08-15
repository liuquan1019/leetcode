//拿到难问题先想如何解决小规模和由小规模拓展至大规模，从而得到递归算法，进而可以剪枝（去掉一些不可能的情况提前到达出口）或者改为动归
class Solution {
public:
	bool isScramble(string s1, string s2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(s1.length() != s2.length())return false;
		if(s1 == s2)return true;
		string t1 = s1,t2 = s2;
		sort(t1.begin(),t1.end());
		sort(t2.begin(),t2.end());
		if(t1 != t2)return false;
		for(int i = 1;i < s1.length();i++){
			if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)))return true;
			if(isScramble(s1.substr(0,i),s2.substr(s2.length() - i)) && isScramble(s1.substr(i),s2.substr(0,s2.length() - i)))return true;
		}
		return false;
	}
};
/*动归:
dp[i][j][k] 代表了s1从i开始，s2从j开始，长度为k的两个substring是否为scramble string。
	有三种情况需要考虑：
	1. 如果两个substring相等的话，则为true
	2. 如果两个substring中间某一个点，左边的substrings为scramble string， 同时右边的substrings也为scramble string，则为true
	3. 如果两个substring中间某一个点，s1左边的substring和s2右边的substring为scramble string, 同时s1右边substring和s2左边的substring也为scramble string，则为true
*/

	public boolean isScramble(String s1, String s2)
{
	int n=s1.length();
	boolean[][][] dp=new boolean[n][n][n+1];

	for(int i=n-1; i>=0; i--)
		for(int j=n-1; j>=0; j--)
			for(int k=1; k<=n-Math.max(i,j);k++)
			{
				if(s1.substring(i,i+k).equals(s2.substring(j,j+k)))
					dp[i][j][k]=true;
				else
				{
					for(int l=1; l<k; l++)
					{
						if(dp[i][j][l] && dp[i+l][j+l][k-l] || dp[i][j+k-l][l] && dp[i+l][j][k-l])
						{
							dp[i][j][k]=true;
							break;
						}
					}
				}
			}

			return dp[0][0][n];
}
//second edition:忘了分解不能取整个字符串，否则有一个递归一直调用自身，导致runtime error
//即下面for循环中的i<n应改为i<n-1
class Solution {
public:
	bool isScramble(string s1, string s2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(s1 == s2)return true;
		int n = s1.length();
		if(n != s2.length() || n <= 1)return false;
		if(n == 2 && s1[0] == s2[1] && s1[1] == s2[0])return true;
		string t1 = "",t2 = "",t3 = "",r1 = s1,r2 = s2,r3 = s2,tmp1,tmp2,tmp3;
		for(int i = 0;i < n - 1;i++){
			t1.push_back(s1[i]);
			t2.push_back(s2[i]);
			t3.insert(t3.begin(),s2[n - 1 - i]);
			r1.erase(r1.begin());
			r2.erase(r2.begin());
			r3.erase(r3.end() - 1);
			tmp1 = t1;tmp2 = t2;tmp3 = t3;
			sort(tmp1.begin(),tmp1.end());
			sort(tmp2.begin(),tmp2.end());
			sort(tmp3.begin(),tmp3.end());
			if(tmp1 == tmp2 && isScramble(t1,t2) && isScramble(r1,r2))return true;
			if(tmp1 == tmp3 && isScramble(t1,t3) && isScramble(r1,r3))return true;
		}
		return false;
	}
};