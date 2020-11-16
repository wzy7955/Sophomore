/*�κ�ϰ��1.8-b
	b.	����һ������ͷ���ĵ�����д���������õ��㷨
		Node* Reverse(Node* first)
*/
#include <iostream>
using namespace std;
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
TODO:�����õ��㷨
 */
Node* Reverse(Node* first)
{
	if( !first || !(first->next) )
		return first;
		
	Node *q = NULL, *p = first;
	while( first )
		{
			p = first->next;
			first->next = q;
			q = first;
			first = p;
		}
	return q;
}
void print(Node* node)
{
    while (NULL != node) {
        cout << node->value << " ";
        node = node->next;
    }
}
int main()
{
    int iNum;
    cin >> iNum;
    Node* a = NULL;
    Node* pTemp;

    for (int i = 0; i < iNum; i++) {
        int tmp;
        cin >> tmp;
        if (i == 0) {
            a = new Node(tmp);
            pTemp = a;
        } else {
            pTemp->next = new Node(tmp);
            pTemp = pTemp->next;
        }
    }

    cout << "����ǰΪ��";
    print(a);
    cout << endl;
    Node* r = Reverse(a);
    cout << "���ú�Ϊ��";
    print(r);
    cout << endl;
    return 0;
}

