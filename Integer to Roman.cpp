/*��������ת��:�����ַ�
I = 1;
V = 5;
X = 10;
L = 50;
C = 100;
D = 500;
M = 1000;
(1)��ͬ��������д������ʾ����������Щ������ӵõ��������磺�� = 3��
(2)С�������ڴ�����ֵ��ұߣ�����ʾ����������Щ������ӵõ������� �磺�� = 8���� = 12��
(3)С�����֣������ڢ�X ��C���ڴ�����ֵ���ߣ�����ʾ�������ڴ�����С���õ��������磺��= 4����= 9��
(4)����ʹ��ʱ��д�������ظ����ó������Ρ��������ϵ��ĵ���--��IIII�������⡣��
(5)��һ���������滭һ�����ߣ���ʾ���������1000 ��
*/
class Solution {
public:
	void appendNumToRoman(int num, string &roman, char symbols[]) {
		if (num == 0)
			return;
		if (num <= 3) {
			roman.append(num,symbols[0]);
		} 
		else if (num == 4) {
			roman.append(1,symbols[0]);
			roman.append(1,symbols[1]);
		} 
		else if (num <= 8) {
			roman.append(1,symbols[1]);
			roman.append(num - 5,symbols[0]);
		} 
		else {
			//num == 9
			roman.append(1,symbols[0]);
			roman.append(1,symbols[2]);
		}
	}
	string intToRoman(int num) {
		char symbol[9] = { 'I','V','X', 'L','C', 'D','M', 'v', 'x' };//v��xӦ���Ǵ�д��������һ��
		string roman = "";
		int scale = 1000;
		for (int i = 6; i >= 0 ; i -= 2) {
			int digit = num / scale;
			appendNumToRoman(digit, roman, symbol + i);
			num = num % scale;
			scale /= 10;
		}
		return roman;
	}
};