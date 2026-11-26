#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
struct ListNode
{
    int val;
    struct ListNode* next;
};
//力扣203 移除链表元素
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* cur = head;
//	struct ListNode* prev = NULL;
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			if (cur == head)
//			{
//				head = cur->next;
//				free(cur);
//				cur = head;
//			}
//			else
//			{
//				prev->next = cur->next;
//				free(cur);
//				cur = prev->next;
//			}
//		}
//		else //迭代往后走
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//	return head;
//}
//int main()
//{
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n1 != NULL);
//	assert(n2 != NULL);
//	assert(n3 != NULL);
//	assert(n4 != NULL);
//	assert(n5 != NULL);
//	n1->val = 1; n2->val = 2; n3->val = 3; n4->val = 2; n5->val = 4;
//	n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5; n5->next = NULL;
//	removeElements(n1, 2);
//	struct ListNode* cur = n1;
//	while (cur != NULL)
//	{
//		printf("%d->", cur->val);
//		cur = cur->next;
//	}
//	printf("NULL");
//	printf("\n");
//	return 0;
//}

//力扣206 翻转链表
// 1.迭代
//struct ListNode* reverseList(struct ListNode* head)
//{
//    if (head == NULL)
//    {
//        return NULL;
//    }
//    struct ListNode* n1, * n2, * n3;
//    n1 = NULL;
//    n2 = head;
//    n3 = head->next;
//    while (n2 != NULL)
//    {
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//        if (n3 != NULL)
//        {
//            n3 = n3->next;
//        }
//
//    }
//    return n1;
//}
//2.头插
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* cur = head;
//    struct ListNode* newhead = NULL;
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//        cur->next = newhead;
//        newhead = cur;
//        cur = next;
//    }
//    return newhead;
//}
//int main()
//{
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n1 != NULL);
//	assert(n2 != NULL);
//	assert(n3 != NULL);
//	assert(n4 != NULL);
//	assert(n5 != NULL);
//	n1->val = 1; n2->val = 2; n3->val = 3; n4->val = 4; n5->val = 5;
//	n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5; n5->next = NULL;
//	
//	struct ListNode* cur = reverseList(n1);
//	while (cur != NULL)
//	{
//		printf("%d->", cur->val);
//		cur = cur->next;
//	}
//	printf("NULL");
//	printf("\n");
//	return 0;
//}

//力扣876 链表中间节点
// slow fast 从头走，fast一次走两步，slow一次走一步，奇数个节点时：fast->next为NULL 偶数个节点：fast为空
//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* slow, * fast;
//    slow = head;
//    fast = head;
//    while (fast != NULL && fast->next != NULL)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}
//int main()
//{
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	assert(n1 != NULL);
//	assert(n2 != NULL);
//	assert(n3 != NULL);
//	assert(n4 != NULL);
//	assert(n5 != NULL);
//	n1->val = 1; n2->val = 2; n3->val = 3; n4->val = 4; n5->val = 5;
//	n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5; n5->next = NULL;
//	struct ListNode* end = middleNode(n1);
//	printf("%d->", end->val);
//	return 0;
//}

//力扣 剑指 Offer 22. 链表中倒数第k个节点
// fast先走k步，slow和fast一起走 当fast为NULL时，结束  return slow
//struct ListNode* getKthFromEnd(struct ListNode* head, int k)
//{
//    struct ListNode* slow, * fast;
//    slow = head;
//    fast = head;
//    int i = 1;
//    while (i <= k)
//    {
//        fast = fast->next;
//        i++;
//    }
//    while (fast != NULL)
//    {
//        slow = slow->next;
//        fast = fast->next;
//    }
//    return slow;
//}
//int main()
//{
//    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    assert(n1 != NULL);
//    assert(n2 != NULL);
//    assert(n3 != NULL);
//    assert(n4 != NULL);
//    assert(n5 != NULL);
//    int k = 0; scanf("%d", &k);
//    n1->val = 1; n2->val = 2; n3->val = 3; n4->val = 4; n5->val = 5;
//    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5; n5->next = NULL;
//    struct ListNode* middleK = getKthFromEnd(n1,k);
//    printf("%d->", middleK->val);
//    return 0;
//}

