struct point{
	int x,y;
	point(int x_,int y_){
		x = x_;y = y_;
	}
};
class Solution {
	bool row[9][10];
	bool column[9][10];
	bool grid[3][3][10];
	vector<point> v;
	vector<vector<char> > b;
public:
	void solveSudoku(vector<vector<char> > &board) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int i,j;
		v.clear();
		b = board;
		assert(board.size() == 9);
		for(i = 0;i < 9;i++)
			for(j = 0;j < 10;j++){
				row[i][j] = true;
				column[i][j] = true;
				grid[i / 3][i % 3][j] = true;
			}
			for(i = 0;i < 9;i++)
				for(j = 0;j < 9;j++){
					if(board[i][j] != '.'){
						grid[i / 3][j / 3][board[i][j] - '0'] = false;
						row[i][board[i][j] - '0'] = false;
						column[j][board[i][j] - '0'] = false;
					}
					else v.push_back(point(i,j));
				}
				dfs(0,board);
	}
	void dfs(int k,vector<vector<char> > &board){
		if(k == v.size()){board = b;return;}
		for(int i = 1;i < 10;i++){
			if(row[v[k].x][i] && column[v[k].y][i] && grid[v[k].x / 3][v[k].y / 3][i]){
				b[v[k].x][v[k].y] = i + '0';
				row[v[k].x][i] = false;
				column[v[k].y][i] = false;
				grid[v[k].x / 3][v[k].y / 3][i] = false;

				dfs(k + 1,board);

				b[v[k].x][v[k].y] = '.';
				row[v[k].x][i] = true;
				column[v[k].y][i] = true;
				grid[v[k].x / 3][v[k].y / 3][i] = true;
			}
		}
	}
};
//second edition一个bug在于回溯时要将符合要求的解保存下来再return,否则最终运行完时又复原为初始棋盘样子
#include<string.h>
class Solution {
	bool hori[9][10];
	bool vert[9][10];
	bool squa[3][3][10];
	vector<vector<char> > b;
public:
	void solveSudoku(vector<vector<char> > &board) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		memset(hori,true,sizeof(hori));
		memset(vert,true,sizeof(vert));
		memset(squa,true,sizeof(squa));
		int cnt = 0;
		for(int i = 0;i < 9;i++)
			for(int j = 0;j < 9;j++)
				if(board[i][j] != '.'){
					hori[i][board[i][j] - '0'] = false;
					vert[j][board[i][j] - '0'] = false;
					squa[i/3][j/3][board[i][j] - '0'] = false;
				}
				else cnt++;
				fill(board,cnt);
				board = b;
	}
	void fill(vector<vector<char> > &board,int cnt){
		if(cnt == 0){b = board;return;}
		for(int i = 0;i < 9;i++)
			for(int j = 0;j < 9;j++)
				if(board[i][j] == '.'){
					for(int k = 1;k <= 9;k++){
						if(hori[i][k] && vert[j][k] && squa[i/3][j/3][k]){
							hori[i][k]=false;vert[j][k]=false;squa[i/3][j/3][k]=false;
							board[i][j] = '0' + k;
							fill(board,cnt - 1);
							hori[i][k]=true;vert[j][k]=true;squa[i/3][j/3][k]=true;
							board[i][j] = '.';
						}
					}
					return;
				}
	}
};