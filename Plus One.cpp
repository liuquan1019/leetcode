class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(digits.empty())return digits;
		int n = digits.size();
		int i = n - 1;
		while(i >= 0){
			if(digits[i] < 9){
				digits[i]++;
				return digits;
			}
			else{
				digits[i] = 0;
				i--;
			}
		}
		vector<int> temp;
		temp.push_back(1);
		for(i = 0;i < n;i++)temp.push_back(digits[i]);
		return temp;
	}
};
//second edition
class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int i;
		for(i = digits.size() - 1;i >= 0;i--){
			if(digits[i] < 9){digits[i]++;break;}
			digits[i] = 0;
		}
		if(i == -1)digits.insert(digits.begin(),1);
		return digits;
	}
};