class Solution {
public:
	string convert(string s, int nRows) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    
		if(nRows <= 1 || nRows >= s.length())return s;
		vector<string> v(nRows,"");
		int i,j = 0;
		bool flag = true;
		for(i = 0; i < s.length();i++){
			v[j].append(1,s[i]);
			if(flag)j++;
			else j--;
			if(j == nRows){flag = false;j -= 2;}
			else if(j < 0){flag = true;j += 2;}
		}
		string ans = "";
		for(i = 0;i < nRows;i++)ans += v[i];
		return ans;
	}
};