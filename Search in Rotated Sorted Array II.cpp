class Solution {
	int N;
public:
	bool search(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n == 0)return false;
		if(n == 1){
			if(A[0] == target)return true;
			return false;
		}
		if(n == 2){
			if(A[0] == target || A[1] == target)return true;
			return false;
		}
		N = n;
		int pivot = binearyPivot(A,0,n - 1);
		if(pivot != -1)
			return binearyTarget(A,0,pivot - 1,target) || binearyTarget(A,pivot,n - 1,target);
		return binearyTarget(A,0,n - 1,target);
	}
	bool binearyTarget(int A[],int start,int end,int target){
		int mid = (start + end)/2;
		if(target == A[mid])return true;
		if(start == end)return false;
		if(end - start == 1){
			if(target == A[end])return true;
			return false;
		}
		if(A[mid] < target)return binearyTarget(A,mid + 1,end,target);
		return binearyTarget(A,start,mid - 1,target);

	}
	int binearyPivot(int A[],int start,int end){
		int mid = (start + end)/2;
		if(mid > 0 && A[mid] < A[mid - 1] && (mid == N - 1 || A[mid] <= A[mid + 1]))return mid;
		if(start == end)return -1;
		if(end - start == 1){
			mid++;
			if(A[mid] < A[mid - 1] && (mid == N - 1 || A[mid] <= A[mid + 1]))return mid;
			return -1;
		}
		int temp = binearyPivot(A,start,mid - 1);
		if(temp != -1)return temp;
		return binearyPivot(A,mid + 1,end);
	}
};
//second edition:与一不同在于中点与左点相同时需要同时搜索左右两边
class Solution {
public:
	bool search(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		return biSearch(A,0,n - 1,target);
	}
	bool biSearch(int A[],int l,int r,int target){
		if(l > r)return false;
		int m = (l + r) / 2;
		if(target == A[m])return true;
		if(target == A[r])return true;
		if(r - l == 1 || r == l)return false;
		if(A[l] < A[r]){
			if(target > A[m])return biSearch(A,m,r,target);
			else return biSearch(A,l,m,target);
		}
		if(A[m] == A[l])
			return biSearch(A,m,r,target) || biSearch(A,l,m,target);
		if(A[m] < A[l]){
			if(target < A[m] || target > A[r])return biSearch(A,l,m,target);
			else return biSearch(A,m,r,target);
		}
		else{
			if(target < A[r] || target > A[m])return biSearch(A,m,r,target);
			else return biSearch(A,l,m,target);
		}
	}
};
//third edition
class Solution {
public:
	bool search(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n == 0)return false;
		if(n == 1)return A[0] == target;
		int l = 0,r = n - 1;
		while(l < r){
			int m = (l + r) / 2;
			if(A[m] == target)return true;
			if(r - l == 1){if(A[r] == target)return true;break;}
			if(A[l] == A[m] && A[m] == A[r]){
				for(;l <= r;l++)if(A[l] == target)return true;
				break;
			}
			else if(A[l] <= A[m] && A[m] <= A[r]){
				if(target > A[m])l = m;
				else r = m;
			}
			else if(A[m] <= A[r] && A[r] <= A[l]){
				if(target > A[m] && target <= A[r])l = m;
				else r = m;
			}
			else{
				if(target < A[m] && target >= A[l])r = m;
				else l = m;
			}
		}
		return false;
	}
};