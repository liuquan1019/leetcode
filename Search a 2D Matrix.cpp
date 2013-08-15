class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(matrix.empty())return false;
		int m = matrix.size();
		int n = matrix[0].size();
		if(matrix[0][0] > target || matrix[m - 1][n - 1] < target)return false;
		int left = 0,right = m - 1,mid = 0;
		while(left < right){
			mid = (left + right) / 2;
			if(matrix[right][0] <= target){mid = right;break;}
			if(matrix[mid][0] <= target && (matrix[mid + 1][0] > target || mid == m - 1))break;
			if(matrix[mid][0] < target)left = mid; 
			else right = mid;
		}
		return binearySearch(matrix[mid],0,matrix[mid].size() - 1,target);
	}
	bool binearySearch(vector<int> &v,int l,int r,int t){
		if(l == r && v[l] != t)return false;
		int m = (l + r) / 2;
		if(v[m] == t)return true;
		if(v[r] == t)return true;
		if(v[m] < t && v[m + 1] > t)return false;
		if(v[m] < t)return binearySearch(v,m + 1,r,t);
		return binearySearch(v,l,m,t);
	}
};
//second edition
class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int m = matrix.size();
		if(m == 0)return false;
		int n = matrix[0].size();
		int i = 0,j = n - 1;
		while(i < m && j >= 0){
			if(matrix[i][j] == target)return true;
			else if(matrix[i][j] < target)i++;
			else j--;
		}
		return false;
	}
};