class Solution {
	vector<vector<int> > ans;
	vector<int> n;
	int t;
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ans.clear();
		if(num.size() < 4)return ans;
		n = num;
		t = target;
		sort(n.begin(),n.end());
		if(n[0] + n[1] + n[2] + n[3] > target)return ans;
		if(n[n.size()-1] + n[n.size()-2] +n[n.size()-3] +n[n.size()-4] < target)return ans;
		vector<int> v;
		calc(0,v,0,0);
		return ans;
	}
	void calc(int i,vector<int> &v,int sum,int num){
		if(num == 4){
			if(sum == t)ans.push_back(v);
			return;
		}
		for(;i <= n.size() - 4 + num;i++){
			int sum2 = sum;
			for(int j = i;j <=3-num+i && j < n.size();j++)sum2+=n[j];//剪枝，否则超时
			if(sum2 > t)return;
			sum2 = sum;
			for(int j = n.size() - 1;j >=n.size()+num-4 && j>=0;j--)sum2+=n[j];
			if(sum2 < t)return;
			v.push_back(n[i]);
			sum += n[i];
			num++;
			calc(i + 1,v,sum,num);
			v.pop_back();
			sum -= n[i];
			num--;
			while(n[i] == n[i + 1])i++;
		}
	}
};

//second edition
class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int> > ans;
		int n = num.size();
		if(n < 4)return ans;
		sort(num.begin(),num.end());
		for(int i = 0;i < n;){
			for(int i2 = i + 1;i2 < n;){
				int j = i2 + 1, k = n - 1;
				while(j < k){
					int sum = num[i] + num[i2] + num[j] + num[k];
					if(sum > target)k--;
					else if(sum < target)j++;
					else{
						vector<int> triplet;
						triplet.push_back(num[i]);
						triplet.push_back(num[i2]);
						triplet.push_back(num[j]);
						triplet.push_back(num[k]);
						ans.push_back(triplet);
						j++;k--;
						while(j < n && num[j] == num[j - 1])j++;
						while(k >= 0 && num[k] == num[k + 1])k--;
					}
				}
				i2++;
				while(i2 < n && num[i2] == num[i2 - 1])i2++;
			}
			i++;
			while(i < n && num[i] == num[i - 1])i++;
		}
		return ans;
	}
};
//递归穷举太差，n^k复杂度，用经典2sum的做法降至n^3，但是更好是用hash达到O(n^2)
//以和为key才能O(n^2)，若以下标组合为key,则C(n,2) = n^2,复杂度变为O(n^4)，以下超时
struct Index{
	int index1,index2;
	Index(int i,int j){
		index1 = i;index2 = j;
	}
	bool operator < (const Index &other)const{
		if(index1 != other.index1)return index1 < other.index1;
		return index2 < other.index2;
	}
};
class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		map<Index,int> hash;
		for(int i = 0;i < num.size();i++)
			for(int j = i + 1;j < num.size();j++){
				Index index(i,j);
				hash[index] = num[i] + num[j];
			}
		map<Index,int>::iterator it1 = hash.begin(),it2;
		vector<vector<int> > ans;
		for(;it1 != hash.end();it1++){
			it2 = it1;it2++;
			for(;it2 != hash.end();it2++)
				if(it1 -> second + it2 -> second == target &&
				it1 -> first.index1 != it2 -> first.index1 &&
				it1 -> first.index1 != it2 -> first.index2 &&
				it1 -> first.index2 != it2 -> first.index1 &&
				it1 -> first.index2 != it2 -> first.index2){
					vector<int> v;
					v.push_back(num[it1 -> first.index1]);
					v.push_back(num[it1 -> first.index2]);
					v.push_back(num[it2 -> first.index1]);
					v.push_back(num[it2 -> first.index2]);
					sort(v.begin(),v.end());
					ans.push_back(v);
				}
		}
		sort(ans.begin(),ans.end());
		for(int i = ans.size() - 1;i > 0;i--)if(ans[i] == ans[i-1])ans.erase(ans.begin() + i);
		return ans;
	}
};
