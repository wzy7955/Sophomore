/*2.4����
 *
 * void BuildHeap();	//2.4-a ���ѹ���
 * void SiftDown(int left);	//2.4-b SiftDown������left���µ����ѣ�ʹ���г�Ϊ��
 * void SiftUp(int pos);	//2.4-c SiftUp������position���ϵ����ѣ�ʹ���г�Ϊ��
 * bool Remove(int pos, T& node);	//2.4-d ɾ�������±��Ԫ��
 * bool Insert(const T& newNode);	//2.4-e �Ӷ��в�����Ԫ��newNode
 *
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
class MaxHeap {
private:
    T* heapArray;
    int CurrentSize; /* ��ǰ��Ԫ�ظ��� */
    int MaxSize; /* �����ܴ�ŵ����Ԫ�ظ��� */
public:
    MaxHeap(T* array, int num, int max)
    {
        this->heapArray = array;
        this->CurrentSize = num;
        this->MaxSize = max;
    }

    virtual ~MaxHeap(){};
    bool isLeaf(int pos) const;
    int leftchild(int pos) const;
    int rightchild(int pos) const;
    int parent(int pos) const;
    void BuildHeap(); /* 2.4-a ���ѹ��� */
    void SiftDown(int left); /* 2.4-b SiftDown������left���µ����ѣ�ʹ���г�Ϊ�� */
    void SiftUp(int pos); /* 2.4-c SiftUp������position���ϵ����ѣ�ʹ���г�Ϊ�� */
    bool Remove(int pos, T& node); /* 2.4-d ɾ�������±��Ԫ�� */
    bool Insert(const T& newNode); /* 2.4-e �Ӷ��в�����Ԫ��newNode */
    T& RemoveMax(); /* 2.4-f �ӶѶ�ɾ�����ֵ */
    void visit();
};

/*
 * TODO:2.4-a ���ѹ���
 */
template <class T>
void MaxHeap<T>::BuildHeap()
{
    for (int i = CurrentSize / 2 - 1; i >= 0; i--)
        SiftDown(i);
}

template <class T>
bool MaxHeap<T>::isLeaf(int pos) const
{
    if (pos >= CurrentSize) {
        cout << "Խ��" << endl;
        return (false);
    } else if (pos > (CurrentSize - 1) / 2)
        return (true);
    else
        return (false);
}

template <class T>
int MaxHeap<T>::leftchild(int pos) const
{
    return (2 * pos + 1);
}

template <class T>
int MaxHeap<T>::rightchild(int pos) const
{
    return (2 * pos + 2);
}

template <class T>
int MaxHeap<T>::parent(int pos) const
{
    return ((pos - 1) / 2);
}

/*
 * TODO:2.4-d ɾ�������±��Ԫ�أ�������Ԫ�ص�ֵ��ֵ��node������
 * ����ֵ˵�������ɾ���ɹ����򷵻�true�����򷵻�false
 * ��Ҫ˵���������ǰ��Ϊ�գ��������ӡcout << "�ն�" << endl;������false
 */
template <class T>
bool MaxHeap<T>::Remove(int pos, T& node)
{
    if (CurrentSize == 0) {
        cout << "�ն�" << endl;
        return (false);
    }
    node = heapArray[pos];
    heapArray[pos] = heapArray[CurrentSize - 1];
    CurrentSize--;
    if (CurrentSize > 1)
        SiftDown(pos);
    return (true);
}

/*
 * TODO:2.4 - b SiftDown������left���µ����ѣ�ʹ���г�Ϊ��
 */
template <class T>
void MaxHeap<T>::SiftDown(int left)
{
    int i = left;
    int j = 2 * i + 1;
    T temp = heapArray[i];
    while (j < CurrentSize) {
        if ((j < CurrentSize - 1) && (heapArray[j] < heapArray[j + 1]))
            j++;
        if (temp < heapArray[j]) {
            heapArray[i] = heapArray[j];
            i = j;
            j = 2 * i + 1;
        } else
            break;
    }
    heapArray[i] = temp;
}

