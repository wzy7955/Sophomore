/*�κ�ϰ��1.8-h

	h.	������ʽ���������3�����ţ�Բ���š������źʹ����š�
		���һ���㷨����˳��ջ�жϱ��ʽ�е������Ƿ���ȷ��ԡ�
		void Bracketmatch(const char* c)

*/
#include <cstring>
#include <iostream>

using namespace std;
class stack {
private:
    int maxsize;
    int top;
    char* st;

public:
    stack(int size)
    {
        maxsize = size;
        top = -1;
        st = new char[maxsize];
    }

    void push(char item)
    {
        st[++top] = item;
    }

    void pop()
    {
        top--;
    }

    bool empty()
    {
        return top == -1;
    }
};
/*
TODO:��һ���㷨����˳��ջ�жϱ��ʽc�е������Ƿ���ȷ��ԡ�
����ֵ˵��:���س���Ϊ3���ַ����ַ�����
��1���ַ���ʾ()��ƥ�������
��2���ַ���ʾ[]��ƥ�����
��3���ַ���ʾ{}��ƥ�������
���ƥ�䣬���Ӧ���ַ�����Ϊ'1'����������Ϊ'0'��
���磺����ֵΪ"110",��ʾ��()ƥ�䣬[]ƥ�䣬{}��ƥ��
 */
char t[]="111" ;
void Bracketmatch(const char* c) //����ƥ��
{
	t[0]='1';
	t[1]='1';
	t[2]='1';
	stack x(1000),y(1000),z(1000);
	for(;*c!='\0';c++)
	{
		if(*c=='{')
		x.push('1');
		if(*c=='[')
		y.push('1');
		if(*c=='(')
		z.push('1');
		if(*c=='}')
		{
			if(x.empty())
			t[2]='0';
			else
			x.pop();
		}
		if(*c==']')
		{
			if(y.empty())
			t[1]='0';
			else
			y.pop();
		}
		if(*c==')')
		{
			if(z.empty())
			t[0]='0';
			else
			z.pop();
		}
	}
		if(!x.empty())
		t[2]='0';
		if(!y.empty())
		t[1]='0';
		if(!z.empty())
		t[0]='0';

		
	
}
void printResult(char* p)
{
    if (NULL != p && strlen(p) == 3) {
        if (p[0] == '1') {
            cout << "()ƥ��" << endl;
        } else {
            cout << "()��ƥ��" << endl;
        }

        if (p[1] == '1') {
            cout << "[]ƥ��" << endl;
        } else {
            cout << "[]��ƥ��" << endl;
        }

        if (p[2] == '1') {
            cout << "{}ƥ��" << endl;
        } else {
            cout << "{}��ƥ��" << endl;
        }
    }
}
int main()
{

    string s;
    getline(cin, s);
    cout << s << endl;
    Bracketmatch(s.c_str());
    printResult(t);

    return 0;
}

