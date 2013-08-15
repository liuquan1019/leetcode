class Solution {
    vector<int> n;
    int t;
    int Min;
    int ans;
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans = 0;
        if(num.size() < 3)return ans;
    	n = num;
		t = target;
		sort(n.begin(),n.end());
        Min = INT_MAX;
		calc(0,0,0);
        return ans;
    }
    void calc(int i,int sum,int num){
    	if(num == 3){
			if((sum >= t && sum - t < Min) || (sum < t && t - sum < Min)){
                Min = sum - t >= 0 ? sum - t : t - sum;
                ans = sum;
			}
			return;
		}
		for(;i <= n.size() - 3 + num;i++){
			sum += n[i];
			num++;
			calc(i + 1,sum,num);
			sum -= n[i];
			num--;
			while(n[i] == n[i + 1])i++;
		}
	}
};

//second edition
class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = num.size(),minDiff = INT_MAX,minSum;
		if(n < 3)return 0;
		sort(num.begin(),num.end());
		for(int i = 0;i < n;){
			int j = i + 1, k = n - 1;
			while(j < k){
				int sum = num[i] + num[j] + num[k];
				if(sum > target){
					if(sum - target < minDiff){
						minDiff = sum - target;
						minSum = sum;
					}
					k--;
				}
				else if(sum < target){
					if(target - sum < minDiff){
						minDiff = target - sum;
						minSum = sum;
					}
					j++;
				}
				else return target;
			}
			i++;
			while(i < n && num[i] == num[i - 1])i++;
		}
		return minSum;
	}
};