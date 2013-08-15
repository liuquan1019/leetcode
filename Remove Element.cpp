class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n == 0)return 0;
		int i,j = n - 1;
		for(i = 0;i < n;i++){
			if(A[i] == elem){
				while(j > i && A[j] == elem){j--;n--;}
				if(j > i){
					A[i] = A[j];
					n--;
					j--;
				}
				else{n = i;break;}
			}
		}
		return n;
	}
};
//second edition
class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int index = 0;
		for(int i = 0;i < n;i++)
			if(A[i] != elem)A[index++] = A[i];
		return index;
	}
};