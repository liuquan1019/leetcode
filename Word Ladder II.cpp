//除了对不同字符串求其foorprint向量外，也可直接比较不同字符的位数建立一个距离矩阵
class Solution {
	vector<vector<string>> ans;
	vector<string> d;
	vector<bool> visited;
	int diff[1000][1000];
	int Min;
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ans.clear();
		d.clear();
		Min = INT_MAX;
		d.push_back(start);
		for(unordered_set<string>::iterator it = dict.begin();it != dict.end();it++)
			if(*it != start && *it != end)d.push_back(*it);
		d.push_back(end);
		visited = vector<bool>(d.size(),false);
		for(int i = 0;i < d.size();i++)
			for(int j = i;j < d.size();j++){
				if(j == i){diff[i][j] = 0;continue;}
				int cnt = 0;
				for(int k = 0;k < d[i].size();k++)if(d[i][k] != d[j][k])cnt++;
				diff[i][j] = cnt;
				diff[j][i] = cnt;
			}
			vector<string> v;
			v.push_back(start);
			dfs(0,0,v);
			return ans;
	}
	void dfs(int i,int cnt,vector<string> &v){
		if(i == d.size() - 1){
			if(cnt == Min)ans.push_back(v);
			else if(cnt < Min){
				Min = cnt;
				ans.clear();
				ans.push_back(v);
			}
			return;
		}
		for(int j = 0;j < d.size();j++){
			if(diff[j][i] == 1 && !visited[j]){
				visited[j] = true;
				v.push_back(d[j]);
				dfs(j,cnt++,v);
				visited[j] = false;
				v.pop_back();
			}
		}
	}
};
//宽搜用前驱构建路径
class Solution {
public:
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		pathes.clear();
		dict.insert(start);
		dict.insert(end);
		vector<string> prev;
		unordered_map<string, vector<string> > traces;
		for (unordered_set<string>::const_iterator citr = dict.begin(); 
			citr != dict.end(); citr++) {
				traces[*citr] = prev;
		}

		vector<unordered_set<string> > layers(2);
		int cur = 0;
		int pre = 1;
		layers[cur].insert(start);
		while (true) {
			cur = !cur;
			pre = !pre;
			for (unordered_set<string>::const_iterator citr = layers[pre].begin();
				citr != layers[pre].end(); citr++)
				dict.erase(*citr);
			layers[cur].clear();
			for (unordered_set<string>::const_iterator citr = layers[pre].begin();
				citr != layers[pre].end(); citr++) {
					for (int n=0; n<(*citr).size(); n++) {  
						string word = *citr;  
						int stop = word[n] - 'a';  
						for (int i=(stop+1)%26; i!=stop; i=(i+1)%26) {  
							word[n] = 'a' + i;  
							if (dict.find(word) != dict.end()) {  
								traces[word].push_back(*citr);
								layers[cur].insert(word); 
							}  
						}
					}
			}
			if (layers[cur].size() == 0)
				return pathes;
			if (layers[cur].count(end))
				break;
		}
		vector<string> path;
		buildPath(traces, path, end);

		return pathes;
	}

private:
	void buildPath(unordered_map<string, vector<string> > &traces, 
		vector<string> &path, const string &word) {
			if (traces[word].size() == 0) {
				path.push_back(word);
				vector<string> curPath = path;
				reverse(curPath.begin(), curPath.end());
				pathes.push_back(curPath);
				path.pop_back();
				return;
			}

			const vector<string> &prevs = traces[word];
			path.push_back(word);
			for (vector<string>::const_iterator citr = prevs.begin();
				citr != prevs.end(); citr++) {
					buildPath(traces, path, *citr);
			}
			path.pop_back();
	}

	vector<vector<string> > pathes;
};
