//题目二：不修改数组找出重复的数字。
//在一个长度为n+1的数组里的所有数字都在1~n的范围内，
//所以数组中至少有一个数字是重复的。请找出数组中任意一个重复的数字，
//但不能修改输入的数组。例如，如果输入长度8的数组{2,3,5,4,3,2,6,7}，
//那么对应的输出是重复的数字2或者3。

int getDuplication(const int *numbers, int length){
	//类似二分查找思路，将数组长度区间一份为二，统计两段中每一段数字出现次数，看一半元素多，再进行二分
	if (numbers == nullptr || length <= 0){
		return -1;
	}
	int start = 1;
	int end = length - 1;
	while (end >= start){
		int middle = ((end - start) >> 1) + start;//右移一位等于除以2
		int count = countRange(numbers, length, start, middle);//统计这个
		if (end == start){    //首尾相等，需要验证次数大于1
			if (count > 1){
				return start;
			}
			else{
				break;
			}
		}
		if (count > (middle - start + 1)){  //数量大于检测一段的大小
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
	for (int i = 0; i < length; ++i){//遍历数组，检测每一段的数量
		if (numbers[i] >= start&&numbers[i] <= end){
			++count;
		}
	}
	return count;
}