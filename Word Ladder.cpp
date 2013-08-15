//����С�ÿ��ѽϿ죬������Ҫ���ȫ����С·������������
class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(start.size() == 0 || end.size() == 0 || dict.size() == 0)return 0;
		if(start == end)return 0;
		unordered_set<string>::iterator it;
		queue<string> q1,q2;
		q1.push(start);
		int cnt = 0;
		while(!q1.empty() || !q2.empty()){
			cnt++;
			while(!q1.empty()){
				start = q1.front();
				q1.pop();
				if(start == end)return cnt;
				for(int i = 0;i < start.length();i++)
					for(char j = 'a';j <= 'z';j++){//ֻ��һ���ַ���ͬ������footprint��ֱ��ö�ټ���
						if(start[i] == j)continue;
						string temp = start;
						temp[i] = j;//Ϊ���ٴα�����ĳԪ�أ�bfs����Сʱ�����ٱ�����һ��ʱ��ɾ����
						if((it = dict.find(temp)) != dict.end()){q2.push(temp);dict.erase(it);}
					}
			}
			swap(q1,q2);
		}
		return 0;
	}
};