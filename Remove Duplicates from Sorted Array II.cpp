class Solution {
public:
	int removeDuplicates(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n == 0 || n == 1 || n == 2)return n;
		int i,j,k;
		for(i = 0;i < n;i++){
			if(i < n - 1 && A[i] == A[i + 1]){
				i++;
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
		if(n == 0 || n == 1)return n;
		int cnt = 2;
		for(int i = 2;i < n;i++)
			if(A[i] != A[i - 1] || A[i] != A[cnt - 2])A[cnt++] = A[i];
		return cnt;
	}
};