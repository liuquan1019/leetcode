/*

*/
class Solution {
	vector<int> elem;
	vector<bool> visited;
	vector<vector<int> > ans;
	int n;
public:
	vector<vector<int> > permuteUnique(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ans.clear();
		n = num.size();
		if(n == 0)return ans;
		vector<int> v;
		if(n == 1){
			v.push_back(num[0]);
			ans.push_back(v);
			return ans;
		}
		elem = num;
		sort(elem.begin(),elem.end());
		visited = vector<bool>(n,false);
		perm(0,v);
		return ans;
	}
	void perm(int k,vector<int> &v){
		if(k == n)
			ans.push_back(v);
		for(int i = 0;i < n;i++){
			if(!visited[i]){
				if(i > 0 && elem[i - 1] == elem[i] && !visited[i - 1])continue;
				v.push_back(elem[i]);
				visited[i] = true;
				perm(k + 1,v);
				v.pop_back();
				visited[i] = false;
			}
		}
	}
};