//暴力搜索也有不同效果，原来枚举首位置、末位置、再遍历其中找最小，共n^3；
//后枚举最右侧的bar,再向前遍历，顺便找到了区间的最小高度，n^2;
//以上大量重复，仍超时，简单剪枝：只对合适的右边界（峰顶），往左遍历面积
class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = height.size();
		if(n == 0)return 0;
		int i,j,ans = 0,h;
		for(i = 0;i < n;i++){
			if(i < n - 1 && height[i] <= height[i + 1])continue;
			h = height[i];
			for(j = i;j >= 0;j--) {
				h = min(h,height[j]);
				ans = max(ans,h * (i - j + 1));
			}
		}
		return ans;
	}
};
/*正规做法：栈模拟
The point of this algorithm is to maintain a stack where higher element is always greater or equal to the 
lower element. Why do we need to maintain that kind of stack? Because if we have a non-decreasing list, we 
can easily calculate the maximum area in one scan. We just need to compare: height[i] * (n – i) for every i.
So how do we maintain this stack? If we keep seeing larger element, we just need to push them onto the stack
. If we see a smaller (compared to the top element on the stack) element, we need to do two things:

1.Pop the stack until we can maintain the non-decreasing order. Pushing the smaller element for m times, 
where m = number of poped elements.
2.Keep track of the maximum area that cause by those pop.

For example, we have height = {1,3,5,7,4}.
We push onto the stack for {1,3,5,7} then we see 4. 4 is less than 7, so we need to pop. We stop popping 
until we see 3. However many times we pop, we push 4 onto the stack. Therefore the resulted stack would be 
{1,3,4,4,4}. Because of popping 7, we need to remember that the maximum area that contains 7 is 7. The 
largest area that contains 5, the other element which get popped, is 10. So we take that down. We then 
finish processing all the elements in the original array and end up with a non-decreasing stack {1,3,4,4,4}.
We can compute the largest area of this stack, which is 4*3 = 12. Since 12 is larger than the previous 
largest, 10, we output 12. 
*/
//third edition
class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = height.size();
		if(n == 0)return 0;
		stack<int> s;
		s.push(height[0]);
		int maxArea = 0,cnt = 0,tmp = 0;
		for(int i = 1;i < n;i++){
			if(height[i] >= s.top())s.push(height[i]);
			else{
				cnt = 0;
				while(!s.empty() && height[i] < s.top()){
					tmp = s.top();
					cnt ++;
					maxArea = max(maxArea,cnt * tmp);
					s.pop();
				}
				cnt ++;
				while(cnt > 0){s.push(height[i]);cnt--;}
			}
		}
		cnt = 0;
		while(!s.empty()){
			tmp = s.top();
			cnt ++;
			maxArea = max(maxArea,cnt * tmp);
			s.pop();
		}
		return maxArea;
	}
};
