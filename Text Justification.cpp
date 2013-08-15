class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<string> ans;
		int i = 0,j,k,cnt,len,extra;
		while(i < words.size()){
			cnt = 0;
			len = 0;
			j = i;
			while(j < words.size() && len + words[j].length() <= L){
				len += words[j].length();
				len ++;
				cnt ++;
				j++;
			}
			extra = L - len + cnt;
			if(j == words.size())break;
			if(cnt == 1){
				string temp = words[i];
				while(extra > 0){temp += " ";extra--;}
				ans.push_back(temp);
			}
			else{
				int avg = extra / (cnt - 1);
				int reminder = extra % (cnt - 1);
				string temp = "";
				for(k = 0;k < j - i - 1;k++){
					temp += words[i + k];
					if(k < reminder)temp += " ";
					extra = avg;
					while(extra > 0){temp += " ";extra--;}
				}
				temp += words[i + k];
				ans.push_back(temp);
			}
			i = j;
		}
		string temp = "";
		for(k = i;k < j - 1;k++)temp += words[k] + " ";
		temp += words[k];
		extra -= cnt - 1;
		while(extra > 0){temp += " ";extra--;}
		ans.push_back(temp);
		return ans;
	}
};
//second edition
class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<string> ans;
		if(L == 0)return words;
		int len = 0,n = words.size();
		for(int i = 0;i < n;i++){
			len = words[i].length() + 1;
			int j = i + 1;
			while(j < n && len + words[j].length() <= L){len += words[j].length() + 1;j++;}
			if(j == i + 1){
				string temp(L-len+1,' ');
				ans.push_back(words[i]+temp);
			}
			else if(j == n){
				string temp = "";
				for(int k = i;k < j - 1;k++)temp += words[k] + " ";
				temp += words[j-1];
				string temp2(L-len+1,' ');
				ans.push_back(temp+temp2);
			}
			else{
				int spaceNum = L - len + (j - i);
				int k = spaceNum % (j - i - 1);
				spaceNum /= (j - i - 1);
				string s = "";
				int t;
				string temp(spaceNum,' ');
				for(t = 0;t < k;t++)s += words[i+t] + temp + " ";
				for(;t < j - i - 1;t++)s += words[i+t] + temp;
				s += words[j-1];
				ans.push_back(s);
			}
			i = j - 1;
		}
		return ans;
	}
};