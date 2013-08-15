class Solution {
public:
	int maxProfit(vector<int> &prices) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = prices.size();
		if(n < 2)return 0;
		int * leftMax, * rightMax;
		leftMax = new int[n];
		rightMax = new int[n];
		leftMax[0] = 0;
		rightMax[n - 1] = 0;
		//错在不能用memset,个别测试数据结果离奇的大，说明未初始化成功
		//memset(leftMax,0,sizeof(leftMax));
		//memset(rightMax,0,sizeof(rightMax));
		int i,minValue = prices[0],maxValue = prices[n - 1];
		for(i = 1;i < n;i++){
			minValue = min(minValue,prices[i]);
			leftMax[i] = max(leftMax[i - 1],prices[i] - minValue);
		}
		int ans = leftMax[n - 1];
		for(i = n - 2;i >= 0;i--){
			maxValue = max(maxValue,prices[i]);
			rightMax[i] = max(maxValue - prices[i],rightMax[i + 1]);
			ans = max(ans,leftMax[i] + rightMax[i]);
		}
		delete [] leftMax;
		delete [] rightMax;
		return ans;
	}
};
//second edition:先判断是否最值是一组解；否则就分治。但大数据超时
/*改进的方法就是动态规划了，那就是第一步扫描，先计算出子序列[0,...,i]中的最大利润，用一个数组保存下来，那么时间是O(n)。
第二步是逆向扫描，计算子序列[i,...,n-1]上的最大利润，这一步同时就能结合上一步的结果计算最终的最大利润了，这一步也是O(n)。
所以最后算法的复杂度就是O(n)的。
*/
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = prices.size();
		if(n == 0)return 0;
		int maxHeight = prices[n-1];
		vector<int> tall;
		for(int i = n - 1;i >= 0;i--){
			if(prices[i] == maxHeight)tall.push_back(prices[i]);
			if(i > 0 && prices[i] < prices[i-1]){
				if(prices[i] == tall[tall.size()-1])tall.pop_back();
				else tall.push_back(prices[i]);
				maxHeight = prices[i-1];
			}
		}
		int m = tall.size();
		if(m == 1)return maxHeight - prices[0];
		if(m % 2){
			if(tall[m-1] == prices[0])tall.pop_back();
			else tall.push_back(prices[0]);
		}
		m = tall.size();
		if(m == 2)return tall[0] - tall[1];
		if(m == 4)return tall[0] - tall[1] + tall[2] - tall[3];
		reverse(tall.begin(),tall.end());
		int ans = 0,max1,max2;
		for(int div = 2;div < m-2;div++){
			max1 = 0;maxHeight = 0;
			for(int i = m - 1;i > div;i--){
				if(tall[i] > maxHeight)maxHeight = tall[i];
				else max1 = max(max1,maxHeight - tall[i]);
			}
			max2 = 0;maxHeight = 0;
			for(int i = div;i >= 0;i--){
				if(tall[i] > maxHeight)maxHeight = tall[i];
				else max2 = max(max2,maxHeight - tall[i]);
			}
			ans = max(ans,max1+max2);
		}
		return ans;
	}
};