/*
旋转图像，方法就是从外到内一圈一圈的转。
在处理每一圈的旋转时，拿最上面一行的第一个元素到倒数第二个元素，逐个找到其在右边，下边和左边一行（或列）中对应的元素，
交换这一组4个元素的值就可以了
*/
//下标极易出错！！
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
//法二：首先沿逆对角线翻转一次，然后按x轴中线翻转一次
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
		//转i圈，左上[i,i]，右下[n-1-i,n-1-i]，元素数n-1-2i
		for(int i = 0;i < n/2;i++)
			//j是offset
			for(int j = 0;j < n - 1 - 2 * i;j++){
				int temp = matrix[i][i+j];
				matrix[i][i+j] = matrix[n-1-i-j][i];
				matrix[n-1-i-j][i] = matrix[n-1-i][n-1-i-j];
				matrix[n-1-i][n-1-i-j] = matrix[i+j][n-1-i];
				matrix[i+j][n-1-i] = temp;
			}
	}
};