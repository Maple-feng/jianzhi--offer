//面试题2：单例模式
//要求：在内存中只能创建一个对象
//1.不能是栈对象-->将构造函数放在private
//2.不能是全局对象
//3.只能是堆对象-->定义一个static的成员函数，通过它来创建堆对象
//4.需要一个static数据成员，来保存已经创建好的对象的首地址
//5.每一次调用getInstance()成员函数都返回该static数据成员

#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
	static Singleton * getInstance(){
		if (_pInstance == NULL){
			_pInstance = new Singleton;
		}
		return _pInstance;
	}
	static void destroy(){
		delete _pInstance;
	}
	void print(){
		cout << "Singleton::print()" << endl;
	}
private:
	Singleton(){
		cout << "Singleton()" << endl;
	}
	~Singleton(){
		cout << "~Singleton()" << endl;
	}
private:
	static Singleton * _pInstance;
};