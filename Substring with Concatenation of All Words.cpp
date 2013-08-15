//说任意顺序组成应想到hash，统计各个词预期和实际的出现次数，简单用数组，复杂用map
class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		map<string,int> expect,appear;
		vector<int> ans;
		int num = L.size();
		if(num == 0)return ans;
		int len = L[0].length();
		int i,j;
		for(i = 0;i < num;i++)expect[L[i]]++;
		for(i = 0; i < S.length() - num * len + 1;i++){
			appear.clear();
			for(j = 0;j < num;j++){
				string temp = S.substr(i + j * len,len);
				if(expect.find(temp) != expect.end())appear[temp]++;
				else break;
				if(appear[temp] > expect[temp])break;
			}
			if(j == num)ans.push_back(i);
		}
		return ans;
	}
};