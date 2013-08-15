class Solution {
	vector<vector<int> > ans;
	vector<int> number;
	int t;
public:
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ans.clear();
		if(target <= 0 || num.empty())return ans;
		number = num;
		sort(number.begin(),number.end());
		t = target;
		vector<int> v;
		comb(0,0,v);
		/*sort(ans.begin(),ans.end());
		for(int i = 1;i < ans.size();){
			if(ans[i - 1] == ans[i])ans.erase(ans.begin() + i);
			else i++;
		}*/
		return ans;
	}
	void comb(int sum,int i,vector<int> &v){
		if(sum == t)ans.push_back(v);
		if(sum > t)return;
		for(;i < number.size();i++){
			v.push_back(number[i]);
			comb(sum + number[i],i + 1,v);
			v.pop_back();
			while(i < number.size() - 1 && number[i] == number[i + 1])i++;//±ÜÃâÖØ¸´
		}
	}
};