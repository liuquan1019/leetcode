//Gray Code有多种排列方式，其中一种的规律很明显，所以找不到规律时换着试试
class Solution {
public:
	vector<int> grayCode(int n) {  
    vector<int> ans;      
      ans.push_back(0);  
      for(int i=0; i< n; i++){  
        int highestBit = 1 << i;  
        int len = result.size();  
        for(int i = len-1; i>=0; i--)  
			result.push_back(highestBit + result[i]);  
	  }  
    return result;  
    }
};
//second edition
class Solution {
public:
	vector<int> grayCode(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> ans;
		ans.push_back(0);
		if(n == 0)return ans;
		ans.push_back(1);
		for(int i = 2;i <= n;i++){
			int m = ans.size();
			for(int j = m - 1;j >= 0;j--)
				ans.push_back(ans[j] + (1 << (i-1)));
		}
		return ans;
	}
};