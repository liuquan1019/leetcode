//ԭ����26λ��������ģ�ⵥ���г��ֵ���ĸ����������һ����ĸ���ܲ�ֹ����һ�Σ���λ����ģ�ⲻ��
class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(strs.empty())return strs;
		int i,j;
		vector<string> ans;
		int n = strs.size();
		vector<int> f(n,0);
		for(i = 0;i < n;i++){
			for(j = 0; j < strs[i].length();j++)f[i] += 1 << (strs[i][j] - 'a');
		}
		vector<int> f2 = f;
		sort(f2.begin(),f2.end());
		for(i = 0;i < n - 1;i++){
			if(f2[i] == f2[i + 1]){
				i++;
				while(f2[i] == f2[i + 1])i++;
				i--;
				for(j = 0;j < n;j++)
					if(f[j] == f2[i])ans.push_back(strs[j]);
			}
		}
		return ans;
	}
};
//������26λ�������飬��ᳬʱ��Ӧ�ٽ�������ӳ��Ϊһ�����֣��뵽��long��(��string��footprint),��64λ��long long Ҳ���
//19λ��������26λ���ʶ�����10���ƣ���Ϊ��С����7��5����3����fail�ģ�������������ȷ��һ����ȷ
class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(strs.empty())return strs;
		int i,j;
		vector<string> ans;
		int n = strs.size();
		vector<long long> f(n,0);
		for(i = 0;i < n;i++){
			vector<int> fp(26,0);
			for(j = 0; j < strs[i].length();j++)fp[strs[i][j] - 'a']++;
			for(j = 0;j < 26;j++)f[i] = f[i] * 7 + fp[j];
		}
		vector<long long> f2 = f;
		sort(f2.begin(),f2.end());
		for(i = 0;i < n - 1;i++){
			if(f2[i] == f2[i + 1]){
				i++;
				while(f2[i] == f2[i + 1])i++;
				i--;
				for(j = 0;j < n;j++)
					if(f[j] == f2[i])ans.push_back(strs[j]);
			}
		}
		return ans;
	}
};

//��������sorted string��key��map�洢������ֱ�����
class Solution {
private:
	vector<string> ret;
	map<string, vector<string> > m;
public:
	vector<string> anagrams(vector<string> &strs) {
		ret.clear();
		m.clear();
		for(int i = 0; i < strs.size(); i++){
			string sortStr(strs[i]);
			sort(sortStr.begin(), sortStr.end());
			m[sortStr].push_back(strs[i]);
		}
		for(map<string, vector<string> >::iterator iter = m.begin(); iter != m.end(); iter++){
			if ((iter->second).size() > 1){
				for(int i = 0; i < (iter->second).size(); i++)
					ret.push_back((iter->second)[i]);
			}
		}
		return ret;
	}
};
//second edition
class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		map<string,vector<string> > m;
		for(int i = 0;i < strs.size();i++){
			string temp = strs[i];
			sort(temp.begin(),temp.end());
			if(m.count(temp) == 0){vector<string> v;m[temp] = v;}
			m[temp].push_back(strs[i]);
		}
		vector<string> ans;
		map<string,vector<string> > :: iterator it = m.begin();
		while(it != m.end()){
			if((it -> second).size() >= 2)
				for(int i = 0;i < (it -> second).size();i++)ans.push_back((it -> second)[i]);
			it++;
		}
		return ans;
	}
};