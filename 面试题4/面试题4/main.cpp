//������4����ά�����еĲ���
//��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������
//ÿһ�ж����մ��ϵ��µ�����˳�����������һ����������������
//��һ����ά�����һ���������ж��������Ƿ��и�����

#include <iostream>
using namespace std;
//˼·��ÿ��ѡ�����ϣ��������£���������ɾ��

bool Find(int *matrix, int rows, int columns, int number){
	bool found = false;

	if (matrix != nullptr&&rows > 0 && columns > 0){
		int row = 0;
		int column = columns - 1;
		while (row < rows&&columns >= 0){
			if (matrix[row*columns + column] == number){
				found = true;
				break;
			}
			else if (matrix[row*columns + column]>number){  //�������ִ���Ŀ������---ɾ����
				--column;
			}
			else{  //��������С��Ŀ������---ɾ����  ����+1��
				++row;
			}
		}
	}
	return found;
}