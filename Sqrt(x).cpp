/*
ò�Ƽ򵥣��и������壺���ֳ�ʼ�Ͻ��ȷ�������ܳ���[sqrt(INT_MAX)] + 1;����Խ��˻�Ϊ��ֵ
*/
class Solution {
public:
	int sqrt(int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(x == 0 || x == 1)return x;
		int l = 1,r = min(x/2,46340),m;
		while(l < r){
			m = (l + r) / 2;
			if(m * m <= x && (m + 1) * (m + 1) > x)return m;
			if(m *m < x)l = m + 1;
			else r = m - 1;
		}
		return l;
	}
};
//second edition:�м�˻���long long����
class Solution {
public:
	int sqrt(int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(x == 0 || x == 1)return x;
		if(x == 2 || x == 3)return 1;
		long long l = 1,r = x/2,m,tmp;
		while(l < r){
			m = (l + r)/2;
			tmp = m * m;
			if(tmp <= x && tmp + 2*m+1 > x)return m;
			else if(r - l == 1)return r;
			else if(tmp > x)r = m;
			else l = m;
		}
	}
};
//third edition:ţ�ٵ���
class Solution {
public:
	int sqrt(int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		assert(x >= 0);
		if(x <= 1)return x;
		double y1 = 1.0,y2 = -1.0;
		while(y1 - y2 >= 1 || y2 - y1 >= 1){
			y2 = (y1 + x / y1) / 2;
			double tmp = y1;y1 = y2;y2 = tmp;
		}
		return y1;
	}
};