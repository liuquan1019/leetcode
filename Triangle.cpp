class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int row = triangle.size();
		if(row == 0)return 0;
		for(int i = row - 1;i > 0;i--)
			for(int j = 0;j < i;j++)
				triangle[i - 1][j] += min(triangle[i][j],triangle[i][j + 1]);
		return triangle[0][0];
	}
};