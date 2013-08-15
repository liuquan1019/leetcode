class Solution {
	int N;
public:
	int search(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n == 0)return -1;
		if(n == 1){
			if(A[0] == target)return 0;
			return -1;
		}
		if(n == 2){
			if(A[0] == target)return 0;
			if(A[1] == target)return 1;
			return -1;
		}
		N = n;
		int pivot = binearyPivot(A,0,n - 1);
		if(pivot != -1)
			return max(binearyTarget(A,0,pivot - 1,target),binearyTarget(A,pivot,n - 1,target));
		return binearyTarget(A,0,n - 1,target);
	}
	int binearyTarget(int A[],int start,int end,int target){
		int mid = (start + end)/2;
		if(target == A[mid])return mid;
		if(start == end)return -1;
		if(end - start == 1){
			if(target == A[end])return end;
			return -1;
		}
		if(A[mid] < target)return binearyTarget(A,mid + 1,end,target);
		return binearyTarget(A,start,mid - 1,target);

	}
	int binearyPivot(int A[],int start,int end){
		int mid = (start + end)/2;
		if(mid > 0 && A[mid] < A[mid - 1] && (mid == N - 1 || A[mid] < A[mid + 1]))return mid;
		if(start == end)return -1;
		if(end - start == 1){
			mid++;
			if(A[mid] < A[mid - 1] && (mid == N - 1 || A[mid] < A[mid + 1]))return mid;
			return -1;
		}
		int temp = binearyPivot(A,start,mid - 1);
		if(temp != -1)return temp;
		return binearyPivot(A,mid + 1,end);
	}
};

//另一做法，直接变相二分查找：
int search(int A[], int n, int target) {    
	int l = 0, r = n-1;   
	while(l<=r){   
		int m = (l+r)/2;   
		if(A[m] == target) return m;   
		if(A[m]>= A[l]){   
			if(A[l]<=target && target<= A[m])r=m-1;   
			else  l = m+1;       
		}   
		else{   
			if(A[m] >= target || target>= A[l])r = m-1;    
			else   l = m+1;   
		}   
	}   
	return -1;   
}
//second edition
class Solution {
public:
	int search(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int l = 0,r = n - 1,m;
		while(l <= r){
			m = (l + r) / 2;
			if(target == A[m])return m;
			if(target == A[r])return r;
			if(r - l == 1 || r == l)break;
			if(A[l] < A[r]){
				if(target > A[m])l = m;
				else r = m;
				continue;
			}
			if(A[m] < A[l]){
				if(target < A[m] || target > A[r])r = m;
				else l = m;
			}
			else{
				if(target < A[r] || target > A[m])l = m;
				else r = m;
			}
		}
		return -1;
	}
};
//third edition:三个bug:1,one、right等布尔型每次循环忘恢复初始值；2，边界[r][l]忘取等；3，先赋m再取值
class Solution {
public:
	int search(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n == 1)return (A[0] == target) - 1;
		int l = 0,r = n - 1,m = 0;
		bool one = false,right = false;
		while(l < r){
			if(A[l] < A[r])one = true;
			m = (l + r) / 2;
			if(A[m] < A[l])right = true;
			if(A[m] == target)return m;
			if(r - l == 1){if(A[r] == target)return r;break;}
			if((one && target > A[m]) ||
				(!one && right && target <= A[r] && target > A[m]) ||
				(!one && !right && (target > A[m] || target <= A[r])))l = m;
			else r = m;
			one = false;right = false;
		}
		return -1;
	}
};
//fourth edition
class Solution {
public:
	int search(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n == 0)return -1;
		if(n == 1)return (A[0] == target) - 1;
		int l = 0,r = n - 1;
		while(l < r){
			int m = (l + r) / 2;
			if(A[m] == target)return m;
			if(r - l == 1){if(A[r] == target)return r;break;}
			if(target > A[m] && (A[m] > A[l] || target <= A[r]))l = m;
			else if(A[m] > A[l] && target < A[l])l = m;
			else r = m;
		}
		return -1;
	}
};