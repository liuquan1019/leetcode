class Solution {
	vector<vector<string> > ans;
	int N;
	bool vert[20];
	bool left[40];
	bool right[40];
	char S[20];
public:
	vector<vector<string> > solveNQueens(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ans.clear();
		if(n <= 0 || n == 2)return ans;
		vector<string> v;
		v.push_back("Q");
		ans.push_back(v);
		if(n == 1)return ans;
		N = n;
		for(int i = 0;i < 20;i++)S[i] = '\0';
		for(int i = 0;i < n;i++){
			vert[i] = true;
			left[2 * i] = true;
			left[2 * i + 1] = true;
			right[2 * i] = true;
			right[2 * i + 1] = true;
			S[i] = '.';
		}
		v.clear();
		ans.clear();
		queen(0,v);
		return ans;
	}
	void queen(int row,vector<string> &v){
		if(row == N){
			ans.push_back(v);
			return;
		}
		for(int i = 0;i < N;i++){
			if(vert[i] && left[i + row] && right[i - row + N]){
				//mark i as queen
				string temp = S;
				temp[i] = 'Q';
				v.push_back(temp);
				vert[i] = false;
				left[i + row] = false;
				right[i - row + N] = false;
				queen(row + 1,v);
				v.pop_back();
				vert[i] = true;
				left[i + row] = true;
				right[i - row + N] = true;
			}
		}
	}
};