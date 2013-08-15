class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int> > ans;
		int n = S.size();
		if(n == 0)return ans;
		int num = 1 << n;
		int i,j;
		for(i = 0;i < num;i++){
			vector<int> v;
			int temp = i;
			for(j = 0;j < n;j++){
				if(temp & 1)v.push_back(S[j]);
				temp >>= 1;
			}
			sort(v.begin(),v.end());
			ans.push_back(v);
		}
		return ans;
	}
};
//second edition
class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = S.size();
		vector<int> v;
		vector<vector<int> > ans;
		ans.push_back(v);
		if(n == 0)return ans;
		ans.clear();
		sort(S.begin(),S.end());
		for(int i = 0;i < n;i++){
			int temp = ans.size();
			v = vector<int>(1,S[i]);
			ans.push_back(v);
			for(int j = 0;j < temp;j++){
				v = ans[j];
				v.push_back(S[i]);
				ans.push_back(v);
			}
		}
		v.clear();
		ans.push_back(v);
		return ans;
	}
};