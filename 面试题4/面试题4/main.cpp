//面试题4：二维数组中的查找
//在一个二维数组中，每一行都按照从左到右递增的顺序排序，
//每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样
//的一个二维数组和一个整数，判断数组中是否含有该整数

#include <iostream>
using namespace std;
//思路：每次选择右上（或者左下）进行区域删除

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
			else if (matrix[row*columns + column]>number){  //右上数字大于目标数字---删除列
				--column;
			}
			else{  //右上数字小于目标数字---删除行  （行+1）
				++row;
			}
		}
	}
	return found;
}