class Solution {
public:
	double pow(double x, int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n == 0 || x == 1)return 1;
		if(x == 0)return 0;
		if(x == -1)return n % 2 ? -1:1;
		if(n == INT_MIN) return 1 / pow(x,INT_MAX);//别忘了值域的边界比较特殊
		if(n < 0)return 1 / pow(x,-n);
		if(n == 1)return x;
		if(n == 2)return x * x;
		double temp = pow(x,n/2);
		if(n % 2)return temp * temp *x;
		return temp * temp;
	}
};
//另简化：
double pow(double x, int n) {
	if (n == 0) return 1.0;
	// Compute x^{n/2} and store the result into a temporary
	// variable to avoid unnecessary computing
	double half = pow(x, n / 2);
	if (n % 2 == 0)
		return half * half;
	else if (n > 0)
		return half * half * x;
	else
		return half * half / x;
}
//法三：Consider the binary representation of n. For example, if it is "10001011", 
//then x^n = x^(1+2+8+128) = x^1 * x^2 * x^8 * x^128.
class Solution {
public:
	double pow(double x, int n) {
		unsigned m = abs((double)n);
		double ret = 1;
		for ( ; m; x *= x, m >>= 1) {
			if (m & 1) {
				ret *= x;
			}
		}
		return (n < 0) ? (1.0 / ret) : (ret);
	}
};