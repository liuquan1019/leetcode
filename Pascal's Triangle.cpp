class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int> > ans;
		vector<int> temp;
		if(numRows == 0)return ans;
		temp.push_back(1);
		ans.push_back(temp);
		if(numRows == 1)return ans;
		temp.push_back(1);
		ans.push_back(temp);
		for(int i = 2;i < numRows;i++){
			vector<int> temp2(i + 1,1);
			for(int j = 1;j < i;j++)
				temp2[j] = ans[i - 1][j - 1] + ans[i - 1][j];
			ans.push_back(temp2);
		}
		return ans;
	}
};