/*
 * TODO:2.4-c SiftUp������pos���ϵ����ѣ�ʹ���г�Ϊ��
 */
template <class T>
void MaxHeap<T>::SiftUp(int pos)
{
    int i = pos; /* ��ǰ���pos */
    int j = (i - 1) / 2; /* pos�ĸ���� */
    T temp = heapArray[pos];

    while (j >= 0 && temp > heapArray[j]) {
        heapArray[i] = heapArray[j];
        i = j;
        if (j != 0)
            j = (i - 1) / 2;
        else
            j = -1;
    }
    heapArray[i] = temp;
}

/*
 * TODO:2.4-e �Ӷ��в�����Ԫ��newNode, �������ɹ�������true�����򷵻�false��
 * ��Ҫ˵�����������Ԫ�س�������Ԫ��������ֵ���������ӡcout << "����" << endl;������false
 */
template <class T>
bool MaxHeap<T>::Insert(const T& newNode)
{
    if (CurrentSize >= MaxSize) {
        cout << "����" << endl;
        return (false);
    }
    heapArray[CurrentSize] = newNode;
    CurrentSize++;
    SiftUp(CurrentSize - 1);
    return (true);
}

template <class T>
void MaxHeap<T>::visit()
{
    for (int i = 0; i < CurrentSize; i++)
        cout << heapArray[i] << " ";
    cout << endl;
}

/*
 * TODO:2.4-f �ӶѶ�ɾ�����ֵ. �����ջΪ�նѣ��������ӡcout << "�ն�" << endl;Ȼ���˳������˳���Ϊ1.
 * ���򣬴ӶѶ�ɾ�����ֵ����������Ϊ����ֵ���з��ء�
 */
template <class T>
T& MaxHeap<T>::RemoveMax()
{
    T node;
    if (CurrentSize == 0) {
        cout << "�ն�" << endl;
        exit(1);
    }
    node = heapArray[0];
    heapArray[0] = heapArray[CurrentSize - 1];
    CurrentSize--;
    if (CurrentSize > 1)
        SiftDown(0);
    return (node);
}

int main()
{
    /* int a[10] = { 20,12,35,15,10,80,30,17,2,1 }; */
    int count, maxSize; /* ��ʼ������Ԫ�ظ��� */
    cin >> count >> maxSize;
    int iValue;
    int* a = new int[count];
    for (int i = 0; i < count; i++) {
        cin >> iValue;
        a[i] = iValue;
    }

    /* MaxHeap<int> maxheap(a, 10, 20); */
    MaxHeap<int> maxheap(a, count, maxSize);
    int temp;
    maxheap.BuildHeap();
    cout << "�����Ѻ�Ϊ:";
    maxheap.visit();
    cin >> iValue; /* ����һ���������ж����Ƿ��Ƕ��ϵ�Ҷ�ӽڵ� */
    if (maxheap.isLeaf(iValue))
        cout << "λ��" << iValue << "��Ҷ���" << endl;
    else
        cout << "λ��" << iValue << "����Ҷ���" << endl;
    maxheap.visit();
    maxheap.RemoveMax();
    cout << "�Ƴ����ֵ��:";
    maxheap.visit();
    cin >> iValue; /* ����һ���������Ƴ����±����ڵ�Ԫ�� */
    maxheap.Remove(iValue, temp);
    cout << "ɾ���±�Ϊ" << iValue << "��Ԫ��֮��Ϊ:";
    maxheap.visit();
    cout << "ɾ���±�Ϊ" << iValue << "��Ԫ��Ϊ" << temp << endl;
    cin >> iValue; /* ����һ���������Ƴ����±����ڵ�Ԫ�� */
    maxheap.Insert(iValue);
    cout << "����" << iValue << "��Ϊ:";
    maxheap.visit();
    return (0);
}



