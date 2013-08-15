/*
�����ռ�Ļ�����һ���Կ����ǲ��ǹ̶������ļ��������ܸ㶨��������Կ����ǲ������Ȿ���Ѿ��ṩ���㹻�Ŀռ䡣
��������ں��ߣ��������þ���ĵ�һ�к͵�һ������Ϊ�����ռ�ʹ�á����ÿ����µĴ洢�ռ䡣�������ǣ�
1.��ȷ����һ�к͵�һ���Ƿ���Ҫ����
2.ɨ��ʣ�µľ���Ԫ�أ����������0���ͽ���Ӧ�ĵ�һ�к͵�һ���ϵ�Ԫ�ظ�ֵΪ0
3.���ݵ�һ�к͵�һ�е���Ϣ���Ѿ����Խ�ʣ�µľ���Ԫ�ظ�ֵΪ��������ֵ��
4.����1��ȷ����״̬�������һ�к͵�һ�С�
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
//second edition:ע����ԭ����洢�����ܴ��ڵĳ�ͻ����һ�С���һ�о�Ϊ��Ԫ��
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