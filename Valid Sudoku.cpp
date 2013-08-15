#include<string.h>
class Solution {
    bool hori[9][10];
    bool vert[9][10];
    bool squa[3][3][10];
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        memset(hori,true,sizeof(hori));
        memset(vert,true,sizeof(vert));
        memset(squa,true,sizeof(squa));
        int cnt = 0;
        for(int i = 0;i < 9;i++)
            for(int j = 0;j < 9;j++)
                if(board[i][j] != '.'){
                    if(!hori[i][board[i][j] - '0'])return false;
                    else hori[i][board[i][j] - '0'] = false;
                    if(!vert[j][board[i][j] - '0'])return false;
                    else vert[j][board[i][j] - '0'] = false;
                    if(!squa[i/3][j/3][board[i][j] - '0'])return false;
                    else squa[i/3][j/3][board[i][j] - '0'] = false;
                }
                else cnt++;
        return true;
    }
};