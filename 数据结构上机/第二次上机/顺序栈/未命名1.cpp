/*课后习题1.8-h

	h.	假设表达式中允许包含3中括号：圆括号、方括号和大括号。
		设计一个算法采用顺序栈判断表达式中的括号是否正确配对。
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
TODO:计一个算法采用顺序栈判断表达式c中的括号是否正确配对。
返回值说明:返回长度为3个字符的字符串，
第1个字符表示()的匹配情况。
第2个字符表示[]的匹配情况
第3个字符表示{}的匹配情况。
如果匹配，则对应的字符设置为'1'，否则设置为'0'。
比如：返回值为"110",表示：()匹配，[]匹配，{}不匹配
 */
char t[]="111" ;
void Bracketmatch(const char* c) //括号匹配
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
            cout << "()匹配" << endl;
        } else {
            cout << "()不匹配" << endl;
        }

        if (p[1] == '1') {
            cout << "[]匹配" << endl;
        } else {
            cout << "[]不匹配" << endl;
        }

        if (p[2] == '1') {
            cout << "{}匹配" << endl;
        } else {
            cout << "{}不匹配" << endl;
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

