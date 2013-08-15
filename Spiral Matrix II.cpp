class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int> > ans(n,vector<int>(n,0));
		vector<int> x,y;
		if(n == 0)return ans;
		int m = n - 1,bm = 0,i;
		if(n == 1){
			ans[0][0] = 1;
			return ans;
		}
		while(bm <= m){
			for(i = bm;i < m;i++){x.push_back(bm);y.push_back(i);}
			for(i = bm;i < m;i++){x.push_back(i);y.push_back(m);}
			if(bm < m){for(i = m;i > bm;i--){x.push_back(m);y.push_back(i);}}
			else {x.push_back(bm);y.push_back(m);}
			for(i = m;i > bm;i--){x.push_back(i);y.push_back(bm);}
			bm++;m--;
		}
		for(i = 0;i < n * n;i++)ans[x[i]][y[i]] = i + 1;
		return ans;
	}
};
//second edition
class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int> > matrix(n,vector<int>(n,0));
		if(n == 0)return matrix;
		if(n == 1){matrix[0][0] = 1;return matrix;}
		int i = 0,cnt = 1;
		for(i = 0;i < n/2;i++){
			for(int j = 0;j < n - 1 - 2 * i;j++)matrix[i][i+j] = cnt++;
			for(int j = 0;j < n - 1 - 2 * i;j++)matrix[i+j][n-1-i] = cnt++;
			for(int j = 0;j < n - 1 - 2 * i;j++)matrix[n-1-i][n-1-i-j] = cnt++;
			for(int j = 0;j < n - 1 - 2 * i;j++)matrix[n-1-i-j][i] = cnt++;
		}
		if(n % 2)matrix[n/2][n/2] = cnt;
		return matrix;
	}
};