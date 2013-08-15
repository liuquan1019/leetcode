class Solution {
public:
	int atoi(const char *str) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		while(*str != '\0' && (*str == ' ' || *str == '0'))str++;
		if(*str == '\0')return 0;
		bool negative = false;
		if(*str == '+')str++;
		else if(*str == '-'){str++;negative = true;}
		//while(*str != '\0' && (*str == ' ' || *str == '0'))str++;
		long long ans = 0;
		while(*str >= '0' && *str <= '9'){
			ans = 10 * ans + (*str - '0');
			str++;
		}
		if(negative)ans = -ans;
		if(ans >= INT_MAX)return INT_MAX;
		if(ans <= INT_MIN)return INT_MIN;
		return ans;
	}
};