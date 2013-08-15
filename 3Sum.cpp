class Solution {
	vector<vector<int> > ans;
	vector<int> n;
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ans.clear();
		if(num.size() < 3)return ans;
		n = num;
		sort(n.begin(),n.end());
		if(n[0] > 0)return ans;
		vector<int> v;
		calc(0,v,0,0);
		return ans;
	}
	void calc(int i,vector<int> &v,int sum,int num){
		if(num == 3){
			if(sum == 0)ans.push_back(v);
			return;
		}
		if(sum > 0)return;
		for(;i <= n.size() - 3 + num;i++){
			if(sum + n[i] <= 0){
				v.push_back(n[i]);
				sum += n[i];
				num++;
				calc(i + 1,v,sum,num);
				v.pop_back();
				sum -= n[i];
				num--;
				while(n[i] == n[i + 1])i++;
			}
			else return;
		}
	}
};

//second edition
class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int> > ans;
		int n = num.size();
		if(n < 3)return ans;
		sort(num.begin(),num.end());
		for(int i = 0;i < n;){
			if(num[i] > 0)break;
			int j = i + 1, k = n - 1;
			while(j < k){
				int sum = num[i] + num[j] + num[k];
				if(sum > 0)k--;
				else if(sum < 0)j++;
				else{
					vector<int> triplet;
					triplet.push_back(num[i]);
					triplet.push_back(num[j]);
					triplet.push_back(num[k]);
					ans.push_back(triplet);
					j++;k--;
					while(j < n && num[j] == num[j - 1])j++;
					while(k >= 0 && num[k] == num[k + 1])k--;
				}
			}
			i++;
			while(i < n && num[i] == num[i - 1])i++;
		}
		return ans;
	}
};