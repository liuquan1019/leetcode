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
		for(int i = 1;i <= n;i++){//�ɼ�֦����Ϊ�Ӵ�С��һ�������ݷ���������
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
D[i,n] = min(D[i, j] + D[j+1,n])  i<=j <n�����Ǹ���ά�ĺ�����ʵ��д����ʱά���Ƚ��鷳��
����Ҫת����һάDP�����ÿ�Σ���i����ɨ�裬ÿ�ҵ�һ�����ľ���һ��DP�Ļ����Ϳ���ת��Ϊ
D[i] = ����[i,n]֮����С��cut����nΪ�ַ������ȣ� ��D[i] = min(1+D[j+1] )    i<=j <n

����ж�[i,j]�Ƿ��ǻ��ģ�Ҳ��һ��DP���⡣���庯��P[i][j] = true if [i,j]Ϊ����
��ôP[i][j] = str[i] == str[j] && P[i+1][j-1];
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