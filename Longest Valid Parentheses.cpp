//Ѱ�ҹ��ɲ���������fail,����뵽����һ�鷴��һ�飬���˸����case�������ҶԳƵ���Ȼfail
class Solution {
public:
	int longestValidParentheses(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(s.empty())return 0;
		stack<int> st;
		int ans = 0,leftMost = s.size();
		for(int i = 0;i < s.length();i++){
			if(s[i] == '(')st.push(i);
			else if(st.empty())leftMost = i + 1;
			else{
				leftMost = min(leftMost,st.top());//�ϲ�ǰ��Ĺؼ�
				st.pop();
				if(st.empty())
					ans = max(ans,i - leftMost + 1);
				else
					ans = max(ans,i - st.top());//�ٴε������ж���(ʱ�ĺϲ�
			}
		}
		return ans;
	}
};
//˳һ�飬��һ��
int counter = 0;
int ret = 0;
int curr_max = 0;
//forward path
for(size_t i = 0 ; i < s.length() ; i++){
	if(s[i] == '('){
		counter++;
		curr_max++;
	}
	else if(s[i] == ')'){
		counter--;
		curr_max++;
	}
	if(counter == 0)
		ret = ret >= curr_max ? ret : curr_max;
	else if(counter < 0){
		curr_max = 0;
		counter = 0;
	}
}
//backward path
counter = 0;
curr_max = 0;
for(int i = s.length() -1; i >=0; i--){
	if(s[i] == ')'){
		counter++;
		curr_max++;
	}
	else if(s[i] == '('){
		counter--;
		curr_max++;
	}
	if(counter == 0)
		ret = ret >= curr_max ? ret : curr_max;
	else if(counter < 0){
		curr_max = 0;
		counter = 0;
	}
}
return ret;
//��ʵҲ����һ�飬���ǳ����ռ���ۣ���Ҫ���棨��λ��
class Solution {
public:
	int longestValidParentheses(string s) {
		int max_len = 0;
		int cur_len = 0;
		stack<int> left_stack;
		vector<bool> v(s.size(), false);

		for( int i = 0; i < s.size(); i ++) {
			if(s[i] == '(') left_stack.push(i);
			if((s[i] == ')') && (left_stack.size() > 0)) {
				v[left_stack.top()] = true;
				left_stack.pop();
				v[i] = true;
			}
		}
		for( int i = 0; i < s.size(); i ++) {
			if(v[i] == true) {
				cur_len++;
				max_len = max(max_len, cur_len);
			} 
			else cur_len = 0;
		}

		return max_len;
	}
};
//third edition
class Solution {
public:
	int longestValidParentheses(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = s.length();
		if(n < 2)return 0;
		stack<int> st;//��ʼ��char,�����ڳ���10���������޷�����һ��char��ʾ�����³���
		for(int i = 0;i < n;i++){
			if(s[i] == '('){st.push(-'(');continue;}
			else if(st.empty() || st.top() == -')')continue;
			else if(st.top() == -'('){st.pop();st.push(2);}
			else{
				int tmp = st.top();
				st.pop();
				if(st.empty() || st.top() == -')'){st.push(tmp);st.push(-')');continue;}
				else{st.pop();st.push(tmp+2);}
			}
			int cnt = 0;
			while(!st.empty() && st.top() > 0){
				cnt += st.top();
				st.pop();
			}
			st.push(cnt);
		}
		int maxNum = 0;
		while(!st.empty()){
			if(st.top() > 0)maxNum = max(maxNum,st.top());
			st.pop();
		}
		return maxNum;
	}
};