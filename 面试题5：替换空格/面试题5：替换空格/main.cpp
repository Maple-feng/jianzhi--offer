//������5���滻�ո�
//��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"��
//���磬����"We are happy."�������"We%20are%20happy."��

//ʱ�临�Ӷ�O(n)
//˼·��1.�ȱ���һ��ո���������λ�ã�ָ��P1ָ�ַ���β��P2ָ����λ�á�
//2.�Ӻ���ǰ���ƶ��Ӵ����ո��滻��һֱ����ָ���غϡ�

#include <iostream>
using namespace std;
//�����±꼴�ɣ�������ʹ��ָ�롣

void ReplaceBlank(char string[], int length){
	if (string == nullptr || length <= 0){
		return;
	}
	int originalLength = 0;//originalLengthΪ�ַ���string��ʵ�ʳ���
	int numberOfBlank = 0;
	int i = 0;
	while (string[i] != '\0'){
		++originalLength;

		if (string[i] == ' '){
			++numberOfBlank;
		}
		++i;
	}

	int newLength = originalLength + numberOfBlank * 2;//newLengthΪ�ո��滻��'%20'֮��ĳ���
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