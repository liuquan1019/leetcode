/*罗马数字转换:基本字符
I = 1;
V = 5;
X = 10;
L = 50;
C = 100;
D = 500;
M = 1000;
(1)相同的数字连写，所表示的数等于这些数字相加得到的数，如：Ⅲ = 3；
(2)小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数， 如：Ⅷ = 8；Ⅻ = 12；
(3)小的数字，（限于Ⅰ、X 和C）在大的数字的左边，所表示的数等于大数减小数得到的数，如：Ⅳ= 4；Ⅸ= 9；
(4)正常使用时连写的数字重复不得超过三次。（表盘上的四点钟--“IIII”，例外。）
(5)在一个数的上面画一条横线，表示这个数扩大1000 倍
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
		char symbol[9] = { 'I','V','X', 'L','C', 'D','M', 'v', 'x' };//v和x应该是大写的上面有一横
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