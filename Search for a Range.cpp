class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> v0(2,-1);
		if(n <= 0 || target < A[0] || target > A[n - 1])return v0;
		int s = biSearchStart(A,0,n - 1,target);
		if(s == -1)return v0;
		if(s == n - 1 || A[s + 1] != target){
			vector<int> v(2,s);
			return v;
		}
		int e = biSearchEnd(A,s + 1,n - 1,target);
		v0.clear();
		v0.push_back(s);
		v0.push_back(e);
		return v0;
	}
	int biSearchStart(int A[],int l,int r,int target){
		int m = (l + r) / 2;
		if(A[m] == target && (m == 0 || A[m - 1] != target))return m;
		if(A[m] < target && A[m + 1] > target)return -1;
		if(r - l == 1 || r == l){
			if(A[r] == target)return r;
			return -1; 
		}
		if(A[m] >= target)return biSearchStart(A,l,m - 1,target);
		return biSearchStart(A,m + 1,r,target);
	}
	int biSearchEnd(int A[],int l,int r,int target){
		int m = (l + r) / 2;
		if(A[m] == target && A[m + 1] != target)return m;
		if(r == l)return r;
		if(r - l == 1 && A[r] == target)return r;
		if(A[m] > target)return biSearchEnd(A,l,m - 1,target);
		return biSearchEnd(A,m + 1,r,target);
	}
};

//second edition
class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> ans;
		int l = 0,r = n - 1,m;
		while(l <= r){
			m = (l + r) / 2;
			if(target == A[m] && A[m - 1] != A[m]){ans.push_back(m);break;}
			if(r - l == 1 || r == l){
				if(target == A[r] && A[r - 1] != A[r])ans.push_back(r);
				break;
			}
			if(target <= A[m])r = m;
			else l = m;
		}
		if(ans.empty()){ans.push_back(-1);ans.push_back(-1);return ans;}
		l = ans[0] + 1;r = n - 1;
		while(l <= r){
			m = (l + r) / 2;
			if(target == A[m] && A[m + 1] != A[m]){ans.push_back(m);break;}
			if(r - l == 1 || r == l){
				if(target == A[r] && A[r + 1] != A[r])ans.push_back(r);
				break;
			}
			if(target < A[m])r = m;
			else l = m;
		}
		if(ans.size() == 1)ans.push_back(ans[0]);
		return ans;
	}
};