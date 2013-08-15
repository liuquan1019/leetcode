class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> num = numbers;
		sort(num.begin(),num.end());
		vector<int> ans;
		int i,j,k;
		for(i = 0,j = num.size() - 1;i < j;){
			if(num[i] + num[j] == target)break;
			else if(num[i] + num[j] < target)i++;
			else j--;
		}
		for(k = 0;k < numbers.size();k++)
			if(numbers[k] == num[i] || numbers[k] == num[j])ans.push_back(k + 1);
		return ans;
	}
};
//未排序：想两指针扫描需要先排序，又需下标位置故要O(n)空间存储，还不如直接hash,优化至一遍扫描的O(n)
unordered_map<int, int> index_map;
unordered_map<int, int>::iterator it;
for (int i=0; i<numbers.size(); ++i) {
	it = index_map.find(target-numbers[i]);
	if (it != index_map.end()) {
		vector<int> result(2);
		result[0] = it->second;
		result[1] = i+1;
		return result;
	} else {
		index_map[numbers[i]] = i+1;
	}
}
return vector<int>();