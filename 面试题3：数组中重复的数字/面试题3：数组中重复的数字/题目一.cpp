//��Ŀһ���ҳ��������ظ�������
//��һ������Ϊn����������������ֶ���0~n-1�ķ�Χ�ڡ�
//������ĳЩ�������ظ��ģ�����֪���м����������ظ��ˣ�
//Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡�
//���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ��������ظ�������2����3

#include <iostream>
using namespace std;
bool duplicate(int numbers[], int length, int *duplication){
	if (numbers == nullptr || length <= 0){
		return false;

	}
	for (int i = 0; i < length; ++i){
		if (numbers[i]< 0 || numbers[i]>length - 1){ //Ŀ�겻��Ϊ����������鳤��
			return false;
		}
	}
	for (int i = 0; i < length; ++i){
		while (numbers[i] != i){//Ŀ�����±겻��Ƚ���
			if (numbers[i] == numbers[numbers[i]]){//ͬʱ�Ƚ�Ŀ���±��Ƿ����
				*duplication = numbers[i];
				return true;
			}
			//swap numbers[i] and numbers[numbers[i]] //����
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
}