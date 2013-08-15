class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int i,j,k,ans = 0,width;
		int f[1000][1000];
		for(i = 0;i < matrix.size();i++)
			f[i][0] = (matrix[i][0] == '1');
		for(i = 0;i < matrix.size();i++)
			for(j = 1;j < matrix[i].size();j++)
				f[i][j] = matrix[i][j] == '1' ? f[i][j - 1] + 1 : 0;

		for(i = 0;i < matrix.size();i++)
			for(j = 0;j < matrix[i].size();j++){
				if(f[i][j] == 0)continue;
				k = i;
				width = 1000;
				while(k >= 0){
					width = min(width,f[k][j]);
					ans = max(ans,width * (i - k + 1));
					k--;
				}
			}
			return ans;
	}
};
//second edition仿照前题弹栈做法:每次都找该行连续1的个数，重复，不如之前做法
class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int m = matrix.size();
		if(m == 0)return 0;
		int n = matrix[0].size();
		int maxSize = 0;
		for(int i = 0;i < m;i++)
			for(int j = 0;j < n;j++)
				if(matrix[i][j] == '1'){
					stack<int> s;
					int t = i;
					while(t < m && matrix[t][j] == '1'){
						int k = j + 1;
						while(k < n &&matrix[t][k] == '1')k++;
						if(s.empty() || s.top() < k - j)s.push(k-j);
						else{
							int cnt = 1;
							while(!s.empty() && s.top() > k - j){
								maxSize = max(maxSize,cnt*s.top());
								s.pop();
								cnt++;    
							}
							while(cnt > 0){s.push(k-j);cnt--;}
						}
						t++;
					}
					int cnt = 0;
					while(!s.empty()){cnt++;maxSize = max(maxSize,cnt * s.top());s.pop();}
				}
				return maxSize;
	}
};