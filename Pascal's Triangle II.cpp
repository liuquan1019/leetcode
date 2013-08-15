class Solution {
public:
	vector<int> getRow(int rowIndex) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> ans;
		ans.push_back(1);
		if(rowIndex == 0)return ans;
		for(int i = 1;i <= rowIndex;i++){
			vector<int> temp(ans);
			ans.clear();
			ans.push_back(1);
			for(int j = 1;j < i;j++)
				ans.push_back(temp[j - 1] + temp[j]);
			ans.push_back(1);
		}
		return ans;
	}
};