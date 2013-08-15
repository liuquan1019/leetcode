/*
��ϰKMP����ƥ����̳ƣ���������ƥ�����������next[j]>=0����Ŀ�괮��ָ��i���䣬��ģʽ����ָ��j�ƶ���next[j]��λ�ü���
        ����ƥ�䣻��next[j]=-1����i����1λ������j��0���������бȽϡ�
Ϊ��ȷ����ƥ�䲻�ɹ�ʱ���´�ƥ��ʱj��λ�ã�������next[]���飬next[j]��ֵ��ʾP[0...j-1]�����׺�ĳ��ȵ�����ͬ�ַ����е�ǰ׺
����next[]�����õ���
���ݶ���next[0]=-1������next[j]=k, ��P[0...k-1]==P[j-k,j-1]

1)��P[j]==P[k]������P[0..k]==P[j-k,j]������Ȼ��next[j+1]=next[j]+1=k+1;

2)��P[j]!=P[k]������԰��俴��ģʽƥ������⣬��ƥ��ʧ�ܵ�ʱ��kֵ����ƶ�����Ȼk=next[k]��
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