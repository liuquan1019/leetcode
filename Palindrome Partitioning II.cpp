class Solution {
	int len;
public:
	int minCut(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(s.length() == 0)return 0;
		len = s.length() - 1;
		dfs(s,-1);
		return len;
	}
	void dfs(string s,int step){
		int n = s.length();
		if(n == 0){len = min(len,step);return;}
		if(step >= len)return;
		for(int i = 1;i <= n;i++){//可剪枝：改为从大到小，一旦有数据返回则跳出
			int j = 0,k = i - 1;
			while(j < k){
				if(s[j] == s[k]){j++;k--;}
				else break;
			}
			if(j >= k){
				string s2 = s.substr(i);
				dfs(s2,step+1);
			}
		}
	}
};
/*
D[i,n] = min(D[i, j] + D[j+1,n])  i<=j <n。这是个二维的函数，实际写代码时维护比较麻烦。
所以要转换成一维DP。如果每次，从i往右扫描，每找到一个回文就算一次DP的话，就可以转换为
D[i] = 区间[i,n]之间最小的cut数，n为字符串长度， 则D[i] = min(1+D[j+1] )    i<=j <n

如何判断[i,j]是否是回文？也是一个DP问题。定义函数P[i][j] = true if [i,j]为回文
那么P[i][j] = str[i] == str[j] && P[i+1][j-1];
*/
int minCut(string s) {  
	int len = s.size();  
	int D[len+1];  
	bool P[len][len];  
	//the worst case is cutting by each char  
	for(int i = 0; i <= len; i++)D[i] = len-i;  
	for(int i = 0; i < len; i++)  
		for(int j = 0; j < len; j++)  
		    P[i][j] = false;  
	for(int i = len-1; i >= 0; i--)  
		for(int j = i; j < len; j++)  
			if(s[i] == s[j] && (j-i<2 || P[i+1][j-1])){  
				P[i][j] = true;  
				D[i] = min(D[i],D[j+1]+1);  
			}  
	return D[0]-1;  
} 