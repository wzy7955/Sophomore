#include<iostream>
#include<string>
#include<algorithm>
#include<time.h>
#include<stack>
#include<queue>
using namespace std; 
class hosnode//医院节点
{    friend class hos;    
hosnode* father;//父亲指针；    
hosnode* left_child;//最左的孩子   
 hosnode* right_brother;//右兄弟   
  string name;//节点名称    
  int n;//数量
  public:    hosnode(string a,int b)    {        name=a;        n=b;    }    string getname()    {        return name;    }    int get_n()    {        return n;    }};class hos//结构类（这里为医院结构类）
  {    hosnode* head;public:    hos(string name,int n)    {        head=new hosnode(name,n);        head->left_child=0;        head->right_brother=0;        head->father=0;    }    hosnode *find(string name)    {        hosnode* temp=head;        if(name==temp->name)return temp;        queue< hosnode* > a;        a.push(temp);        while(!a.empty())        {            temp=a.front();            a.pop();            temp=temp->left_child;//出队列          
    while(temp!=0)            {                a.push(temp);                if(name==temp->name)return temp;                temp=temp->right_brother;            }        }        return 0;    }    bool insert(string father,string child,int n)    {        hosnode* temp=find(father);        if(temp->left_child==0)        {            temp->left_child=new hosnode(child,n);            temp->left_child->right_brother=0;            temp->left_child->father=temp;            temp->left_child->left_child=0;        }        else        {            temp=temp->left_child;            while(temp->right_brother!=0)                temp=temp->right_brother;            temp->right_brother=new hosnode(child,n);            temp->right_brother->right_brother=0;            temp->right_brother->father=find(father);            temp->right_brother->left_child=0;        }        return 1;    }    int get_number(string big,string small)    {        hosnode* p1=find(big);        hosnode* p2=find(small);        int sum=1;        while(p2!=0 && p2!=p1)        {            sum*=p2->n;            p2=p2->father;        }        if(p2==0)        {            return 0;        }        else            return sum;    }    hosnode * get_this_and_all_childs(string name)    {        hosnode * temp=find(name);        if(temp==0)return 0;        else        {            cout<<temp->name<<"的所有孩子:";            temp=temp->left_child;            if(temp==0)cout<<"无";            while(temp!=0)            {                cout<<temp->name<<" ";                temp=temp->right_brother;            }            cout<<"\n";            return find(name);        }    }    void show_all()    {        hosnode* temp=head;        get_this_and_all_childs(head->name);        queue<hosnode*> a;        a.push(temp);        while(!a.empty())        {            temp=a.front();            a.pop();            temp=temp->left_child;//出队列         
	  while(temp!=0)            {                a.push(temp);                get_this_and_all_childs(temp->name);                temp=temp->right_brother;            }        }    }};int main(){    hos a("医院",1);    a.insert("医院","楼层",1);    a.insert("楼层","配楼",4);    a.insert("楼层","中央大厅",1);    a.insert("中央大厅","电视",1);    a.insert("中央大厅","沙发",2);    a.insert("配楼","长走廊",2);    a.insert("配楼","走廊连接",1);    a.insert("走廊连接","库房",5);    a.insert("长走廊","病房",21);    a.insert("病房","卫生间",1);    a.insert("病房","插座",4);    a.insert("病房","病床",2);    a.insert("卫生间","洗脸盆",1);    a.insert("卫生间","座便器",1);    a.insert("插座","插口",2);    a.insert("插座","面板",1);    cout<<a.get_number("楼层","病房")<<"\n";    cout<<a.get_number("长走廊","病房")<<"\n";    cout<<a.get_number("病房","插口")<<"\n";    cout<<a.get_number("医院","插口")<<"\n";    a.get_this_and_all_childs("楼层");    cout<<"\n\n\n";    a.show_all();}

