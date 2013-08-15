//不用乘除取余号则只能从位操作考虑，要习惯二进制。
class Solution {
public:
	int divide(int dividend, int divisor) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		assert(divisor != 0);
		if(dividend == 0)return 0;
		if(divisor == 1)return dividend;
		long long x = dividend,y = divisor;
		bool negative = false;
		if(x < 0 && y < 0){x = -x;y = -y;}
		else if(x < 0){negative = true;x = -x;}
		else if(y < 0){negative = true;y = -y;}

		int cnt = 0,ans = 0;
		while((y << cnt) <= x)cnt++;
		for(int i = cnt - 1;i >= 0;i--){
			if((y << i) <= x){
				x -= y << i;
				ans += 1 << i;
			}
		}
		if(negative)return -ans;
		return ans;
	}
};
//另简化代码：


class Solution {
public:
	int divide(int dividend, int divisor) {
		long long a = abs((double)dividend);;
		long long b = abs((double)divisor);

		long long ret = 0;
		while (a >= b) {
			long long c = b;
			for (int i = 0; a >= c; ++i, c <<= 1) {
				a -= c;
				ret += 1 << i;
			}
		}

		return ((dividend^divisor)>>31) ? (-ret) : (ret);
	}
};

