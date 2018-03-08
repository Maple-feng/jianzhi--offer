//��Ŀ����������CMyString����������Ϊ��������Ӹ�ֵ���������
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

///��ע��1���Ƿ�ѷ���ֵ����������Ϊ�����͵����ã����ں�������ǰ����ʵ����������ã�*this����
///ֻ�з���һ�����ò���������ֵ
///��ע��2���Ƿ�Ѵ���Ĳ�������������Ϊ�������á��������Ĳ����������ö���ʵ����
///��ô���βε�ʵ�λ����һ�θ��ƹ��캯��,���Ӧ��Ϊ��������ò�������const�ؼ��֡�
///��ע��3���Ƿ��ͷ��������е��ڴ档�ڴ�й©��
///��ע��4���жϴ���Ĳ����͵�ǰ��ʵ����*this���ǲ���ͬһ��ʵ����
///�����ͬһ��������Ҫ���и�ֵ������ֱ�ӷ��ء�


//�ⷨ1�������ⷨ
CMyString &CMyString::operator=(const CMyString &str)  //��ע��1��2�������������úʹ�������ǳ��� const
{ 
	if (this == &str){    //��ע��4--�ж��Ƿ���ͬ
		return *this;
	}

	delete[]m_pData;     //��ע��3--��ɾ���ͷſռ䣬��ʹ�����·���
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);

	return *this;
}

//�ⷨ2���߼��ⷨ   �ⷨ1�ڷ����ڴ�֮ǰ����delete�ͷ���ʵ��m_pData���ڴ档
//�����ʱ�ڴ治�㵼��new char�׳��쳣����m_pData����һ����ָ�룬���³��������

//���˼·������new���������ݣ�����delete�ͷ���������
CMyString &CMyString::operator=(const CMyString &str)
{
	if (this != &str){
		CMyString strTemp(str);  //������ʱʵ��
		
		char *pTemp = strTemp.m_pData; 
		strTemp.m_pData = m_pData; //strTemp.m_pData��ʵ�������m_pData���н���
		m_pData = pTemp;
	}
	//strTemp��һ���ֲ�������if������˱���������strTemp.m_pData��ָ����ڴ��ͷŵ�
	return *this;
}
