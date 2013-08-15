/*
复习KMP：在匹配过程称，若发生不匹配的情况，如果next[j]>=0，则目标串的指针i不变，将模式串的指针j移动到next[j]的位置继续
        进行匹配；若next[j]=-1，则将i右移1位，并将j置0，继续进行比较。
为了确定在匹配不成功时，下次匹配时j的位置，引入了next[]数组，next[j]的值表示P[0...j-1]中最长后缀的长度等于相同字符序列的前缀
求算next[]数组用递推
根据定义next[0]=-1，假设next[j]=k, 即P[0...k-1]==P[j-k,j-1]

1)若P[j]==P[k]，则有P[0..k]==P[j-k,j]，很显然，next[j+1]=next[j]+1=k+1;

2)若P[j]!=P[k]，则可以把其看做模式匹配的问题，即匹配失败的时候，k值如何移动，显然k=next[k]。
*/
class Solution {
public:
	char *strStr(char *haystack, char *needle) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!needle || !haystack)return NULL;
		if(needle[0] == '\0')return haystack;
		int i,j = 0,k = -1;
		int slen = strlen(haystack),tlen = strlen(needle);
		if(tlen > slen)return NULL;
		int *next = new int[tlen];
		assert(next != 0);
		next[0] = -1;
		while(j < tlen - 1){
			if(k == -1 || needle[j] == needle[k]){
				j++;
				k++;
				next[j] = k;
			}
			else k = next[k];
		}
		i = 0;j = 0;
		while(i < slen && j < tlen){
			if(j == -1 || haystack[i] == needle[j]){
				i++;j++;
			}
			else j = next[j];
		}
		if(j >= tlen)return haystack + (i - tlen);
		return NULL;
	}
};