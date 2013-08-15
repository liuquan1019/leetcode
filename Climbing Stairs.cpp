class Solution {
public:
	int climbStairs(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n <= 0)return 0;
		int f[1000];
		f[1] = 1;f[2] = 2;
		for(int i = 3;i <= n;i++)f[i] = f[i - 1] + f[i - 2];
		return f[n];
	}
};
//second edition
class Solution {
public:
	int climbStairs(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n == 1 || n == 2)return n;
		int a = 1,b = 2,c;
		for(int i = 3;i <= n;i++){c = b;b += a;a = c;}
		return b;
	}
};