class Solution {
public:
	void sortColors(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int i = 0,j = n - 1,temp;
		while(i < j){
			while(A[i] == 0 && i < j)i++;
			while((A[j] == 1 || A[j] == 2) && i < j)j--;
			if(i < j){
				temp = A[j];A[j] = A[i];A[i] = temp;
				i++;j--;
			}
		}
		i = 0;j = n - 1;
		while(i < j){
			while((A[i] == 0 || A[i] == 1) && i < j)i++;
			while(A[j] == 2 && i < j)j--;
			if(i < j){
				temp = A[j];A[j] = A[i];A[i] = temp;
				i++;j--;
			}
		}
	}
};
//����ĿҪ��one-pass,����Ҫ����ָ��ֱ�ָ��0,1,2
class Solution {
public:
	void sortColors(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int i = 0; // 0 pointer
		int j = n - 1; // 1 pointer
		int k = n - 1; // 2 pointer

		while (i <= j)
		{
			if (A[i] == 2)
			{
				int t = A[k];
				A[k] = A[i];
				A[i] = t;
				k--;
				if (k < j)
					j = k;
			}
			else if (A[i] == 1)
			{
				int t = A[j];
				A[j] = A[i];
				A[i] = t;
				j--;
			}
			else
				i++;
		}
	}
};
//third edition
class Solution {
public:
	void sortColors(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int i = 0,j = n - 1,k = n - 1;
		while(i <= j){
			while(i <= j && A[i] == 0)i++;
			if(i > j)break;
			if(A[i] == 2){
				while(k >= i && A[k] == 2)k--;
				if(i > k)break;
				A[i] = A[k];
				A[k] = 2;
				k--;
				if(k < j)j = k;
			}
			else{
				while(j >= i && A[j] == 1)j--;
				if(i > j)break;
				A[i] = A[j];
				A[j] = 1;
				j--;
			}
		}
	}
};
/*˼·��
��i��¼0Ӧ�÷ŵ�λ�ã�j��¼2Ӧ�÷ŵ�λ�á�
cur��0��jɨ�裬
����0������iλ�ã�i���ƣ�
����2������jλ�ã�jǰ�ƣ�
����1��cur���ơ�
ɨ��һ��õ��ź�������顣
*/


void sortColors(int A[], int n) {
	int r=0,w=0,b=n-1;
	for(w=0;w<=b;) {
		if(A[w]==0)
			swap(A[r++],A[w++]); // why also w++? because r's next position can only be white 
		else if(A[w]==2)
			swap(A[b--],A[w]);
		else
			w++;
	}
}

