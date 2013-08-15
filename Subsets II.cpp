//vectorÒ²ÓÐ==,>,<µÈ·ûºÅ
class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
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
		sort(ans.begin(),ans.end());
		for(i = 0;i < ans.size();){
			for(j = i + 1;j < ans.size();){
				if(ans[i] == ans[j])ans.erase(ans.begin() + j);
				else break;
			}
			i = j;
		}
		return ans;
	}
};
//second edition
class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = S.size();
		vector<int> v;
		vector<vector<int> > ans;
		ans.push_back(v);
		if(n == 0)return ans;
		ans.clear();
		sort(S.begin(),S.end()); 
		v = vector<int>(1,S[0]);
		ans.push_back(v);
		int cnt = 0;
		for(int i = 1;i < n;i++){
			if(S[i] == S[i-1])cnt++;
			else cnt = 0;
			int temp = ans.size();         
			for(int j = 0;j < temp;j++){
				if(S[i] == S[i-1]){
					int num = 0;
					for(int k = 0;k < ans[j].size();k++)if(ans[j][k] == S[i])num++;
					if(num < cnt)continue;
				}
				v = ans[j];
				v.push_back(S[i]);
				ans.push_back(v);
			}
			if(cnt)continue;
			v = vector<int>(1,S[i]);
			ans.push_back(v);
		}
		v.clear();
		ans.push_back(v);
		return ans;
	}
};
