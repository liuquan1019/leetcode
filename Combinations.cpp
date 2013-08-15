//用组合的数学公式递归降阶
class Solution {
	vector<vector<int> > ans;
public:
	vector<vector<int> > combine(int n, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ans.clear();
		return partialCombine(n,k); 
	}
	vector<vector<int> > partialCombine(int n,int k){
		vector<vector<int> > temp;
		if(k == 0 || n <= 0)return temp; 
		int i;
		if(k == n){
			vector<int> v;
			for(i = 1;i <= n;i++)v.push_back(i);
			temp.push_back(v);
			return temp;
		}
		if(k == 1){
			for(i = 1;i <= n;i++){
				vector<int> v;
				v.push_back(i);
				temp.push_back(v);
			}
			return temp;
		}
		vector<vector<int> > temp1 = partialCombine(n - 1,k);
		for(i = 0;i < temp1.size();i++)temp.push_back(temp1[i]);
		vector<vector<int> > temp2 = partialCombine(n - 1,k - 1);
		for(i = 0;i < temp2.size();i++){temp2[i].push_back(n);temp.push_back(temp2[i]);}
		return temp;
	}
};
//法二：简单dfs
class Solution {
private:
	vector<vector<int> > ret;
	vector<int> a;
public:
	void solve(int dep, int maxDep, int n, int start){
		if (dep == maxDep){
			ret.push_back(a);
			return;
		}
		for(int i = start; i <= n; i++){
			a[dep] = i;
			solve(dep + 1, maxDep, n, i + 1);
		}      
	}
	vector<vector<int> > combine(int n, int k) {
		a.resize(k);
		ret.clear();
		solve(0, k, n, 1);
		return ret;
	}
};
//second edition
class Solution {
	vector<vector<int> > ans;
	int n;
public:
	vector<vector<int> > combine(int m, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ans.clear();
		n = m;
		assert(n >= k);
		if(k == 0)return ans;
		vector<int> v;
		dfs(1,k,v);
		return ans;
	}
	void dfs(int i,int k,vector<int> &v){
		if(k == 0){ans.push_back(v);return;}
		for(;i <= n-k+1;i++){
			v.push_back(i);
			dfs(i+1,k-1,v);
			v.pop_back();
		}
	}
};