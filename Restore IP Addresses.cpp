//题目本身没难度，关键是细心对临界case，比如.00.或.01.
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<string> ans;
		int len = s.length();
		if(len < 4 || len > 12)return ans;
		int i,j,k;
		for(i = 1;i <= 3 && i <= len - 3;i++ )
			for(j = i + 1;j <= i + 3 && j <= len - 2;j++)
				for(k = j + 1;k <= j + 3 && k <= len - 1;k++){
					int a = atoi(s.substr(0,i).c_str());
					int b = atoi(s.substr(i,j - i).c_str());
					int c = atoi(s.substr(j,k - j).c_str());
					int d = atoi(s.substr(k,len - k).c_str());
					if(a != 0 && s[0] == '0')continue;
					if(b != 0 && s[i] == '0')continue;
					if(c != 0 && s[j] == '0')continue;
					if(d != 0 && s[k] == '0')continue;

					if(a == 0 && i > 1)continue;
					if(b == 0 && j - i > 1)continue;
					if(c == 0 && k - j > 1)continue;
					if(d == 0 && len - k > 1)continue;
					if(a < 256 && b < 256 && c < 256 && d < 256)
						ans.push_back(s.substr(0,i) + "." +
						s.substr(i,j - i) + "." +
						s.substr(j,k - j) + "." +
						s.substr(k,len - k));
				}
				return ans;
	}
};
//second edition
class Solution {
	vector<string> ans;
public:
	vector<string> restoreIpAddresses(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ans.clear();
		int n = s.length();
		if(n < 4 || n > 12)return ans;
		restore(s,3,0);
		return ans;
	}
	void restore(string &s,int cnt,int i){
		int n = s.length();
		if(cnt == 0){
			if(i < n - 1 && s[i] == '0')return;
			int t = 0;
			for(;i < n;i++)t = 10 * t + s[i] - '0';
			if(t <= 255)ans.push_back(s);
			return;
		}
		int t = 0;
		for(;i < n - 1;i++){
			t = 10 * t + s[i] - '0';
			if(t <= 255){
				s.insert(s.begin()+i+1,'.');
				restore(s,cnt-1,i+2);
				s.erase(s.begin()+i+1);
				if(t == 0)break;
			}
			else break;
		} 
	}
};