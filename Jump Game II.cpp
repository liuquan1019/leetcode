class Solution {
public:
	int jump(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> f(n,INT_MAX);
		f[0] = 0;
		int i,j;
		int far = 0;
		for(i = 0;i < n - 1;i++){
			for(j = far + 1;j <= i + A[i] && j < n;j++){
				f[j] = min(f[j],f[i] + 1);
			}
			far = i + A[i];
		}
		return f[n - 1];
	}
};
//second edition:最后一组大数据超时
class Solution {
public:
	int jump(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> dp(n,INT_MAX);
		dp[n - 1] = 0;
		int i,j,upper;
		for(i = n - 2;i >= 0;i--){
			//if(A[i] ==A[i+1] + 1){dp[i] = dp[i+1] + 1;continue;}
			upper = min(n - 1,i + A[i]);
			for(j = upper;j > i;j--)
				if(dp[j] != INT_MAX)dp[i] = min(dp[i],dp[j]+1);
		}
		return dp[0];
	}
};
//third edition:其实数组没必要，用一个最大值保存即可，空间缩为O(1)
class Solution {
public:
	int jump(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n <= 1)return 0;
		vector<int> reach(n,-1);
		reach[0] = 0;
		int far = 0;
		for(int i = 0;i < n;i++)
			if(reach[i] >= 0){
				for(int j = far + 1;j <= i + A[i] && j < n;j++)reach[j] = reach[i] + 1;
				far = max(far,i + A[i]);
			}
			return reach[n-1];
	}
};