//面试题5：替换空格
//题目：请实现一个函数，把字符串中的每个空格替换成"%20"。
//例如，输入"We are happy."，则输出"We%20are%20happy."。

//时间复杂度O(n)
//思路：1.先遍历一遍空格数和最终位置，指针P1指字符串尾，P2指最终位置。
//2.从后往前，移动子串，空格替换，一直到两指针重合。

#include <iostream>
using namespace std;
//计算下标即可，无需再使用指针。

void ReplaceBlank(char string[], int length){
	if (string == nullptr || length <= 0){
		return;
	}
	int originalLength = 0;//originalLength为字符串string的实际长度
	int numberOfBlank = 0;
	int i = 0;
	while (string[i] != '\0'){
		++originalLength;

		if (string[i] == ' '){
			++numberOfBlank;
		}
		++i;
	}

	int newLength = originalLength + numberOfBlank * 2;//newLength为空格替换成'%20'之后的长度
	if (newLength > length){
		return;
	}

	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal){
		if (string[indexOfOriginal] == ' '){
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else{
			string[indexOfNew--] = string[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}