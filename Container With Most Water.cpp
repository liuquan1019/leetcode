/*
������һ��ָ�룬Ȼ�����area�����height[i] <= height[j]����ôi++����Ϊ������height[i]��ƿ����j������ֻ����������
����������area������һ��̰�ĵĲ��ԣ�ÿ��ȡ����Χ�����һ���ƽ���ϣ����ȡ�����ˮ��
*/
class Solution {
public:
	int maxArea(vector<int> &height) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(height.empty() || height.size() == 1)return 0;
		int m = INT_MIN,i,j,temp;
		for(i = 0,j = height.size() - 1;i < j;){
			temp = min(height[i],height[j]) * (j - i);
			m = max(m,temp);
			if(height[i] < height[j])i++;
			else j--;
		}
		return m;
	}
};
//third edition
class Solution {
public:
	int maxArea(vector<int> &height) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = height.size();
		int i = 0,j = n - 1,maxSum = 0,sum = 0;
		while(i < j){
			sum = min(height[i],height[j]) * (j - i);
			maxSum = max(maxSum,sum);
			if(height[i] <= height[j])i++;
			else j--;
		}
		return maxSum;
	}
};