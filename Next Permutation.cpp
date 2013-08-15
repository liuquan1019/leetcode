class Solution {
public:
	void nextPermutation(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int s = num.size();
		if(s <= 1)return;
		if(s == 2){reverse(num.begin(),num.end());return;}
		int i,j;
		for(i = s - 1;i >= 0;i--)if(i > 0 && num[i] > num[i - 1])break;
		if(i == s - 1){int temp = num[i];num[i] = num[i - 1];num[i - 1] = temp;}
		else if(i == -1)reverse(num.begin(),num.end());
		else{
			for(j = s - 1;j >=i;j--)if(num[j] > num[i - 1])break;
			int temp = num[j];num[j] = num[i - 1];num[i - 1] = temp;
			sort(num.begin() + i,num.end());
		}
	}
};
//second edition
class Solution {
public:
	void nextPermutation(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = num.size(),i,j;
		if(n <= 1)return;
		for(i = n - 1;i > 0;i--)if(num[i - 1] < num[i])break;
		if(i != 0){
			for(j = n - 1;j > i - 1;j--)if(num[j] > num[i - 1])break;
			int temp = num[i - 1];
			num[i - 1] = num[j];
			num[j] = temp;
		}
		reverse(num.begin() + i,num.end());
	}
};
