//memory limit exceeded:bfs能过，dfs看来还是递归太深
class Solution {
	vector<vector<bool> > visited;
	vector<vector<char>> b;
	int n;
	vector<pair<int,int> > v;
public:
	void solve(vector<vector<char>> &board) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		n = board.size();
		if(n <= 2)return;
		visited = vector<vector<bool>>(n,vector<bool>(n,false));
		b = board;
		for(int i = 1;i < n - 1;i++)
			for(int j = 1;j < n - 1;j++){
				if(b[i][j] == 'X' || visited[i][j])continue;
				v.clear();
				visited[i][j] = true;
				if(b[i - 1][j] == 'O' || b[i][j - 1] == 'O')continue;
				if(b[i + 1][j] == 'X' && b[i][j + 1] == 'X'){board[i][j] = 'X';continue;}
				v.push_back(make_pair(i,j));
				bool right = true,down = true;
				if(b[i + 1][j] == 'O')down = dfs(i + 1,j);
				if(b[i][j + 1] == 'O')right = dfs(i,j + 1);
				if(down && right)
					for(int k = 0;k < v.size();k++)board[v[k].first][v[k].second] = 'X';
			}
	}
	bool dfs(int i,int j){
		visited[i][j] = true;
		v.push_back(make_pair(i,j));
		if(i == n - 1 || j == n - 1)return false;
		if(b[i + 1][j] == 'X' && b[i][j + 1] == 'X')return true;
		bool right = true,down = true;
		if(b[i + 1][j] == 'O')down = dfs(i + 1,j);
		if(b[i][j + 1] == 'O')right = dfs(i,j + 1);
		return right && down;
	}
};
/*有个更简单的思路（以上较为通用），因为不被包围的最终必然通到矩阵的4条边界上，
1.First scan the four edges of the board, if you meet an 'O', call a recursive mark function to mark that 
region to something else (for example, '+');
2.scan all the board, if you meet an 'O', flip it to 'X';
3.scan again the board, if you meet an '+', flip it to 'O';
step 2 and 3 can be merged.
*/
public class Solution {
	int m,n;
	char[][] board;
	void dfs(int x, int y){
		if(x<0 || x>=m || y<0 || y>=n || board[x][y]!='O') return;
		board[x][y]='D';
		dfs(x-1,y);
		dfs(x+1,y);
		dfs(x,y-1);
		dfs(x,y+1);
	}
	public void solve(char[][] board){
		if(board==null || board.length==0) return;
		this.board=board;
		m=board.length;
		n=board[0].length;
		for(int j=0;j<n;j++){
			dfs(0,j);
			dfs(m-1,j);
		}
		for(int i=1;i<m-1;i++){
			dfs(i,0);
			dfs(i,n-1);
		}
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++){
				if(board[i][j]=='O') board[i][j]='X';
				else if(board[i][j]=='D') board[i][j]='O';
			}  
	}
}
//bfs:


struct Point{
	int x, y;
	Point(int a, int b):x(a), y(b) {}
};
void solve(vector<vector<char> > & board) {
	const int M = board.size();
	if (M <= 2) return;
	const int N = board[0].size();
	vector<Point> run;
	for (int i=0; i<M; ++i) // 1 border
		for (int j=0; j<N; ++j) 
			if ((i == 0 || i == M-1 || j == 0 || j == N-1) && board[i][j] == 'O') {
				board[i][j] = 'D';
				run.push_back(Point(i, j));
			}
			const int PATH[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
			while (!run.empty()) { // 2 out -> insider
				Point p = run.back();
				run.pop_back();
				for (int i=0; i<4; ++i) {
					int x = p.x+PATH[i][1];
					int y = p.y+PATH[i][0];
					if (x<0 || x>=M || y<0 || y>= N || board[x][y] != 'O')
						continue;
					board[x][y] = 'D';
					run.push_back(Point(x, y));
				}
			}
			for (int i=0; i<M; ++i) // 3 checking
				for (int j=0; j<N; ++j) {
					if (board[i][j] == 'X') continue;
					board[i][j] = (board[i][j] == 'O'?'X':'O');
				}
}
//second edition
class Solution {
	int n;
public:
	void solve(vector<vector<char>> &board) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		n = board.size();
		if(n <= 2)return;
		for(int i = 0;i < n;i++){
			if(board[0][i] == 'O')dfs(0,i,board);
			if(board[n-1][i] == 'O')dfs(n-1,i,board);
			if(board[i][0] == 'O')dfs(i,0,board);
			if(board[i][n-1] == 'O')dfs(i,n-1,board);
		}
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				if(board[i][j] == '.')board[i][j] = 'O';
				else if(board[i][j] == 'O')board[i][j] = 'X';
	}
	void dfs(int i,int j,vector<vector<char>> &board){
		board[i][j] = '.';
		if(i > 1 && board[i-1][j] == 'O')dfs(i-1,j,board);
		if(i < n-1 && board[i+1][j] == 'O')dfs(i+1,j,board);
		if(j > 1 && board[i][j-1] == 'O')dfs(i,j-1,board);
		if(j < n-1 && board[i][j+1] == 'O')dfs(i,j+1,board);
	}
};
