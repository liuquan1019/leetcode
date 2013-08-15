class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n == 0)return;
		vector<int> v;
		int i,j;
		for(i = 0,j = 0;i < m && j < n;){
			if(A[i] <= B[j]){v.push_back(A[i]);i++;}
			else{v.push_back(B[j]);j++;}
		}
		for(;i < m;i++)v.push_back(A[i]);
		for(;j < n;j++)v.push_back(B[j]);
		int len = v.size();
		for(i = 0;i < len;i++)A[i] = v[i];
	}
};
//second edition
class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n == 0)return;
		int i = m - 1,j = n - 1,k = m + n - 1;
		while(i >= 0 && j >= 0){
			if(A[i] > B[j]){A[k--] = A[i];i--;}
			else{A[k--] = B[j];j--;}
		}
		if(j == - 1)return;
		while(j >= 0){A[k--] = B[j];j--;}
	}
};