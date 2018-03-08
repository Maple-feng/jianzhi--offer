//面试题6：从尾到头打印链表
//题目：输入一个链表的头结点，从尾到头反过来打印出每个节点的值。

#include <iostream>
#include <stack>
using namespace std;
//链表节点定义如下：
struct ListNode{
	int m_nValue;
	ListNode *m_pNext;
};

//解法一：放入栈中
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

//解法二：递归--每次先输出后面的节点（函数调用层级深，容易导致函数调用栈溢出）
void PrintListReversingly_Recursively(ListNode *pHead){
	if (pHead != nullptr){
		if (pHead->m_pNext != nullptr){
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
		printf("%d\t", pHead->m_nValue);
	}
}