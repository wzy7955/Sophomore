//#include <bits/stdc++.h>

#include "iostream"

#include "time.h"

#include <windows.h>

#include <stdio.h>

#include<conio.h> 

using namespace std;



#define wide 49 



#define gao 24 

#define high 6 

int yanhua[gao][wide], hang, lie, i, j, temp, pc, flag;

char ch;

////////////////////////////�������� 

void SS()

{

    void printchar();

    int midw1, midw, midw2;

    srand((int)time(NULL));

    for (hang = gao; hang >= high; hang--)//�����׶� 

    {

        midw = wide / 2 + pc * 2;

        midw1 = wide - pc * 6;

        midw2 = wide / 2 - pc * 6;

        yanhua[gao][midw] = 10;

        yanhua[gao][midw1] = 10;

        yanhua[gao][midw2] = 10;

        system("cls");//������Ļ 

        printchar();

        if (hang < gao)

        {

            int temp;

            for (temp = gao; temp > hang; temp--)

            {

                if (temp <= hang + 5)

                {

                    yanhua[temp][midw] = 20;//����β�� 

                    yanhua[temp][midw1] = 20;

                    yanhua[temp][midw2] = 20;

                }

                else

                {

                    yanhua[temp][midw] = 0;//���β�� 

                    yanhua[temp][midw1] = 0;

                    yanhua[temp][midw2] = 0;

                }

            }

            yanhua[hang + 1][midw] = 10;//�����̻�ͷ 

            yanhua[hang + 1][midw1] = 10;

            yanhua[hang + 1][midw2] = 10;

        }

        if (hang == 5)

        {

            int temp;

            for (temp = gao; temp > hang; temp--)yanhua[temp][midw] = 0;

            yanhua[hang + 1][midw] = 10;

        }

        Sleep(10);

    }

}



///////////////////////////////��ը���� 

void BZ()

{

    void printchar();

    void randnum();

    for (temp = 1; temp <= 3; temp++)

    {

        randnum();

        system("cls");

        printchar();

        Sleep(40);

    }

    for (i = 0; i < gao; i++)

    {

        for (j = 0; j < wide; j++)yanhua[i][j] = 0;

    }

}

//////////////////////////////������������� 

void randnum()

{

    srand((int)time(0));

    for (hang = 0; hang < gao; hang++)

    {

        for (lie = 0; lie < wide; lie++)

        {

            yanhua[hang][lie] = (int)((10 * rand()) / RAND_MAX);

        }

    }

}

///////////////////////////////���ͼ�κ��� 

void printchar()

{

    for (i = 0; i < gao; i++)

    {

        for (j = 0; j < wide; j++)

        {

            if (yanhua[i][j] == 0)cout << " ";

            else if (yanhua[i][j] == 10)cout << "��";

            else if (yanhua[i][j] == 20)cout << "��";

            else if (yanhua[i][j] == 1)cout << "*";

            else if (yanhua[i][j] == 2)cout << "��.";

            else cout << " ";

        }//����̻� 

        cout << endl;

    }

}

////////////////////////����ʱ���� 

void djs()

{

    cout << "���ʲ��ݴ������";

    Sleep(1000);

    system("cls");

    void printchar();

    for (temp = 3; temp >= 1; temp--)

    {

        switch (temp)

        {

        case 1:

            for (i = 2; i <= 15; i++)

            {

                for (j = wide / 2; j <= wide / 2 + 1; j++)yanhua[i][j] = 1;

            }break;

        case 2:

            for (i = 2; i <= 15; i++)

            {

                switch (i)

                {

                case 2:case 3:case 8:case 9:case 14:case 15:

                    for (j = wide / 2 - 7; j <= wide / 2 + 8; j++)yanhua[i][j] = 1; break;

                case 4:case 5:case 6:case 7:

                    for (j = wide / 2 + 7; j <= wide / 2 + 8; j++)yanhua[i][j] = 1; break;

                default:

                    for (j = wide / 2 - 7; j <= wide / 2 - 6; j++)yanhua[i][j] = 1; break;

                }

            }break;

        case 3:

            for (i = 2; i <= 15; i++)

            {

                switch (i)

                {

                case 2:case 3:case 8:case 9:case 14:case 15:

                    for (j = wide / 2 - 7; j <= wide / 2 + 8; j++)yanhua[i][j] = 1; break;

                default:

                    for (j = wide / 2 + 7; j <= wide / 2 + 8; j++)yanhua[i][j] = 1; break;

                }

            }break;

        }

        printchar();

        Sleep(1000);

        for (i = 0; i < gao; i++)

        {

            for (j = 0; j < wide; j++)yanhua[i][j] = 0;

        }

        system("cls");

    }

    cout << "�̻���ʼ.....";

    Sleep(500);

}

