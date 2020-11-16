/*1.3 ˳��ջ

	bool Push(const T item)		//1.3-a. ��ջ���������ж�ջ�Ƿ�Ϊ��	
	bool Pop(T& item)			//1.3-b ��ջ���������ж�ջ�Ƿ�Ϊ�գ�����ջ��Ԫ��	
	bool Top(T& item)			//1.3-c ��ȡջ��Ԫ�أ�����ɾ�����ж�ջ�Ƿ�Ϊ��

*/
#include <iostream>
using namespace std;

template <class T>
class Stack {
public:
    void Clear();
    bool Push(const T item);
    bool Pop(T& item);
    bool Top(T& item);
    bool IsEmpty(); 
    bool IsFull;
};

template <class T>
class ArrayStack : public Stack<T> {
public:
    ArrayStack(int size)
    {
        maxSize = size;
        top = -1;
        st = new T[maxSize];
    }
    ArrayStack()
    {
        top = -1;
    }
    ~ArrayStack()
    {
        delete[] st;
    }
    void Clear()
    {
        top = -1;
    }
    /*
	TODO:1.3-a. ��ջ���������ж�ջ�Ƿ�Ϊ��,��ջ���������ӡcout << "ջ�����" << endl;����false������item��ջ������true
	����ֵ˵�����ɹ���ջ������true�����򷵻�false��
	 */
    bool Push(const T item)
    {
    	if(top == maxSize-1)
			{
				cout << "ջ�����" << endl;
				return false;
			 } 
		else
		{
			st[++top] = item;
			return true;
		}
    }
    /*
	TODO:1.3-b ��ջ���������ж�ջ�Ƿ�Ϊ�գ���Ϊ�գ����ӡcout << "ջΪ�գ����ܽ���ɾ������" << endl;����false��
	���򣬽�ջ��Ԫ�ص�ֵȡ������ֵ��item�����г�ջ����������true
	����ֵ˵���������ջ�ɹ�������true�����򷵻�false��
	 */
    bool Pop(T& item)
    {
    	if(top == -1)
			{
				cout << "ջΪ�գ����ܽ���ɾ������" << endl;
				return false;
			 } 
		else
		{
			item = st[top];
			top--;
			return true;
		}
    }
    /*
	TODO:1.3-c ��ȡջ��Ԫ�أ�����ɾ�����ж�ջ�Ƿ�Ϊ��,��Ϊ�գ����ӡcout << "ջΪ�գ����ܶ�ȡջ��Ԫ��" << endl;����false
	���򣬽�ջ��Ԫ��ȡ��������ֵ��item������true��
	����ֵ˵�����ɹ���ȡջ��Ԫ�أ�����true�����򷵻�false��
	 */
    bool Top(T& item)
    {
		if(top == -1)
			{
				cout << "ջΪ�գ����ܶ�ȡջ��Ԫ��" << endl;
				return false;
			 } 
		else
		{
			item = st[top];
			return true;
		}
    }
    	
    

private:
    int maxSize; //ջ����ౣ���Ԫ�ظ���
    int top; //ָ��ջ������ʼ��Ϊ-1����ջʱtop+1����ջʱtop-1
    T* st; //ջ
};

int main()
{
    int maxsize, loop_num, temp;
    cin >> maxsize >> loop_num >> temp;

    ArrayStack<int> as(maxsize);
    for (int i = 1; i < loop_num; i++) {
        as.Push(i);
    }
    as.Push(temp);
    cout << "��ջ��" << temp << endl;
    as.Pop(temp);
    cout << "��ջ:" << temp << endl;
    as.Top(temp);
    cout << "��ȡջ��Ԫ��:" << temp << endl;
    return 0;
}

