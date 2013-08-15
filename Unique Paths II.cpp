class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(obstacleGrid.empty())return 0;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if(m <= 0 || n <= 0 || obstacleGrid[m - 1][n - 1] || obstacleGrid[0][0])return 0;
		if(m == 1 || n == 1)return 1;
		vector<vector<int> > f(m,vector<int>(n,0));
		f[m - 1][n - 1] = 1;
		for(int i = m - 2;i >= 0;i--){
			if(obstacleGrid[i][n - 1])break;
			else f[i][n - 1] = 1;
		}
		for(int i = n - 2;i >= 0;i--){
			if(obstacleGrid[m - 1][i])break;
			else f[m - 1][i] = 1;
		}
		for(int i = m - 2;i >= 0;i--)
			for(int j = n - 2;j >= 0;j--){
				if(obstacleGrid[i][j])f[i][j] = 0;
				else f[i][j] = f[i + 1][j] + f[i][j + 1];
			}
			return f[0][0];
	}
};