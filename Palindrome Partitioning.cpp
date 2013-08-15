class Solution {
	vector<vector<string>> ans;
public:
	vector<vector<string>> partition(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ans.clear();
		if(s.length() == 0)return ans;
		vector<string> v;
		dfs(s,v);
		return ans;
	}
	void dfs(string s,vector<string> &v){
		int n = s.length();
		if(n == 0){ans.push_back(v);return;}
		for(int i = 1;i <= n;i++){
			int j = 0,k = i - 1;
			while(j < k){
				if(s[j] == s[k]){j++;k--;}
				else break;
			}
			if(j >= k){
				v.push_back(s.substr(0,i));
				string s2 = s.substr(i);
				dfs(s2,v);
				v.pop_back();
			}
		}
	}
};