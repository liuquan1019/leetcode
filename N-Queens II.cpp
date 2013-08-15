class Solution {
	int cnt;
	int N;
	bool vert[20];
	bool left[40];
	bool right[40];
public:
	int totalNQueens(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n <= 0 || n == 2)return 0;
		if(n == 1)return 1;
		N = n;
		cnt = 0;
		for(int i = 0;i < n;i++){
			vert[i] = true;
			left[2 * i] = true;
			left[2 * i + 1] = true;
			right[2 * i] = true;
			right[2 * i + 1] = true;
		}
		queen(0);
		return cnt;
	}
	void queen(int row){
		if(row == N){
			cnt++;
			return;
		}
		for(int i = 0;i < N;i++){
			if(vert[i] && left[i + row] && right[i - row + N]){
				//mark i as queen
				vert[i] = false;
				left[i + row] = false;
				right[i - row + N] = false;
				queen(row + 1);
				vert[i] = true;
				left[i + row] = true;
				right[i - row + N] = true;
			}
		}
	}
};