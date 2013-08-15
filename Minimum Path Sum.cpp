//递归大数据超时
class Solution {
	vector<vector<int> > b;
	int m,n;
public:
	int minPathSum(vector<vector<int> > &grid) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(grid.empty())return 0;
		int i,ans = 0;
		m = grid.size();
		n = grid[0].size();
		b = grid;
		if(m == 1){
			for(i = 0;i < n;i++)ans += b[0][i];
			return ans;
		}
		if(n == 1){
			for(i = 0;i < m;i++)ans += b[i][0];
			return ans;
		}
		return minSum(0,0) + b[0][0];   
	}
	int minSum(int i,int j){
		int k,ans = 0;
		if(i == m - 1){
			for(k = j + 1;k < n;k++)ans += b[i][k];
			return ans;
		}
		if(j == n - 1){
			for(k = i + 1;k < m;k++)ans += b[k][j];
			return ans;
		}
		return min(b[i + 1][j] + minSum(i + 1,j),b[i][j + 1] + minSum(i,j + 1));
	}
};
//下改为动态规划：
class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(grid.empty())return 0;
		int i,j;
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int> > f = grid;
		for(i = n - 2;i >= 0;i--)f[m - 1][i] += f[m - 1][i + 1];
		for(i = m - 2;i >= 0;i--)f[i][n - 1] += f[i + 1][n - 1];
		for(i = m - 2;i >= 0;i--)
			for(j = n - 2;j >= 0;j--)
				f[i][j] += min(f[i + 1][j],f[i][j + 1]);
		return f[0][0];
	}
};