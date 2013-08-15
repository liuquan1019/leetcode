//unix路径: .表示当前目录，多个/认为一个，根目录下..仍是跟，即/
class Solution {
public:
	string simplifyPath(string path) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		stack<string> s;
		int i = 0,j;
		int n = path.length();
		while(i < n){
			while(i < n && path[i] == '/')i++;
			if(i == n)break;
			j = i + 1;
			while(j < n && path[j] != '/')j++;
			string temp = path.substr(i,j - i);
			if(temp ==".."){
				if(!s.empty())s.pop();
			}
			else if(temp != ".")s.push(temp);
			i = j;
		}
		if(s.empty())return "/";
		string temp = "";
		while(!s.empty()){
			temp = "/" + s.top() + temp;
			s.pop();
		}
		return temp;
	}
};
//second edition
class Solution {
public:
	string simplifyPath(string path) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<string> v;
		string s = "";
		int n = path.length();
		for(int i = 0;i < n;){
			s = "";
			while(i < n && path[i] == '/')i++;
			while(i < n && path[i] != '/'){s.push_back(path[i]);i++;}
			if(s == "." || s == "")continue;
			if(s == ".."){
				if(!v.empty())v.pop_back();
				continue;
			}
			v.push_back(s);
		}
		if(v.empty())return "/";
		s = "";
		for(int i = 0;i < v.size();i++)s += "/" + v[i];
		return s;
	}
};