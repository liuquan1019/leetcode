/*
��תͼ�񣬷������Ǵ��⵽��һȦһȦ��ת��
�ڴ���ÿһȦ����תʱ����������һ�еĵ�һ��Ԫ�ص������ڶ���Ԫ�أ�����ҵ������ұߣ��±ߺ����һ�У����У��ж�Ӧ��Ԫ�أ�
������һ��4��Ԫ�ص�ֵ�Ϳ�����
*/
//�±꼫�׳�����
class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = matrix.size();
		if(n == 0 || n == 1)return;
		for(int i = n;i > 1;i = i - 2)
			for(int j = 0;j < i - 1;j++){
				int temp = matrix[(n - i)/2][(n - i)/2 + j];
				matrix[(n - i)/2][(n - i)/2 + j] = matrix[(n+i)/2 - j - 1][(n - i)/2];
				matrix[(n+i)/2 - j - 1][(n - i)/2] = matrix[(n + i)/2 - 1][(n+i)/2 - j - 1];
				matrix[(n + i)/2 - 1][(n+i)/2 - j - 1] = matrix[(n - i)/2 + j][(n + i)/2 - 1];
				matrix[(n - i)/2 + j][(n + i)/2 - 1] = temp;  
			}
	}
};
//��������������Խ��߷�תһ�Σ�Ȼ��x�����߷�תһ��
void rotate(vector<vector<int> > &matrix) {  
	int len = matrix[0].size();  
	for(int i =0; i<len-1; i++){  
		for(int j=0;j<len-i;j++){  
			swap(matrix[i][j], matrix[len-1-j][len-1-i]);  
		}  
	}  
	for(int i =0; i<len/2; i++) 
		for(int j=0;j<len;j++){  
			swap(matrix[i][j], matrix[len-i-1][j]);  
		}  
}
void swap(int& a1, int&a2){  
	int temp = a1;  
	a1=a2;  
	a2=temp;  
}  
//second edition
class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = matrix.size();
		if(n <= 1)return;
		//תiȦ������[i,i]������[n-1-i,n-1-i]��Ԫ����n-1-2i
		for(int i = 0;i < n/2;i++)
			//j��offset
			for(int j = 0;j < n - 1 - 2 * i;j++){
				int temp = matrix[i][i+j];
				matrix[i][i+j] = matrix[n-1-i-j][i];
				matrix[n-1-i-j][i] = matrix[n-1-i][n-1-i-j];
				matrix[n-1-i][n-1-i-j] = matrix[i+j][n-1-i];
				matrix[i+j][n-1-i] = temp;
			}
	}
};