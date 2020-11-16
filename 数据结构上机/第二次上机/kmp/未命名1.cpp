#include <iostream>
#include <string.h>
#include<bits/stdc++.h> 

using namespace std;

/*
 * TODO����ģʽT��nextֵ
 * ����������ʹ����������ģʽT��nextֵ
 * ����˵����T[]: ģʽT
 *          next[]: ������������
 * ����ֵ˵������
*/
void GetNext(char T[], int next[])
{
	int m = strlen(T);
	if(m<=0)
	{
		exit[0];
	 } 
	else
	{
		next[0] = 0;
		for(int i=1 ; i<m ; i++)
		{
			int k = next[i-1];
			while(k>0 && T[i]!=T[k])	k= next[k-1];
			if(T[i] == T[k])	next[i] = k+1;
			else next[i] = 0;
			}	
	}
}

/*
 * TODO����ƥ��KMP�㷨
 * ������������������S���Լ�ģʽT������T��S�е�λ��, ʹ�ô�ƥ��KMP�㷨�������⡣
            ����GetNext�������ʱ�ٶ�ģʽ�Ϊ80���ַ���
 * ����˵����S[]: ����S
 *           T[]: ģʽT
 * ����ֵ˵��������ƥ��Ŀ�ʼλ�ã��±�+1��
 * ����˵��������ģʽT��abcacc������S��abcabcabcaccb�е�λ���ǣ�7
*/
int KMP(char S[],char T[])
{
	int i=0,j=0,t,a[80];
	while(i<strlen(S)&&j<strlen(T))
	{
		if(S[i]!='\0'&&T[j]!='\0')
		{
			if(S[i]==T[j])
			{
				i++;j++;
			}
			else
			{
				if(j==0)
				i=i+1;
				else
				{
					GetNext(T, a);
					j=a[j-1];
				}
			}
		}

	}

	if(j==strlen(T))return i-strlen(T)+1;
	else return 0;
}

int main()
{

    const int size = 20;
    char S[size];
    char T[size];
    //��ƥ��BF�㷨
    //���룺 ����S, ģʽT
    cout<<"����������S:"<<endl;
    cin>>S;
    cin.get();
    cout<<"���������ģʽT:"<<endl;
    cin>>T;
    cin.get();
    //��ƥ��KMP�㷨
    //���룺 ����S, ģʽT
    int index = KMP(S,T);
    //����� T��S�е�λ��
    for (int i = 1; i < index; i++)
        cout<<" ";
    cout<<T<<"��"<<endl;
    cout<<S<<"�е�λ���ǣ�"<<index<<endl;
    return 0;
}

