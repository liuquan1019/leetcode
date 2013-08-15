class Solution {
public:
	string addBinary(string a, string b) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int al = a.length(),bl = b.length();
		if(al == 0)return b;
		if(bl == 0)return a;
		if(al < bl){
			string temp = b;
			b = a;
			a = temp;
			al = bl;
			bl = b.length();
		}
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		int i,add = 0,sum = 0;
		for(i = 0;i < bl;i++){
			sum = (a[i] == '1') + (b[i] == '1') + add;
			if(sum >= 2){add = 1;a[i] = '0' + sum - 2;}
			else{add = 0;a[i] = '0' + sum;}
		}
		if(add){
			for(;i < al;i++){
				if(a[i] == '0'){a[i] = '1';add = 0;break;}
				else {a[i] = '0';}
			}
		}
		reverse(a.begin(),a.end());
		if(add == 1)return "1" + a;
		return a;
	}
};
//second edition
class Solution {
public:
	string addBinary(string a, string b) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n1 = a.length(),n2 = b.length();
		if(n1 == 0)return b;
		if(n2 == 0)return a;
		if(n1 < n2){
			string s = b;b = a;a = s;
			int n = n2;n2 = n1;n1 = n;
		}
		bool overflow = false;
		for(int i = 0;i < n1;i++){
			if(i < n2)a[n1-1-i] += b[n2-1-i] - '0';
			if(a[n1-1-i] > 1 + '0'){
				a[n1-1-i] -= 2;
				if(n1 - i >= 2)a[n1-2-i] += 1;
				else overflow = true;
			}
		}
		if(overflow)return "1" + a;
		return a;
	}
};