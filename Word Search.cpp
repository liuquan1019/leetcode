class Solution {
	int m,n,len;
	vector<vector<char> > b;
	vector<vector<bool> >visited;
public:
	bool exist(vector<vector<char> > &board, string word) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		len = word.length();
		if(len == 0)return true;
		if(board.empty())return false;
		m = board.size();
		n = board[0].size();
		b = board;
		visited = vector<vector<bool> >(m,vector<bool>(n,false));
		for(int i = 0;i < m;i++)
			for(int j = 0;j < n;j++){
				if(b[i][j] != word[0])continue;
				visited[i][j] = true;
				if(find(i,j,word.substr(1)))return true;
				visited[i][j] = false;
			} 
			return false;
	}
	bool find(int i,int j,string word){
		if(word.length() == 0)return true;
		if(i > 0 &&b[i - 1][j] == word[0] && !visited[i - 1][j]){
			if(word.length() == 1)return true;
			visited[i - 1][j] = true;
			if(find(i - 1,j,word.substr(1)))return true;
			visited[i - 1][j] = false;
		}
		if(i < m - 1 &&b[i + 1][j] == word[0] && !visited[i + 1][j]){
			if(word.length() == 1)return true;
			visited[i + 1][j] = true;
			if(find(i + 1,j,word.substr(1)))return true;
			visited[i + 1][j] = false;
		}
		if(j > 0 &&b[i][j - 1] == word[0] && !visited[i][j - 1]){
			if(word.length() == 1)return true;
			visited[i][j - 1] = true;
			if(find(i,j - 1,word.substr(1)))return true;
			visited[i][j - 1] = false;
		}
		if(j < n - 1 &&b[i][j + 1] == word[0] && !visited[i][j + 1]){
			if(word.length() == 1)return true;
			visited[i][j + 1] = true;
			if(find(i,j + 1,word.substr(1)))return true;
			visited[i][j + 1] = false;
		}
		return false;
	}
};
//second edition注意下面的问题
class Solution {
vector<vector<bool> > visited;
vector<vector<char> > b;
int m,n;
public:
	bool exist(vector<vector<char> > &board, string word) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(word.length() == 0)return true;
		b = board;
		m = board.size();
		n = board[0].size();
		visited = vector<vector<bool> >(m,vector<bool>(n,false));
		const char *p = word.c_str();
		for(int i = 0;i < m;i++)
			for(int j = 0;j < n;j++)
				if(b[i][j] == *p && dfs(p+1,i,j))return true;
		return false;
	}
	bool dfs(const char * word,int i,int j){
		if(*word == '\0')return true;
		visited[i][j] = true;
		if(i >= 1 && b[i-1][j] == *word && !visited[i-1][j] && dfs(word+1,i-1,j))return true;
		if(i < m-1  && b[i+1][j] == *word && !visited[i+1][j] && dfs(word+1,i+1,j))return true;
		if(j >= 1 && b[i][j-1] == *word && !visited[i][j-1] && dfs(word+1,i,j-1))return true;
		if(j < n-1 && b[i][j+1] == *word && !visited[i][j+1] && dfs(word+1,i,j+1))return true;
		visited[i][j] = false;//很重要！！为减少代码行数将赋值放在递归函数里，则复原也应在函数结束前！
		return false;
	}
};