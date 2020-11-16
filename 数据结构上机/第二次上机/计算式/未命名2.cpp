/**1.4-d,e ����������׺���ʽת��Ϊ��׺��������

	void infix_to_suffix();   //1.4-e  ����׺���ʽת��Ϊ��׺���
	void cal_suffix();        //1.4-d.	������׺���ʽ��ֵ

**/
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

template <class T>
class stack {
private:
    int top; //ջ��
    int maxtop; //����ջ��ֵ
    T* st; //��ջԪ������
public:
    stack(int maxstacksize = 10)
    {
        maxtop = maxstacksize - 1;
        st = new T[maxstacksize];
        top = -1;
    }
    ~stack()
    {
        delete[] st;
    }
    bool isfull()
    {
        return top == maxtop;
    }
    bool isempty()
    {
        return top == -1;
    }
    bool add(const T& x)
    {
        if (isfull()) {
            cout << "no memory" << endl;
            return false;
        }
        top++;
        st[top] = x;
        return true;
    }
    T del()
    {
        if (isempty()) {
            cerr << "no element" << endl;
        }
        T x;
        x = st[top];
        top--;
        return x;
    }
    T returntop()
    {
        return st[top];
    }
    void clear()
    {
        top = -1;
    }
    void output()
    {
        if (isempty()) {
            cout << "ջ�ǿյ�" << endl;
        } else {
            for (int i = 0; i <= top; i++) {
                cout << st[i] << '\t';
            }
            cout << endl;
        }
    }
};

class Calculator {
public:
    string infix; //��׺���ʽ
    string postfix; //��׺���ʽ
    stack<double> poststack; //��׺ջ
    Calculator(string str);
    ~Calculator()
    {
        poststack.clear();
    }
    void infix_to_suffix(); //1.4-e  ����׺���ʽת��Ϊ��׺���
    int inStack(char ch); //ջ�����ȼ�
    int outStack(char ch); //ջ�����ȼ���
    void cal_suffix(); //1.4-d.	������׺���ʽ��ֵ
    void print();
    bool Get_operands(double& left, double& right);
    bool isNumber(char ch);   //�ж��Ƿ���һ���� 
    double returnnum(char* c, int n); //�����ַ���Ӧ����
    float toNum(char num_ch); //��ֵ���ַ�ת��������
    void cal(char ch); //���ݲ����� ȥջ��ȥȡ����Ԫ�ؼ���
};
Calculator::Calculator(string str)
{
    infix = str;
}

/*
TODO:1.4-e  ����׺���ʽת��Ϊ��׺���,������׺���ʽΪ1+(2-3)*4+4/2��
��ת����Ϊ��1&2&3&-4&*+4&2&/+ [Ϊ���������������֣���&���Ž����ֽ��и�������ȻҲ������ѡ��������ʽ�����]
 */
void Calculator::infix_to_suffix()
{
	postfix="";
	int j=0;
	for(int i=0;i<infix.length();i++)
	{
		if(isNumber(infix[i]))
		{
			postfix+=infix[i];	
			postfix+='&';
			
		}
		else
		{
			int x=outStack(infix[i]);  //����ջ������ֵ 
			if(poststack.isempty())
			{
				poststack.add(infix[i]);
			}
			else
			{
				char t=poststack.returntop();
				if(inStack(t)<x)
				{
					poststack.add(infix[i]);
				}
				else if(inStack(t)>x)
				{
					postfix+=poststack.del();
					i--;
				}
				else
				{
					poststack.del();
				}
			}
			
		}
	}
		while(!poststack.isempty())
		{
				postfix+=poststack.del();
				
		
		}
}

/*
TODO: 1.4-d.������׺���ʽ��ֵ�����磺������׺���ʽΪ1+(2-3)*4+4/2��������������������ȼ����㣬���Ľ��Ϊ-1.
����������׺���ʽ�Ƿ������ӡcout << "�������� �������ʽ�ĺϷ���" << endl;��Ȼ��exit(0)����ִ�С�
                                         1&2&3&-4&*+4&2&/+*/
