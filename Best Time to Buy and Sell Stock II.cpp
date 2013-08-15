class Solution {
public:
	int maxProfit(vector<int> &prices) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(prices.empty())return 0;
		int n = prices.size();
		int i = 0,j = 0,ans = 0;
		for(i = 0;i < n;){
			for(j = i;j < n - 1;){
				if(prices[j] <= prices[j + 1])j++;
				else break;
			}
			ans += prices[j] - prices[i];
			i = j + 1;
		}
		return ans;
	}
};
//second edition
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = prices.size();
		int maxPrice = 0,ans = 0;
		for(int i = n - 1;i >= 0;i--){
			if(prices[i] > maxPrice)maxPrice = prices[i];
			else if(i == 0 || prices[i] <= prices[i-1]){
				ans += maxPrice - prices[i];
				maxPrice = 0;
			}
		}
		return ans;
	}
};