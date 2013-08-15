//双指针，动态维护一个区间。尾指针不断往后扫，当扫到有一个窗口包含了所有T的字符后，然后再收缩头指针，直到不能再收缩为止。
//最后记录所有可能的情况中窗口最小的
class Solution {
public:
	string minWindow(string S, string T) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int sLen = S.length(),tLen = T.length();
		if(sLen == 0 || sLen < tLen)return "";
		vector<int> appear(256,0);
		vector<int> expect(256,0);
		int i;
		for(i = 0;i < tLen;i++)expect[T[i]]++;//hash
		int width = INT_MAX,minStart = 0;
		int start = 0,end;
		int cnt = 0;
		for(end = 0;end < sLen;end++){
			if(expect[S[end]] > 0){
				appear[S[end]]++;
				if(appear[S[end]] <= expect[S[end]])cnt++;//用<是因为和整个T的长度作比，而不是不同字符的个数
			}
			if(cnt == tLen){
				while(expect[S[start]] == 0 || appear[S[start]] > expect[S[start]]){
					appear[S[start]]--;
					start++;
				}
				if(width > end - start + 1){
					width = end - start + 1;
					minStart = start;
				}
			}
		}
		if(width == INT_MAX)return "";
		return S.substr(minStart,width);
	}
};
//second edition
class Solution {
public:
	string minWindow(string S, string T) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		string ans = "";
		int i = 0,j = 0,len = INT_MAX,n = S.length();
		vector<int> target(256,0);
		vector<int> source(256,0);
		for(i = 0;i < T.length();i++)target[T[i]]++;
		for(j = 0;j < n;j++){
			source[S[j]]++;
			for(i = 0;i < 256;i++)if(source[i] < target[i])break;
			if(i == 256)break;
		}
		if(j == n)return ans;

		i = 0;
		while(source[S[i]] - 1 >= target[S[i]]){
			source[S[i]]--;
			i++;
		}
		if(j - i + 1 < len){
			len = j-i+1;
			ans = S.substr(i,j-i+1);
		}
		source[S[i]]--;
		i++;

		while(j < n - 1){
			while(j < n - 1&& source[S[i-1]] < target[S[i-1]]){
				j++;
				source[S[j]]++;
			}
			if(source[S[i-1]] == target[S[i-1]]){
				while(source[S[i]] - 1 >= target[S[i]]){
					source[S[i]]--;
					i++;
				}
				if(j - i + 1 < len){
					len = j-i+1;
					ans = S.substr(i,j-i+1);
				} 
			}
			source[S[i]]--;
			i++;
		}

		return ans;
	}
};