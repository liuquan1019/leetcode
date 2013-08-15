//位操作实现常量空间，但是数据范围有限，大数据时越界导致出错
class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n <= 0)return 1;
		int pattern = 0,cnt = 1;
		for(int i = 0;i < n;i++)
			if(A[i] > 0){
				if((pattern >> (A[i] - 1)) & 1)continue;//取第i位别忘右移后和1与
				pattern += 1 << (A[i] - 1);
				cnt++;
			}
			int rule = (1 << cnt) - 1;
			pattern = pattern ^ rule;
			if(pattern == 0)return cnt;
			cnt = 1;
			while(pattern%2 != 1){pattern >>= 1;cnt++;}
			return cnt;
	}
};
/*
题目的最后一行，要求O(n)实际上暗示了用hash，但是又说要contant space，就没法再开新空间来建hash。
正好这个题目中处理的是1到n的数据，提供了一个将输入的数组同时用作hash表的可能性。

第一遍扫描排除所有非正的数，将它们设为一个无关紧要的正数(n+2)，因为n+2不可能是答案
第二遍扫描，将数组作为hash表来使用，用数的正负来表示一个数是否存在在A[]中。
当遇到A[i]，而A[i]属于区间[1,n]，就把A中位于此位置A[i] – 1的数置翻转为负数。
所以我们取一个A[i]的时候，要取它的abs，因为如果它是负数的话，通过步骤一之后，只可能是我们主动设置成负数的
第三遍扫描，如果遇到一个A[i]是正数，说明i+1这个数没有出现在A[]中，只需要返回即可。
上一步没返回，说明1到n都在，那就返回n+1

*/
class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		if(n <= 0)
			return 1;
		int intOutOfRange = n + 2;
		//first run, turn every negetive value into an impossible positive value
		//make every value in A is positive
		for(int i = 0 ; i < n ; ++ i) {
			if(A[i] <= 0)
				A[i] = intOutOfRange;
		}
		//second run, make A[] as a hash table, A[i] indicate the presence of i + 1
		//the way is that, if k in [1,n] is in A[], then turn A[k -1] to negetive
		for(int i = 0 ; i < n ; ++i) {
			int ai = A[i];
			int absi = abs(ai);
			if(absi <= n)
				A[absi-1] = -abs(A[absi-1]);
		}
		//third run, if A[i] is positive, from step 2, we know that i + 1 is missing.
		for(int i = 0 ; i < n ; ++i) {
			if(A[i] > 0)
				return i + 1;
		}
		//all int from 1 to n is present, then return n + 1
		return n+1;
	}
};
//法三：把对应的数放到对应的索引上，例如1放到A[1]上，这样只需要O(n)的遍历就能完成，然后用一个O(n)的遍历找第一个没有放到索引上
//的数返回。最后就是可能A[0] == n，这时就要有个特殊情况的处理。
class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		int i = 0;
		while(i < n){
			if (A[i] == i)i++;
			else{
				if (0 <= A[i] && A[i] < n && A[A[i]] != A[i]){
					int t = A[i];
					A[i] = A[A[i]];
					A[t] = t;
				}
				else i++;
			}
		}
		for(int i = 1; i < n; i++)
			if (A[i] != i)
				return i;
		return A[0] == n ? n + 1 : n;
	}
};
//法四：其实就是桶排序，只不过不许用额外空间。所以，每次当A[i]!= i的时候，将A[i]与A[A[i]]交换，直到无法交换位置。终止条件是 A[i]== A[A[i]]。
//然后i -> 0 到n走一遍就好了。
int firstMissingPositive(int A[], int n) {  
	// Start typing your C/C++ solution below  
	// DO NOT write int main() function  
	int i =0;  
	for(int i =0; i< n; i++){  
		while(A[i] != i+1){        
			if(A[i] <= 0 || A[i] >n || A[i] == A[A[i] -1]) break;  
			int temp = A[i];  
			A[i] = A[temp-1];  
			A[temp-1] = temp;          
		}  
	}  
	for(int i =0; i< n; i++)  
		if(A[i]!=i+1)return i+1;  
	return n+1;  
}
//third edition
class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		for(int i = 0;i < n;i++){
			while(A[i] > 0 && A[i] <= n && A[i] != i + 1 && A[i] !=  A[A[i] - 1]){
				int tmp = A[A[i] - 1];
				A[A[i] - 1] = A[i];
				A[i] = tmp;
			}
		}
		for(int i = 0;i < n;i++)
			if(A[i] != i + 1)return i + 1;
		return n + 1;
	}
};