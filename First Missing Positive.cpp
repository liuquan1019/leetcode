//λ����ʵ�ֳ����ռ䣬�������ݷ�Χ���ޣ�������ʱԽ�絼�³���
class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n <= 0)return 1;
		int pattern = 0,cnt = 1;
		for(int i = 0;i < n;i++)
			if(A[i] > 0){
				if((pattern >> (A[i] - 1)) & 1)continue;//ȡ��iλ�������ƺ��1��
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
��Ŀ�����һ�У�Ҫ��O(n)ʵ���ϰ�ʾ����hash��������˵Ҫcontant space����û���ٿ��¿ռ�����hash��
���������Ŀ�д������1��n�����ݣ��ṩ��һ�������������ͬʱ����hash��Ŀ����ԡ�

��һ��ɨ���ų����з�����������������Ϊһ���޹ؽ�Ҫ������(n+2)����Ϊn+2�������Ǵ�
�ڶ���ɨ�裬��������Ϊhash����ʹ�ã���������������ʾһ�����Ƿ������A[]�С�
������A[i]����A[i]��������[1,n]���Ͱ�A��λ�ڴ�λ��A[i] �C 1�����÷�תΪ������
��������ȡһ��A[i]��ʱ��Ҫȡ����abs����Ϊ������Ǹ����Ļ���ͨ������һ֮��ֻ�����������������óɸ�����
������ɨ�裬�������һ��A[i]��������˵��i+1�����û�г�����A[]�У�ֻ��Ҫ���ؼ��ɡ�
��һ��û���أ�˵��1��n���ڣ��Ǿͷ���n+1

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
//�������Ѷ�Ӧ�����ŵ���Ӧ�������ϣ�����1�ŵ�A[1]�ϣ�����ֻ��ҪO(n)�ı���������ɣ�Ȼ����һ��O(n)�ı����ҵ�һ��û�зŵ�������
//�������ء������ǿ���A[0] == n����ʱ��Ҫ�и���������Ĵ���
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
//���ģ���ʵ����Ͱ����ֻ���������ö���ռ䡣���ԣ�ÿ�ε�A[i]!= i��ʱ�򣬽�A[i]��A[A[i]]������ֱ���޷�����λ�á���ֹ������ A[i]== A[A[i]]��
//Ȼ��i -> 0 ��n��һ��ͺ��ˡ�
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