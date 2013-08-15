class Solution {
public:
	string multiply(string num1, string num2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len1 = num1.length(),len2 = num2.length();
		if(len1 == 0 || len2 == 0)return "";
		if(num1 == "0" || num2 == "0")return "0";
		vector<int> a(400,0);
		char s[400];
		int i,j;
		for(i = 0;i < 400;i++)s[i] = '\0';
		reverse(num1.begin(),num1.end());
		reverse(num2.begin(),num2.end());
		for(i = 0;i < len1;i++)
			for(j = 0;j < len2;j++)
				a[i + j] += (num1[i] - '0') * (num2[j] - '0');
		for(i = 0;i < len1 + len2;i++){
			if(a[i] > 9){
				a[i + 1] += a[i] / 10;
				a[i] = a[i] % 10;
			}
			s[i] = a[i] + '0';
		}
		for(i = len1 + len2;i >= 0;i--){
			if(s[i] != '\0' && s[i] != '0')break;
			else s[i] = '\0';
		}
		if(i == -1)return "0";
		string temp = s;
		reverse(temp.begin(),temp.end());
		return temp;
	}
};
//second edition
class Solution {
public:
	string multiply(string num1, string num2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n1 = num1.length(),n2 = num2.length(),i;
		vector<int> ans(n1 + n2,0);
		for(i = n1 - 1;i >= 0;i--)
			for(int j = n2 - 1;j >= 0;j--)
				ans[n1+n2-2-i-j] += (num1[i] - '0') * (num2[j] - '0');
		for(i = 0;i < n1 + n2;i++)
			if(ans[i] > 9){
				ans[i + 1] += ans[i] / 10;
				ans[i] = ans[i] % 10;
			}
			for(i = n1 + n2 - 1;i >= 0;i--)if(ans[i] != 0)break;
			if(i == -1)return "0";
			string s = "";
			for(;i >= 0;i--)s.push_back(ans[i] + '0');
			return s;
	}
};
//third edition
class Solution {
public:
	string multiply(string num1, string num2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(num1 == "0" || num2 == "0")return "0";
		int n1 = num1.length(),n2 = num2.length();
		vector<int> product(n1 + n2,0);
		for(int i = n1 - 1;i >= 0;i--)
			for(int j = n2 - 1;j >= 0;j--)
				product[n1 - 1 - i + n2 - 1 -j] += (num1[i] - '0') * (num2[j] - '0');
		int carry = 0,i;
		for(i = 0;i < n1 + n2;i++){
			product[i] += carry;
			if(product[i] > 9){
				carry = product[i] / 10;
				product[i] = product[i] % 10;
			}
			else carry = 0;
		}
		string ans = "";
		for(i = n1 + n2 - 1;i > 0;i--)if(product[i] != 0)break;
		for(;i >= 0;i--)ans.push_back(product[i] + '0');
		return ans;
	}
};