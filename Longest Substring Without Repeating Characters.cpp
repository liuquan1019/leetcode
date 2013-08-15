//���ɽ�һ���Ż���������ɨ�裬�������ظ���ĸʱ������һ���ظ���ĸ��index +1����Ϊ�µ�������ʼλ�ã�
//��ʱhash���Բ������0��1��ʾ�Ƿ���֣����Ǵ洢���ֵ��±꣬-1Ϊδ����
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len = s.length();
		if(len <= 1)return len;
		int m = 1;
		int i,j;
		for(i = 0;i <= len - m;i++){
			vector<bool> v(257,false);
			v[s[i]] = true;
			for(j = i + 1;j < len;j++){
				if(!v[s[j]])v[s[j]] = true;
				else break;
			}
			m = max(m,j - i);
			if(j == len)break;
		}
		return m;
	}
};
//second edition
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = s.length();
		int maxLength = 0;
		for(int i = 0;i < n;i++){
			int mask = 0,len = 0;
			while(i + len < n && (mask >> (s[i+len] - 'a') & 1) == 0){
				mask |= 1 << (s[i+len] - 'a');
				len ++;
			}
			maxLength = max(maxLength,len);
		}
		return maxLength;
	}
};