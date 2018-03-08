//������6����β��ͷ��ӡ����
//��Ŀ������һ�������ͷ��㣬��β��ͷ��������ӡ��ÿ���ڵ��ֵ��

#include <iostream>
#include <stack>
using namespace std;
//����ڵ㶨�����£�
struct ListNode{
	int m_nValue;
	ListNode *m_pNext;
};

//�ⷨһ������ջ��
void PrintListReversingly_iteratively(ListNode *pHead){
	std::stack<ListNode*> nodes;
	ListNode *pNode = pHead;
	while (pNode != nullptr){
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	while (!nodes.empty()){
		pNode = nodes.top();
		printf("%d\t", pNode->m_nValue);
		nodes.pop();
	}
}

//�ⷨ�����ݹ�--ÿ�����������Ľڵ㣨�������ò㼶����׵��º�������ջ�����
void PrintListReversingly_Recursively(ListNode *pHead){
	if (pHead != nullptr){
		if (pHead->m_pNext != nullptr){
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
		printf("%d\t", pHead->m_nValue);
	}
}