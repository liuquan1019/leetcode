//要递归二分寻找中位数，就需要转变为寻找第k个元素
//Kth element in 2 sorted array”， 如下图，两个中位数 A[m/2] 和 B[n/2]， 可以将数组划分为四个部分。
//	而丢弃哪一个部分取决于两个条件：1， (m/2 + n/2)?k；2，A[m/2] ? B[n/2];
class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if((m+n) % 2 == 0)return (getKth(A,m,B,n,(m + n)/2) + getKth(A,m,B,n,(m + n)/2 + 1))/2.0;
		else return getKth(A,m,B,n,(m + n)/2 + 1);
	}
	int getKth(int A[],int m,int B[],int n,int k){
		if(m <= 0)return B[k - 1];
		if(n <= 0)return A[k - 1];
		if(k <= 1)return min(A[0],B[0]);
		if(A[m/2] > B[n/2]){
			if(m/2 + n/2 + 1 >= k)return getKth(A,m/2,B,n,k);
			else return getKth(A,m,B + n/2 + 1,n - (n/2 + 1),k - (n/2 + 1));//注意不能合并为n/2 - 1因为有去小数过程，否则WA
		}
		else{
			if(m/2 + n/2 + 1 >= k)return getKth(A,m,B,n/2,k);
			else return getKth(A + m/2 + 1,m - (m/2 + 1),B,n,k - (m/2 + 1));
		}
	}
};
//second edition
class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if((m + n) & 1)return findKth(A,m,B,n,(m+n+1)/2 );
		double a = findKth(A,m,B,n,(m+n)/2);
		double b = findKth(A,m,B,n,(m+n)/2 + 1);
		return (a+b)/2;
	}
	double findKth(int A[],int m,int B[],int n,int k){
		if(m == 0)return B[k-1];
		if(n == 0)return A[k-1];
		if(m/2 + n/2 + 2 == k && A[m/2] == B[n/2])return A[m/2];
		if(m/2 + n/2 + 2 <= k){
			if(A[m/2] <= B[n/2])return findKth(A+m/2+1,(m+1)/2-1,B,n,k-m/2-1);
			else return findKth(A,m,B+n/2+1,(n+1)/2-1,k-n/2-1);
		}
		else{
			if(A[m/2] <= B[n/2])return findKth(A,m,B,n/2,k);
			else return findKth(A,m/2,B,n,k);
		}
	}
};
//third edition
class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if((m + n) & 1)return findKth(A,m,B,n,(m + n) / 2 + 1);
		else return (findKth(A,m,B,n,(m + n) / 2) + findKth(A,m,B,n,(m + n) / 2 + 1)) / 2;
	}
	double findKth(int A[],int m,int B[],int n,int k){
		if(n == 0)return A[k - 1];
		if(m == 0)return B[k - 1];
		if(k == 1)return min(A[0],B[0]);
		if(A[m / 2] == B[n / 2] && (k == m / 2 + n / 2 + 1 || k == m / 2 + n / 2 + 2))return A[m / 2];
		if(A[m / 2] >= B[n / 2]){
			if(k > m / 2 + n / 2 + 1)return findKth(A,m,B + n / 2 + 1,(n - 1) / 2,k - n / 2 - 1);
			else return findKth(A,m / 2,B,n,k);
		}
		else{
			if(k > m / 2 + n / 2 + 1)return findKth(A + m / 2 + 1,(m - 1) / 2,B,n,k - m / 2 - 1);
			else return findKth(A,m,B,n / 2,k);
		}
	}
};