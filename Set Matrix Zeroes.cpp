/*
常数空间的话，第一可以考虑是不是固定数量的几个变量能搞定；否则可以考虑是不是问题本身已经提供了足够的空间。
这道题属于后者，就是利用矩阵的第一行和第一列来作为辅助空间使用。不用开辟新的存储空间。方法就是：
1.先确定第一行和第一列是否需要清零
2.扫描剩下的矩阵元素，如果遇到了0，就将对应的第一行和第一列上的元素赋值为0
3.根据第一行和第一列的信息，已经可以讲剩下的矩阵元素赋值为结果所需的值了
4.根据1中确定的状态，处理第一行和第一列。
*/
class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(matrix.empty())return;
		int m = matrix.size();
		int n = matrix[0].size();
		int i,j;
		vector<int> row,column;
		for(i = 0;i < m;i++)
			for(j = 0;j < n;j++){
				if(matrix[i][j] == 0){
					row.push_back(i);
					column.push_back(j);
				}
			}
			j = row.size();
			for(i = 0;i < j;i++)
				matrix[row[i]] = vector<int>(n,0);
			n = column.size();
			for(i = 0;i < n;i++)
				for(j = 0;j < m;j++)
					matrix[j][column[i]] = 0;
	}
};
//second edition:注意用原数组存储，可能存在的冲突：第一行、第一列均为首元素
class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int m = matrix.size();
		if(m == 0)return;
		int n = matrix[0].size();
		bool firstColumn = false, firstRow = false;
		for(int i = 0;i < m;i++)
			for(int j = 0;j < n;j++)
				if(matrix[i][j] == 0){
					if(i == 0)firstRow = true;
					if(j == 0)firstColumn = true;
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
				for(int i = 1;i < m;i++)
					for(int j = 1;j < n;j++)
						if(matrix[i][0] == 0 || matrix[0][j] == 0)matrix[i][j] = 0;
				if(firstColumn)
					for(int i = 0;i < m;i++)matrix[i][0] = 0;
				if(firstRow)
					for(int i = 0;i < n;i++)matrix[0][i] = 0;
	}
};