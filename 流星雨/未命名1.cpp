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

////////////////////////////上升函数 

void SS()

{

    void printchar();

    int midw1, midw, midw2;

    srand((int)time(NULL));

    for (hang = gao; hang >= high; hang--)//上升阶段 

    {

        midw = wide / 2 + pc * 2;

        midw1 = wide - pc * 6;

        midw2 = wide / 2 - pc * 6;

        yanhua[gao][midw] = 10;

        yanhua[gao][midw1] = 10;

        yanhua[gao][midw2] = 10;

        system("cls");//清理屏幕 

        printchar();

        if (hang < gao)

        {

            int temp;

            for (temp = gao; temp > hang; temp--)

            {

                if (temp <= hang + 5)

                {

                    yanhua[temp][midw] = 20;//产生尾巴 

                    yanhua[temp][midw1] = 20;

                    yanhua[temp][midw2] = 20;

                }

                else

                {

                    yanhua[temp][midw] = 0;//清除尾巴 

                    yanhua[temp][midw1] = 0;

                    yanhua[temp][midw2] = 0;

                }

            }

            yanhua[hang + 1][midw] = 10;//重设烟花头 

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



///////////////////////////////爆炸函数 

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

//////////////////////////////产生随机数函数 

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

///////////////////////////////输出图形函数 

void printchar()

{

    for (i = 0; i < gao; i++)

    {

        for (j = 0; j < wide; j++)

        {

            if (yanhua[i][j] == 0)cout << " ";

            else if (yanhua[i][j] == 10)cout << "●";

            else if (yanhua[i][j] == 20)cout << "‖";

            else if (yanhua[i][j] == 1)cout << "*";

            else if (yanhua[i][j] == 2)cout << "。.";

            else cout << " ";

        }//输出烟花 

        cout << endl;

    }

}

////////////////////////倒计时函数 

void djs()

{

    cout << "精彩不容错过……";

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

    cout << "烟花开始.....";

    Sleep(500);

}

/////////////////////////流星雨 

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

                        cout << "★_";

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

//////////////////////////////输出文字 

void printword()

{

    char ch;

    cout << endl;

    char Word1[180] = "送你一只小熊维尼，让它每天陪着你，和你分享它的蜂蜜，甜到你的心里！";

    for (i = 0; Word1[i] != NULL; i++)

    {

        cout << Word1[i];

        Sleep(50);

    }

    cout << endl;

    cout << "┴┬┴┬／￣＼＿／￣＼" << endl;

    cout << "┬┴┬┴▏　　▏▔▔▔▔＼ " << endl;

    cout << "┴┬┴／＼　／　　　　　　﹨ " << endl;

    cout << "┬┴∕　　　　　　　／　　　） " << endl;

    cout << "┴┬▏　　　　　　　　●　　▏ " << endl;

    cout << "┬┴▏　　　　　　　　　　　▔█　 " << endl;

    cout << "┴◢██◣　　　　　＼＿＿＿／ " << endl;

    cout << "┬█████◣　　　　　　　／　　 " << endl;

    cout << "┴█████████████◣ " << endl;

    cout << "◢██████████████▆▄ " << endl;

    cout << "█◤◢██◣◥█████████◤＼ " << endl;

    cout << "◥◢████　████████◤　　 ＼ " << endl;

    cout << "┴█████　██████◤　　　　　 ﹨ " << endl;

    cout << "┬│　　　│█████◤　　　　　　　　▏ " << endl;

    cout << "┴│　　　│　　　　　　　　　　　　　　▏ " << endl;

    cout << "┬ ∕　　　 ∕　　　　／▔▔▔＼　　　　 ∕ " << endl;

    cout << "┴/＿＿＿／﹨　　　∕　　　　　﹨　　／＼ " << endl;

    cout << "┬┴┬┴┬┴＼ 　　 ＼ 　　　　　﹨／　　 ﹨ " << endl;

    cout << "┴┬┴┬┴┬┴ ＼＿＿＿＼　　　　 ﹨／▔＼﹨ ▔＼ " << endl;

    cout << "▲△▲▲╓╥╥╥╥╥╥╥╥＼　　 ∕　 ／▔﹨／▔﹨ " << endl;

    cout << "　＊＊╠╬╬╬╬╬╬╬╬＊﹨　　／　　／／ " << endl;

    cout << " *********的维尼熊*****************" << endl;

}

int main()

{

    system("color 0f");

    djs();/////////////////////////倒计时 

    for (pc = 1; pc <= 10; pc++)///////////////放烟花 

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

    char Word2[180] = " 今天是元宵节，看完了烟花，我们来看下流星雨吧!现实中流星雨不常见，现在，就让\n我为你制造一场流星雨！可以借机许个愿望吧！\n";

    for (i = 0; Word2[i] != NULL; i++)

    {

        cout << Word2[i];

        Sleep(100);

    }





    lxy();

    char Word3[100] = " 流星雨做的有点丑，但是也期望你元宵节快乐！\n";

    for (i = 0; Word3[i] != NULL; i++)

    {

        cout << Word3[i];

        Sleep(50);

    }

    printword();

    cout << "元宵节快乐！";

    for (flag; flag <= 1; flag++)ch = getchar();





    exit(0);

    //////////////////////////



    



}
