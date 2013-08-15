class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(target < A[0])return 0;
		if(target > A[n - 1])return n;
		return binearySearch(A,0,n - 1,target);
	}
	int binearySearch(int A[],int l,int r,int target){
		int m = (l + r) / 2;
		if(A[m] == target)return m;
		if(A[m] < target && A[m + 1] > target)return m + 1;
		if(A[m] < target)return binearySearch(A,m + 1,r,target);
		return binearySearch(A,l,m,target);
	}
};
//second edition
class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(target < A[0])return 0;
		if(target > A[n - 1])return n;
		int l = 0,r = n - 1,m;
		while(l < r){
			m = (l + r) / 2;
			if(target == A[m] || (A[m - 1] < target && target < A[m]))return m;
			if(target == A[r] || (A[r - 1] < target && target < A[r]))return r;
			if(target > A[m])l = m;
			else r = m;
		}
	}
};