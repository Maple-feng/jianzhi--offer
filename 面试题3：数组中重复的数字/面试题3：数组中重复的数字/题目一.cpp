//题目一：找出数组中重复的数字
//在一个长度为n的数组里的所有数字都在0~n-1的范围内。
//数组中某些数字是重复的，但不知道有几个数字是重复了，
//也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
//例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是重复的数字2或者3

#include <iostream>
using namespace std;
bool duplicate(int numbers[], int length, int *duplication){
	if (numbers == nullptr || length <= 0){
		return false;

	}
	for (int i = 0; i < length; ++i){
		if (numbers[i]< 0 || numbers[i]>length - 1){ //目标不能为负或大于数组长度
			return false;
		}
	}
	for (int i = 0; i < length; ++i){
		while (numbers[i] != i){//目标与下标不相等交换
			if (numbers[i] == numbers[numbers[i]]){//同时比较目标下标是否相等
				*duplication = numbers[i];
				return true;
			}
			//swap numbers[i] and numbers[numbers[i]] //交换
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
}