class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> ans;
		if(matrix.empty())return ans;
		int m = matrix.size() - 1;
		int n = matrix[0].size() - 1;
		int bm = 0,bn = 0,i,j,k;
		if(m == 0){
			for(i = 0;i <= n;i++)ans.push_back(matrix[0][i]);
			return ans;
		}
		if(n == 0){
			for(i = 0;i <= m;i++)ans.push_back(matrix[i][0]);
			return ans;
		}
		while(bm <= m && bn <= n){
			for(i = bn;i < n;i++)ans.push_back(matrix[bm][i]);
			for(i = bm;i < m;i++)ans.push_back(matrix[i][n]);
			if(bm < m){for(i = n;i > bn;i--)ans.push_back(matrix[m][i]);}
			else ans.push_back(matrix[bm][n]);
			if(bn < n){for(i = m;i > bm;i--)ans.push_back(matrix[i][bn]);}
			else if(bm != m) ans.push_back(matrix[m][n]);
			bm++;bn++;m--;n--;
		}
		return ans;
	}
};
//second edition
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> ans;
		int m = matrix.size();
		if(m == 0)return ans;
		int n = matrix[0].size();
		if(m == 1)return matrix[0];
		if(n == 1){for(int j = 0;j < m;j++)ans.push_back(matrix[j][0]);return ans;}
		int i = 0;
		for(i = 0;i < min(n/2,m/2);i++){
			for(int j = 0;j < n - 1 - 2 * i;j++)ans.push_back(matrix[i][i+j]);
			for(int j = 0;j < m - 1 - 2 * i;j++)ans.push_back(matrix[i+j][n-1-i]);
			for(int j = 0;j < n - 1 - 2 * i;j++)ans.push_back(matrix[m-1-i][n-1-i-j]);
			for(int j = 0;j < m - 1 - 2 * i;j++)ans.push_back(matrix[m-1-i-j][i]);
		}
		if(m % 2 && n % 2)ans.push_back(matrix[i][i]);
		else if(m % 2){
			for(int j = 0;j < n - 2 * i;j++)ans.push_back(matrix[i][i+j]);
		}
		else if(n % 2){
			for(int j = 0;j < m - 2 * i;j++)ans.push_back(matrix[i+j][n-1-i]);
		}
		return ans;
	}
};