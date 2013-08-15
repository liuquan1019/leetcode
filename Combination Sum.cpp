class Solution {
	vector<vector<int> > ans;
	vector<int> num;
	int t;
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ans.clear();
		if(target <= 0 || candidates.empty())return ans;
		num = candidates;
		sort(num.begin(),num.end());
		t = target;
		vector<int> v;
		comb(0,0,v);
		return ans;
	}
	void comb(int sum,int i,vector<int> &v){
		if(sum == t)ans.push_back(v);
		if(sum > t)return;
		for(;i < num.size();i++){
			v.push_back(num[i]);
			comb(sum + num[i],i,v);
			v.pop_back();
		}
	}
};
//second edition类似，只是需注意回溯时的一些参数，容易出错
class Solution {
	vector<vector<int> > ans;
	int n,t;
	vector<int> cand;
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ans.clear();
		n = candidates.size();
		cand = candidates;
		t = target;
		if(n == 0)return ans;
		sort(cand.begin(),cand.end());
		vector<int> q;
		combination(q,0,0);
		return ans;
	}
	void combination(vector<int> &q,int index,int sum){
		if(sum == t){ans.push_back(q);return;}
		for(int j = index;j < n;j++){
			if(sum + cand[j] > t)break;
			else{
				q.push_back(cand[j]);
				combination(q,j,sum + cand[j]);
				q.pop_back();
			}
			while(j < n - 1 && cand[j] == cand[j+1])j++;
		}
	}
};