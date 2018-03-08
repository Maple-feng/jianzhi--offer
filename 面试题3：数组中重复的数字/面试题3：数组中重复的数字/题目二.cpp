//��Ŀ�������޸������ҳ��ظ������֡�
//��һ������Ϊn+1����������������ֶ���1~n�ķ�Χ�ڣ�
//����������������һ���������ظ��ġ����ҳ�����������һ���ظ������֣�
//�������޸���������顣���磬������볤��8������{2,3,5,4,3,2,6,7}��
//��ô��Ӧ��������ظ�������2����3��

int getDuplication(const int *numbers, int length){
	//���ƶ��ֲ���˼·�������鳤������һ��Ϊ����ͳ��������ÿһ�����ֳ��ִ�������һ��Ԫ�ض࣬�ٽ��ж���
	if (numbers == nullptr || length <= 0){
		return -1;
	}
	int start = 1;
	int end = length - 1;
	while (end >= start){
		int middle = ((end - start) >> 1) + start;//����һλ���ڳ���2
		int count = countRange(numbers, length, start, middle);//ͳ�����
		if (end == start){    //��β��ȣ���Ҫ��֤��������1
			if (count > 1){
				return start;
			}
			else{
				break;
			}
		}
		if (count > (middle - start + 1)){  //�������ڼ��һ�εĴ�С
			end = middle;
		}
		else{
			start = middle + 1;
		}
	}
	return -1;
}
int countRange(const int *numbers, int length, int start, int end){
	if (numbers == nullptr){
		return 0;
	}
	int count = 0;
	for (int i = 0; i < length; ++i){//�������飬���ÿһ�ε�����
		if (numbers[i] >= start&&numbers[i] <= end){
			++count;
		}
	}
	return count;
}