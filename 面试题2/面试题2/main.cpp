//������2������ģʽ
//Ҫ�����ڴ���ֻ�ܴ���һ������
//1.������ջ����-->�����캯������private
//2.������ȫ�ֶ���
//3.ֻ���ǶѶ���-->����һ��static�ĳ�Ա������ͨ�����������Ѷ���
//4.��Ҫһ��static���ݳ�Ա���������Ѿ������õĶ�����׵�ַ
//5.ÿһ�ε���getInstance()��Ա���������ظ�static���ݳ�Ա

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