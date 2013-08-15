class Solution {
	int f[9];
public:
	string getPermutation(int n, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		f[1] = 1;
		for(int i = 2; i < 9;i++)f[i] = f[i - 1] * i;
		return partialPermutation(n,k);
	}
	string partialPermutation(int n,int k){
		if(k > f[n])return "";
		if(n == 1)return "1";
		if(n == 2){
			string an[2] = {"12","21"};
			return an[k - 1];
		}
		int kk = k % f[n - 1];
		int t = k / f[n - 1] + 1;
		if(kk == 0){t--;kk = f[n - 1];}
		string temp = partialPermutation(n - 1,kk);
		for(int i = 0;i < temp.length();i++)
			if(temp[i] >= '0' + t)
				temp[i]++;
		stringstream ss;
		ss << t;
		return ss.str() + temp;
	}
};

//以上做法可改为递推，因为单一路径降阶
class Solution {
public:
	string getPermutation(int n, int k) {
		char *arr = new char[n];
		int pro = 1;
		for(int i = 0 ; i < n; ++i) {
			arr[i] = '1' + i;
			pro *= (i + 1);
		}
		k = k - 1;//让k的范围是0 <= k < n!
		k %= pro;
		pro /= n;//pro = 1 * 2 * ... * (n-1)
		for(int i = 0 ; i < n-1; ++i) {
			//for index i
			int selectI = k / pro;
			k = k % pro;
			pro /= (n - i - 1);
			int temp = arr[selectI + i];
			for(int j = selectI; j > 0; --j)
				arr[i + j] = arr[i + j - 1];
			arr[i] = temp;
		}
		return string(arr, arr + n);
	}
};
//法三：dfs依次输出各序列
class Solution {
private:
	int a[10];
	bool canUse[10];
	string ret;
public:
	void dfs(int dep, int maxDep, int &k){
		if (k == 0)return;
		if (dep == maxDep){
			k--;
			if (k == 0){
				ret = "";
				for(int i = 0; i < maxDep; i++)
					ret += (char)(a[i] + '0');
				return;
			}
		}
		for(int i = 1; i <= maxDep; i++)
			if (canUse[i]){
				canUse[i] = false;
				a[dep] = i;
				dfs(dep + 1, maxDep, k);
				canUse[i] = true;
			}
	}
	string getPermutation(int n, int k) {
		memset(canUse, true, sizeof(canUse));
		dfs(0, n, k);
		return ret;
	}
};
//second edition
class Solution {
public:
	string getPermutation(int n, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n == 1)return "1";
		int m = 1;
		for(int i = 2;i < n;i++)m *= i;
		int digit = k / m,plus = k % m;
		if(plus)digit++;
		else plus = m;
		string temp = getPermutation(n-1,plus);
		for(int i = 0;i < temp.size();i++)if(temp[i] - '0' >= digit)temp[i]++;
		string c(1,digit + '0');
		return c+temp;
	}
};
