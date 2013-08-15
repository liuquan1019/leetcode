class Solution {
public:
	bool isPalindrome(int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(x < 0)return false;
		if(x < 10)return true;
		int b,e,i = 1000000000;//���i��10�����ǵ���x������ܳ���int��Χ�����³�ʱ
		while(x < i)i /= 10;
		while(x >= 10){
			e = x % 10;
			b = x / i;
			if(b != e)return false;
			x = (x - b * i - e) / 10; 
			i /= 100;
		}
		return true;
	}
};