/////////////////////////������ 

void lxy()

{

    int flag, n;

    srand((int)time(0));

    for (hang = 0; hang < gao; hang++)

    {

        for (lie = 0; lie < wide; lie++)

        {

            yanhua[hang][lie] = (int)((100 * rand()) / RAND_MAX);

        }

    }

    for (flag = 0; flag <= 4; flag++)

    {

        for (temp = 1; temp < wide; temp++)

        {

            for (i = 0, n = 0; i < gao; i++)

            {

                for (j = wide - 1; j >= 0; j--)

                {

                    switch (yanhua[i][j])

                    {

                    case 56:

                    {

                        cout << "��_";

                        n++;

                        if (n % 6 == 0)

                        {

                            yanhua[i - 2][j - 1] = 56;

                            yanhua[i][j] = 0;

                        }

                        else

                        {

                            yanhua[i][j + i] = 56;

                            yanhua[i][j] = 0;

                        }

                        Sleep(0);

                    }break;

                    case 0:

                    {

                        cout << "--";

                        yanhua[i][j] = 1;

                    }break;

                    default:cout << " ";

                    }

                }

            }

            system("cls");

        }

        Sleep(80);

    }

}

//////////////////////////////������� 

void printword()

{

    char ch;

    cout << endl;

    char Word1[180] = "����һֻС��ά�ᣬ����ÿ�������㣬����������ķ��ۣ���������";

    for (i = 0; Word1[i] != NULL; i++)

    {

        cout << Word1[i];

        Sleep(50);

    }

    cout << endl;

    cout << "�ةЩةУ����ܣߣ�����" << endl;

    cout << "�ЩةЩب����������������� " << endl;

    cout << "�ةЩأ��ܡ����������������� " << endl;

    cout << "�ЩبM������������������������ " << endl;

    cout << "�ةШ������������������񡡡��� " << endl;

    cout << "�Щب����������������������������� " << endl;

    cout << "�ب������������������ܣߣߣߣ� " << endl;

    cout << "�Ш������������������������������� " << endl;

    cout << "�ب��������������������������� " << endl;

    cout << "�������������������������������}�{ " << endl;

    cout << "������������������������������������ " << endl;

    cout << "������������������������������������ �� " << endl;

    cout << "�ب����������������������������������� �� " << endl;

    cout << "�Щ��������������������������������������� " << endl;

    cout << "�ة��������������������������������������� " << endl;

    cout << "�� �M������ �M�����������������ܡ������� �M " << endl;

    cout << "��/�ߣߣߣ����������M�������������������� " << endl;

    cout << "�ЩةЩةЩأ� ���� �� ������������������ �� " << endl;

    cout << "�ةЩةЩةЩ� �ܣߣߣߣܡ������� �������ܩ� ���� " << endl;

    cout << "���������W�i�i�i�i�i�i�i�i�ܡ��� �M�� ������������ " << endl;

    cout << "�������d�p�p�p�p�p�p�p�p������������������ " << endl;

    cout << " *********��ά����*****************" << endl;

}

int main()

{

    system("color 0f");

    djs();/////////////////////////����ʱ 

    for (pc = 1; pc <= 10; pc++)///////////////���̻� 

    {

        SS();

        switch (pc)

        {

        case 1:system("color 14"); break;

        case 6:system("color 6f"); break;

        case 2:system("color 2b"); break;

        case 9:system("color 91"); break;

        case 3:system("color 3e"); break;

        case 7:system("color 79"); break;

        case 4:system("color 4f"); break;

        case 10:system("color 8a"); break;

        case 5:system("color 5e"); break;

        case 8:system("color a5"); break;

        }

        BZ();

        system("cls");

        system("color 0f");

    }

    char Word2[180] = " ������Ԫ���ڣ��������̻��������������������!��ʵ�������겻���������ڣ�����\n��Ϊ������һ�������꣡���Խ�����Ը���ɣ�\n";

    for (i = 0; Word2[i] != NULL; i++)

    {

        cout << Word2[i];

        Sleep(100);

    }





    lxy();

    char Word3[100] = " �����������е�󣬵���Ҳ������Ԫ���ڿ��֣�\n";

    for (i = 0; Word3[i] != NULL; i++)

    {

        cout << Word3[i];

        Sleep(50);

    }

    printword();

    cout << "Ԫ���ڿ��֣�";

    for (flag; flag <= 1; flag++)ch = getchar();





    exit(0);

    //////////////////////////



    



}
