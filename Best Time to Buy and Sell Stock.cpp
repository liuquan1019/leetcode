class Solution {
public:
	int maxProfit(vector<int> &prices) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(prices.empty())return 0;
		int n = prices.size();
		int maxPrice = prices[n - 1];
		int ans = 0;
		for(int i = n - 2;i >= 0;i--){
			maxPrice = max(maxPrice,prices[i + 1]);
			ans = max(ans,maxPrice - prices[i]);
		}
		return ans;
	}
};