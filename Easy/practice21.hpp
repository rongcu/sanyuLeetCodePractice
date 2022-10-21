/*******************************************************************************
 * @Author       : tuhuilin
 * @Date         : 2022-10-21 16:21:08
 * @Description  :
 * @Copyright (c) 2022 zyyt, All Rights Reserved.
 *******************************************************************************/
/*******************************************************************************
 * @Author       : tuhuilin
 * @Date         : 2022-10-21 16:21:08
 * @Description  : 合并两个有序列表
 * @Copyright (c) 2022 zyyt, All Rights Reserved.
 *******************************************************************************/
//写之前的疑惑与了解
/*1.在C++中，链表使用什么来表示     
	用链表结构体
2.升序链表中排序方法是什么？它是如何实现的，既然有升序，是不是有降序和乱序？
	用比大小实现的升序
3.两个链表合并的时候相同的数不被删除，这样的是什么实现方法？删除的又是什么实现方法？
4.如果遇到了两个相同的数，哪个数在前？哪个数在后？这次easy的题目好像不用关心这个，但是关心的话又可以怎么实现自己的想法呢？

关于链表
：依据数据结构这课得到的知识可知，链表是由指针串联起来的，它并不是一个完整的数据块，
单向链表：只能指向前，不能返回后
双向链表：前后都能指向
环形链表：类似一个圈，可以从头指到尾*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//定义一个链表结构体
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
	//传入的是一个链表结构体指针，返回的也是，相当于指向下一个的位置
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
	{
		//第一步：判断是否是空链表，在递归算法中，也可判断链表是否走到头了，链表走到头了其实和空链表是一样的
		//前面这两个判断互相指，可以保证一定能走完两个链表
		if (l1 == nullptr)
		{
			return l2;
		}
		else if (l2 == nullptr)
		{
			return l1;
		}
		else if (l1->val < l2->val)
		{
			l1->next = mergeTwoLists(l1->next, l2);		//递归算法，函数里再调用此函数
			return l1;
		}
		else
		{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};
