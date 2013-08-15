class Solution {
public:
	int removeDuplicates(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n == 0 || n == 1)return n;
		int i,j,k;
		for(i = 0;i < n;i++){
			j = i + 1;
			while(j < n && A[i] == A[j])j++;
			if(j == n){
				n = i + 1;
				break;
			}
			else{
				for(k = j;k < n;k++)A[i + 1 + k - j] = A[k];
				n -= j - i - 1;
			}
		}
		return n;
	}
};
//second edition
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n == 0)return 0;
		int cnt = 1;
		for(int i = 1;i < n;i++)
			if(A[i] != A[i - 1])A[cnt++] = A[i];
		return cnt;
	}
};