void Calculator::cal_suffix()
{
    infix_to_suffix(); //����׺���ʽת��Ϊ��׺���ʽ
	poststack.clear();
	for(int i=0;i<postfix.length();i++)
	{
		if(isNumber(postfix[i])&&postfix[i+1]=='&')
			{
			double a=toNum(postfix[i]); 
			poststack.add(a);
			}
		if(!isNumber(postfix[i])&&postfix[i]!='&')
			{
				if(poststack.isempty())
				{
					cout << "�������� �������ʽ�ĺϷ���" << endl;
					exit(0);
				}
				cal(postfix[i]);
			}
	}
/*	for(int i=0;i<postfix.length();i++)
	{
/*		if(poststack.isempty())
		{
			cout << "�������� �������ʽ�ĺϷ���" << endl;
			exit(0);
		}
		if(!isNumber(postfix[i])&&postfix[i]!='&')
		
			
	}*/
				
}    
    


bool Calculator::Get_operands(double& left, double& right)
{
    if (poststack.isempty()) {
        cout << "ȱ���Ҳ�����" << endl;
        return false;
    }
    right = poststack.del(); //ȡ�Ҳ�����
    if (poststack.isempty()) {
        cout << "ȱ���������" << endl;
        return false;
    }
    left = poststack.del(); //ȡ���������
    return true; //����true
}
double Calculator::returnnum(char* c, int n) //�����ַ���Ӧ����,n��ʾ��ʮ��ǧλ
{
    int l = n;
    double num = 0;
    double m = 1;
    for (int i = l - 1; i >= 0; i--) {
        num += toNum(c[i]) * m;
        m *= 10;
    }
    return num;
}

int Calculator::inStack(char c)
{
    switch (c) {
    case '#':
        return 0;
        break;
    case '(':
        return 1;
        break;
    case '*':
    case '/':
    case '%':
        return 5;
        break;
    case '+':
    case '-':
        return 3;
        break;
    case ')':
        return 6;
        break;
    }
}
//���ز�������ջ�����ȼ�
int Calculator::outStack(char c)
{
    switch (c) {
    case '#':
        return 0;
        break;
    case '(':
        return 6;
        break;
    case '*':
    case '/':
    case '%':
        return 4;
        break;
    case '+':
    case '-':
        return 2;
        break;
    case ')':
        return 1;
        break;
    }
}
//�ж��Ƿ�Ϊ������
bool Calculator::isNumber(char ch)
{
    if (48 <= ch && ch <= 57)
        return true;
    else
        return false;
}

//��ֵ���ַ�ת��Ϊ����
float Calculator::toNum(char num_ch)
{
    switch (num_ch) {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    }
}
//���ݲ����� ȥջ��ȥȡ����Ԫ�ؼ���
void Calculator::cal(char cp)
{
    double left, right, value;
    if (Get_operands(left, right)) {
        switch (cp) {
        case '+': {
            value = left + right;
            poststack.add(value); //��Ӻ���ѹջ
            break;
        }
        case '-': {
            value = left - right;
            poststack.add(value); //��� ѹջ
            break;
        }
        case '*': {
            value = left * right;
            poststack.add(value); //��� ѹջ
            break;
        }
        case '/':
            if (right == 0) {
                cout << "/ ������ �Ҳ�����Ϊ0" << endl;
                exit(1);
            } else {
                value = left / right;
                poststack.add(value); //��� ѹջ
            }
            break;
        }
    }
}
//��������������
void Calculator::print()
{
    cout << "���ʽ������:" << endl;
    cout << poststack.returntop() << endl;
}
int main()
{
    string str;
    cout << "����һ����׺���ʽ��" << endl;
    cin >> str;
    Calculator calculator(str);
    calculator.cal_suffix();
    calculator.print(); //��ʾ���
    return 0;
}

