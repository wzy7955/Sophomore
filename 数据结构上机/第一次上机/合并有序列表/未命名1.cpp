/*课后习题1.8-d

	d.	设ha和hb分别是两个带头结点的非递减有序单链表的表头指针，试设计一个算法，
		将这两个有序链表合并成一个非递减有序的单链表。要求结果链表仍使用原来两个链表的存储空间，
		不另外占用其他的存储空间。表中允许有重复的数据。

		Node* Merge(Node* a, Node* b)

*/
#include <iostream>
using namespace std;
const int MinNumber = -1000000;
struct Node {
    Node(int x)
    {
        value = x;
        next = NULL;
    }
    int value;
    Node* next;
};

/*
TODO:链表连接,将链表a和链表b进行连接合并，连接合并后结果链表仍使用原来两个链表的存储空间，
不另外占用其他的存储空间，且合并后的是一个非递减有序的单链表。
返回值说明：返回合并后的非递减有序单链表
*/
Node* Merge(Node* a, Node* b)
{
	Node* New = NULL;//合并后的链表
	Node* tail = NULL;//标记合并后链表的尾部，方便尾插
	Node* cur1 = a;
	Node* cur2 = b;
	Node* nxt = NULL;//用来保存链表的后续节点

	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->value <= cur2->value)
		{
			nxt = cur1->next;
		
			if (New == NULL)
			{	
				New = cur1;
			}
			else
			{
				tail->next = cur1;
			}
			cur1->next = NULL;//为了不占用别的内存 
			tail = cur1;
			cur1 = nxt;
		}
		else
		{
			nxt = cur2->next;
			if (New == NULL)
			{
				New = cur2;
			}
			else
			{
				tail->next = cur2;
			}
			cur2->next = NULL;
			tail = cur2;
			cur2 = nxt;
		}
	}
	if (cur1 == NULL)
	{
		tail->next = cur2;
	}
	if (cur2 == NULL)
	{
		tail->next = cur1;
	}
	return New;
}

void print(Node* pNode)
{
    while (pNode != NULL) {
        cout << pNode->value << " ";
        pNode = pNode->next;
    }
    cout << endl;
}

Node* init()
{
    int count;
    cin >> count;
    Node *p = NULL, *q;
    for (int i = 0; i < count; i++) {
        int iValue;
        cin >> iValue;
        if (NULL == p) {
            p = new Node(iValue);
            q = p;
        } else {
            q->next = new Node(iValue);
            q = q->next;
        }
    }
    return p;
}

int main()
{
    Node* ha = init();
    Node* hb = init();
    cout << "合并前链表1为:";
    print(ha);
    cout << "合并前链表2为:";
    print(hb);
    Node* head = Merge(ha, hb);
    cout << "合并后的单链表为:";
    print(head);
    return 0;
}


