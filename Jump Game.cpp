class Solution {
public:
	bool canJump(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<bool> f(n,false);
		f[0] = true;
		int far = 0;
		for(int i = 0;i < n;i++){
			if(!f[i] || A[i] == 0)continue;
			for(int j = far + 1;j <= i + A[i] && j < n;j++)f[j] = true;
			far = i + A[i];//��¼��Զ�ɴ�ĵ㣬�����ظ�f��ֵ������ʱ
		}
		return f[n - 1];
	}
};
//second edition:�õݹ顢����¼����������һ�����ݳ�ʱ
class Solution {
    //int n;
    //vector<int> memo;
public:
    bool canJump(int A[], int n) {
        //n = m;
        //memo = vector<int>(n,-1);
        //return can(A,0);
        vector<bool> dp(n,false);
        dp[n - 1] = true;
        int i,j,upper;
        for(i = n - 2;i >= 0;i--){
            if(A[i] ==A[i+1] + 1){dp[i] = dp[i+1];continue;}
            upper = min(n - 1,i + A[i]);
            for(j = upper;j > i;j--)if(dp[j])break;
            if(j != i)dp[i] = true;
        }
        return dp[0];
    }
    /*bool can(int A[], int index) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( A[index] >= n - index - 1)memo[index] == 1;
        if(index == n - 1 || memo[index] == 1)return true;
        for(int i = 1; i <= A[index] && i + index < n;i++){
            if(memo[index + i] == -1)memo[index + i] = can(A,index + i);
            if(memo[index + i] == 1)return true;
        }    
        return false;
    }*/
};
//̰�ģ�̰�ķ��ɽ⣬��Ϊ�����������k�񣬾�һ����������k֮ǰ������һ�񡣾�û��Ҫ��dp�ˡ�
bool canJump(int A[], int n) {  
	int maxCover = 0;  
	for(int start =0; start<= maxCover && start<n; start++){  
		if(A[start]+start > maxCover)maxCover = A[start]+start;  
		if(maxCover >= n-1) return true;  
	}  
	return false;  
} 