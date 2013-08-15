class Solution {
public:
	int trap(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n <= 2)return 0;
		int i,j ,ti,sum = 0,maxHeight = A[n - 1],maxI = n - 1;
		int maxH[n];
		bool tall = false;
		maxH[n - 1] = n - 1;
		for(i = n - 2;i >= 0;i--){
			if(A[i] > maxHeight){
				maxHeight = A[i];
				maxI = i;
			}
			maxH[i] = maxI;
		}
		i = 0;
		while(A[i + 1] >= A[i])i++;
		for(;i < n - 1;i++){
			if(maxH[i] == i){
				tall = true;
				ti = i;
			}
			else{
				if(tall){
					sum += A[maxH[i]] * (maxH[i] - ti);
					for(j = ti + 1;j <= maxH[i];j++)sum -= A[j];
					i = maxH[i] - 1;
					tall = false;
				}
				else{
					for(j = i + 1;j < n;j++){
						sum -= A[j];
						if(A[j] >= A[i])break;
					}
					sum += A[j] - A[i];
					sum += A[i] * (j - i);
					i = j - 1;
				}
			}
		}
		return sum;
	}
};
/*��������ĳ��ֵA[i]��˵����trapped������waterȡ������i֮ǰ��ߵ�ֵleftMostHeight[i]����i�ұߵ���ߵ�ֵ
rightMostHeight[i]���������������������min(left,right) > A[i]����ô��i���λ������trapped��water����
min(left,right) �C A[i]����������뷨�ͺð��ˣ���һ������Ҽ�������leftMostHeight���ڶ�����ҵ������rightMostHeight��
�ڵڶ����ͬʱ�Ϳ��Լ����iλ�õĽ���ˣ����Ҳ�����Ҫ���ռ������rightMostHeight����
*/
class Solution {
public:
	int trap(int A[], int n) {
		//no way to contain any water
		if(n <= 2) return 0;

		//1. first run to calculate the heiest bar on the left of each bar
		int *lmh = new int[n];//for the most height on the left
		lmh[0] = 0;
		int maxh = A[0];
		for(int i = 1; i < n; ++i) {
			lmh[i] = maxh;
			if(maxh < A[i]) maxh = A[i];
		}
		int trapped = 0;

		//2. second run from right to left, 
		// caculate the highest bar on the right of each bar
		// and calculate the trapped water simutaniously
		maxh = A[n-1];
		for(int i = n - 2; i > 0; --i) {
			int left = lmh[i];
			int right = maxh;
			int container = min(left,right);
			if(container > A[i]) {
				trapped += container - A[i];
			}
			if(maxh < A[i]) maxh = A[i];
		}
		delete lmh;
		return trapped;
	}
};

//third edition
class Solution {
public:
	int trap(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n <= 2)return 0;
		vector<int> left(n,0);
		int maxHeight = A[0],maxIndex = 0;
		left[0] = 0;
		for(int i = 1;i < n;i++){
			if(A[i] >= maxHeight){maxHeight = A[i];maxIndex = i;}
			left[i] = maxIndex;
		}
		int sum = 0;
		maxHeight = A[n-1];
		for(int i = n - 2;i >= 0;i--){
			maxHeight = max(maxHeight,A[i]);
			if(left[i] != i)sum += min(maxHeight,A[left[i]]) - A[i];
		}
		return sum;
	}
};