//面试题 02.04. 分割链表
//struct ListNode* partition(struct ListNode* head, int x)
//{
//    struct ListNode* lesshead, * lesstail, * greathead, * greattail;
//    //开哨兵位
//    lesshead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode));
//    lesshead->next = NULL;
//    greathead = greattail = (struct ListNode*)malloc(sizeof(struct ListNode));
//    greathead->next = NULL;
//
//    struct ListNode* cur = head;
//    while (cur != NULL)
//    {
//        if (cur->val < x)
//        {
//            lesstail->next = cur;
//            lesstail = cur;
//        }
//        else
//        {
//            greattail->next = cur;
//            greattail = cur;
//
//        }
//        cur = cur->next;
//    }
//    lesstail->next = greathead->next;
//    greattail->next = NULL;
//    struct ListNode* newnode = lesshead->next;
//    free(lesshead);
//    free(greathead);
//    return newnode;
//}

//面试题 02.06. 回文链表
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* cur = head;
//    struct ListNode* newhead = NULL;
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//        cur->next = newhead;
//        newhead = cur;
//        cur = next;
//    }
//    return newhead;
//}
//
//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* slow, * fast;
//    slow = head;
//    fast = head;
//    while (fast != NULL && fast->next != NULL)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}
//
//bool isPalindrome(struct ListNode* head)
//{
//    struct ListNode* mid = middleNode(head);
//    struct ListNode* rhead = reverseList(mid);
//    struct ListNode* curA = head;
//    struct ListNode* curR = rhead;
//    while (curA && curR)
//    {
//        if (curA->val != curR->val)
//        {
//            return false;
//        }
//        else
//        {
//            curA = curA->next;
//            curR = curR->next;
//        }
//    }
//    return true;
//}

//160. 相交链表
//1.穷举  A链表所有节点去和B链表比较，有地址相同的，第一个相同的就是交点  O(n^2)
//2.尾节点相同就是相交  长链表先走长度差步，再一起走，第一个相同的就是交点
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//    struct ListNode* tailA = headA;
//    struct ListNode* tailB = headB;
//    int cntA = 0; int cntB = 0;
//    while (tailA->next != NULL)
//    {
//        tailA = tailA->next;
//        cntA++;
//    }
//    while (tailB->next != NULL)
//    {
//        tailB = tailB->next;
//        cntB++;
//    }
//    if (tailA != tailB)
//    {//不相交
//        return NULL;
//    }
//    int gap = abs(cntA - cntB); //长度差
//    //长的先走长度差步，再一起走
//    struct ListNode* longlist = headA;
//    struct ListNode* shortlist = headB;
//    if (cntA < cntB)
//    {
//        shortlist = headA;
//        longlist = headB;
//    }
//    //长的先走
//    while (gap--)
//    {
//        longlist = longlist->next;
//    }
//    //同时走
//    while (longlist != shortlist)
//    {
//        longlist = longlist->next;
//        shortlist = shortlist->next;
//    }
//    return shortlist;
//}

//141. 环形链表
//slow和fast指向链表的开始，slow一次一步，fast一次两步，不带环，fast会为空，带环,fast会在环内追上slow
//bool hasCycle(struct ListNode* head)
//{
//    struct ListNode* slow = head, * fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (slow == fast)
//        {
//            return true;
//        }
//    }
//    return false;
//}
//延伸问题：
//1.为什么slow和fast绝对会相遇，证明        --- 一定会相遇
//2.为什么fast一次走2步，slow一次走1步。fast一次能不能走多步    --- 走n步，如果n>2不一定相遇
//答：fast 先进环 slow走了进环距离的一半        slow进环 fast在环里面走了一段距离
//    假设slow进环，fast追上slow的距离是n. fast一次2步 slow一次1步，每次都比较
//    每追一次 fast和slow距离变化缩短一步 n-1 n-2 ……。当距离为0就可以相遇
//    slow 1 fast 3，距离变化 n-2 n-4 ……  
//    n为偶数，可以追到 如果n为奇数，一次追不到，距离差-1 还要追C-1步，C为环的长度 如果C-1（n）奇数，追不到
// 

//142 环形链表开始点
//slow一次一步，fast一次两步，一定会相遇，怎么求环的开始点
//答：一个指针从头走 一个指针从相遇点走 一定会在环的入口相遇
//假设head到入口的距离为L 入口到sf相遇点的距离为X 环长度为C
//slow走了 L+X，fast走了L+X+n*C n为fast在环内走的圈数
//2(L+X)=L+x+n*C 则 L=n*C-X   L=(n-1)*C+C-X
// 
//struct ListNode* detectCycle(struct ListNode* head)
//{
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (slow == fast)
//        {
//            //相遇点
//            struct ListNode* meetnode = slow;
//            while (meetnode != head)
//            {
//                meetnode = meetnode->next;
//                head = head->next;
//            }
//            return meetnode;
//        }
//    }
//    return NULL;
//}
