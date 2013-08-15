class Solution {
	vector<int> elem;
	vector<bool> visited;
	vector<vector<int> > ans;
	int n;
public:
	vector<vector<int> > permute(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ans.clear();
		n = num.size();
		if(n == 0)return ans;
		vector<int> v;
		if(n == 1){
			v.push_back(num[0]);
			ans.push_back(v);
			return ans;
		}
		elem = num;
		visited = vector<bool>(n,false);
		perm(0,v);
		return ans;
	}
	void perm(int k,vector<int> &v){
		if(k == n)ans.push_back(v);
		for(int i = 0;i < n;i++){
			if(!visited[i]){
				v.push_back(elem[i]);
				visited[i] = true;
				perm(k + 1,v);
				v.pop_back();
				visited[i] = false;
			}
		}
	}
};
//法二是0000的n进制累加；
//法三：不断调用next permutation

/*法四：不断交换
(1) Swap the 1st element with all the elements, including itself.
	(2) Then the 1st element is fixed, go to the next element.
	(3) Until the last element is fixed. Output.
*/
class Solution {
public:
	void perm(vector<int> num,int k,int n, vector<vector<int> > &res){
		if (k==n)
			res.push_back(num);
		else{
			for (int i=k;i<=n;i++){
				int tmp = num[k];
				num[k]=num[i];
				num[i]=tmp;

				perm(num,k+1,n,res);

				tmp = num[k];
				num[k]=num[i];
				num[i]=tmp;
			}
		}
	}
	vector<vector<int> > permute(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int> > res;
		perm(num,0,(num.size()-1),res);
		return res;
	}
};