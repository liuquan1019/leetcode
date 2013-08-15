class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len = strs.size();
		if(len == 0)return "";
		if(len == 1)return strs[0];
		int i,j,Min = INT_MAX,min_i;
		for(i = 0;i < len;i++){
			if(strs[i].length() == 0)return "";
			if(strs[i].length() < Min){Min = strs[i].length();min_i = i;}
		}
		i = 0;
		while(i < Min){
			for(j = 0;j < len;j++)
				if(strs[min_i][i] != strs[j][i])break;
			if(j != len)break;
			i++;
		}
		if(i == 0)return "";
		return strs[min_i].substr(0,i);
	}
};