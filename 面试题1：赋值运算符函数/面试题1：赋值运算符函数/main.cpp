//题目：如下类型CMyString的声明，请为该类型添加赋值运算符函数
#include <iostream>
using namespace std;

class CMyString
{
public:
	CMyString(char *pData = nullptr); 
	CMyString(const CMyString &str);
	~CMyString(void);
private:
	char* m_pData;
};

///关注点1：是否把返回值的类型声明为该类型的引用，并在函数结束前返回实例自身的引用（*this）。
///只有返回一个引用才能连续赋值
///关注点2：是否把传入的参数的类型声明为常量引用。如果传入的参数不是引用而是实例，
///那么从形参到实参会调用一次复制构造函数,因此应该为传入的引用参数加上const关键字。
///关注点3：是否释放自身已有的内存。内存泄漏。
///关注点4：判断传入的参数和当前的实例（*this）是不是同一个实例。
///如果是同一个，则不需要进行赋值操作，直接返回。


//解法1：初级解法
CMyString &CMyString::operator=(const CMyString &str)  //关注点1和2，函数返回引用和传入参数是常量 const
{ 
	if (this == &str){    //关注点4--判断是否相同
		return *this;
	}

	delete[]m_pData;     //关注点3--先删除释放空间，再使用重新分配
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);

	return *this;
}

//解法2：高级解法   解法1在分配内存之前先用delete释放了实例m_pData的内存。
//如果此时内存不足导致new char抛出异常，则m_pData将是一个空指针，导致程序崩溃。

//解决思路：先用new分配新内容，再用delete释放已有内容
CMyString &CMyString::operator=(const CMyString &str)
{
	if (this != &str){
		CMyString strTemp(str);  //创建临时实例
		
		char *pTemp = strTemp.m_pData; 
		strTemp.m_pData = m_pData; //strTemp.m_pData和实例自身的m_pData进行交换
		m_pData = pTemp;
	}
	//strTemp是一个局部变量，if外面出了变量作用域，strTemp.m_pData所指向的内存释放掉
	return *this;
}
