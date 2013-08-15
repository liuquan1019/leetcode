/*
Here are some good questions to ask before coding. Bonus points for you if you have already thought through 
this!If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the 
reverse of 1000000003 overflows. How should you handle such cases?
Throw an exception? Good, but what if throwing an exception is not an option? You would then have to 
re-design the function (ie, add an extra parameter).
*/
class Solution {
public:
	int reverse(int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(x < 10 && x > -10)return x;
		bool negative = false;
		long long y = x,ans = 0;
		if(x < 0){y = -x;negative = true;}
		while(y % 10 == 0)y /= 10;
		while(y > 0){
			int i = y % 10;
			y /= 10;
			ans = ans * 10 + i;
		}
		if(negative){
			long long temp = INT_MAX;
			temp++;
			if(ans > temp)ans = temp;
			return -ans;
		}
		else{
			if(ans > INT_MAX)ans = INT_MAX;
			return ans;
		}
	}
};