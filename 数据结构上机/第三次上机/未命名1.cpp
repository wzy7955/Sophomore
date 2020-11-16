/*具体要求请见教材2.7.2?队列：银行叫号系统的实现??p69?（PDF中是在54页）?本次上机代码需要提交到华为云。
编写一个程序模拟银行取号系统，该程序只是模拟了取号排队的功能，本模拟系统的最终目标是：实现叫号机的基本功能，即用
户到达后可以叫号，工作人员登录进入系统后可以对用户进行办理业务。*/

#include<bits/stdc++.h>
using namespace std ;

//定义三种用户，虚继承服务项 
class User
{
	public:
		int id;
    	int isWait;
   		int ArriveTime;
		wchar_t type;
		virtual void getServed();
		
		User();
    	User(int id,bool isWait,int ArriveTime,wchar_t type,int ServerTime)
        :id(id),isWait(isWait),ArriveTime(ArriveTime),type(type),ServerTime(ServerTime){};
    	~User(){};

    
	private:
    	int ServerTime;
};

class NormalUser: public User{
public:
    NormalUser(int id,bool isWait,int ArriveTime,wchar_t type,int ServerTime)
        :User(id,isWait,ArriveTime,type,ServerTime){};
    void getServed();
};

class VIPUser: public User{
public:
    VIPUser(int id,bool isWait,int ArriveTime,wchar_t type,int ServerTime)
        :User(id,isWait,ArriveTime,type,ServerTime){};
    void getServed();
};

class OfficialUser: public User{
public:
    OfficialUser(int id,bool isWait,int ArriveTime,wchar_t type,int ServerTime)
        :User(id,isWait,ArriveTime,type,ServerTime){};
    void getServed();
};



//定义服务项 
void User::getServed(){
    if(type=='n'){
        cout<<endl<<endl<<"普通用户："<<id<<" 服务完毕！"<<endl;
    }
    if(type=='v'){
        cout<<endl<<endl<<"VIP用户："<<id<<" 服务完毕"<<endl;
    }
    if(type=='o'){
        cout<<endl<<endl<<"对公用户："<<id<<" 服务完毕"<<endl;
    }
}

/*void NormalUser::getServed(){
    cout<<endl<<endl<<"普通用户："<<id<<" 服务完毕"<<endl;
}

void VIPUser::getServed(){
    cout<<endl<<endl<<"VIP用户："<<id<<" 服务完毕"<<endl;
}

void OfficialUser::getServed(){
    cout<<endl<<endl<<"对公用户："<<id<<" 服务完毕 "<<endl;
}*/




//定义窗口 
class BankWindow
{
	public:
		bool isBusy;      //占用 
		int id;
    	User *client;    //client 客户 
    	wchar_t type;
    	int serviceStartTime;    //起始时间 t
		virtual void HandleUser();
		
		BankWindow(){};
    	BankWindow(bool isBusy,int id,wchar_t type):isBusy(isBusy),id(id),type(type){};
    	~BankWindow(){};
		
	};
	
class NormalBankWindow: public BankWindow{
	public:
    	NormalBankWindow(bool isBusy,int id,wchar_t type)
        :BankWindow(isBusy,id,type){};
    	void HandleUser();
};

class VIPBankWindow: public BankWindow{
	public:
    	VIPBankWindow(bool isBusy,int id,wchar_t type)
        :BankWindow(isBusy,id,type){};
    	void HandleUser();
};

class OfficialBankWindow: public BankWindow{
	public:
    	OfficialBankWindow(bool isBusy,int id,wchar_t type)
        :BankWindow(isBusy,id,type){};
    	void HandleUser();
};
 
 

//定义窗口当前使用
void BankWindow::HandleUser(){
    cout<<endl<<"此窗口正被占用"<<endl;
}
void NormalBankWindow::HandleUser(){
    cout<<endl<<this->id<<"号窗口正被占用"<<client->id<<endl<<endl;
}

void VIPBankWindow::HandleUser(){
    cout<<endl<<"VIP窗口正被占用"<<client->id<<endl<<endl;
}

void OfficialBankWindow::HandleUser(){
    cout<<endl<<"对公窗口正被占用"<<client->id<<endl<<endl;
}

//叫号系统
class Simulater
{
	public:
	 Simulater(){};
    ~Simulater(){};

    queue<NormalUser> NormalUserQueue;
    queue<VIPUser> VIPUserQueue;
    queue<OfficialUser> OfficialUserQueue;

    list<NormalBankWindow> nbw;
    list<VIPBankWindow> vbw;
    list<OfficialBankWindow> obw;

    void customerEnter();
    void simulateCustomerEnter();
    void simulateCallCustomer();
    void Simulate();

    void display();
	
 };
 
//银行进人

int t  = 0;
bool Flag = false; 
int customerEnterArray[7][3]={
    {3,1,1},
    {5,0,0},
    {0,0,0},
    {5,1,0},
    {0,0,0},
    {0,0,0},
    {0,0,0},
    
};
 
void Simulater::customerEnter(){//模拟用户入队   4s办事 2s来人 
	static int h=0 ;
	int i=0,j=0,k=0;
    i=customerEnterArray[t/2][0];
    j=customerEnterArray[t/2][1];
    k=customerEnterArray[t/2][2];
    
    //入队 
     for(int n=0;n<i;n++){
        NormalUserQueue.push(NormalUser(h++,true,t,'n',4));
        cout << "普通客户排队,  编号id:" <<NormalUserQueue.back().id<< endl;
    }
    for(int n=0;n<j;n++){
        VIPUserQueue.push(VIPUser(h++,true,t,'v',4));
        cout << "VIP客户排队,  编号id:"<<VIPUserQueue.back().id<<endl;
    }
    for(int n=0;n<k;n++){
        OfficialUserQueue.push(OfficialUser(h++,true,t,'o',4));
        cout << "对公客户排队,  编号id:" <<OfficialUserQueue.back().id<< endl;
    }


} 


//银行处理用户序列
void Simulater::simulateCustomerEnter(){ 
    //普通用户窗口
    list<NormalBankWindow>::iterator itor;
    itor=nbw.begin();
    while(itor!=nbw.end()){
        cout <<"窗口号:"<<itor->id;
        if (itor->isBusy == true){
            cout<< "  正在服务  "<< " 窗口类型: " << "普通 "<< "客户编号: " << itor->client->id;
            if (t - itor->serviceStartTime >= 4){
                itor->client->getServed();
                Flag=true;
                itor->isBusy = false;//将当前位置的User清空
            }
        }
        else{
            cout << "  等待  "<<endl;
        }
        cout<<endl;
        itor++;
    }
    //VIP用户窗口
    cout <<"窗口号:"<<vbw.begin()->id;
    if (vbw.begin()->isBusy == true){
        cout<< "  正在服务  "<< " 窗口类型: " << " VIP "<< "客户编号: " << vbw.begin()->client->id;
        if (t - vbw.begin()->serviceStartTime >= 4){
            vbw.begin()->client->getServed();
            Flag=true;
            vbw.begin()->isBusy = false;//将当前位置的User清空
        }
    }
    else{
        cout << "  等待  "<<endl;
    }
    cout<<endl;
    //对公用户窗口
    cout <<"窗口号:"<<obw.begin()->id;
    if (obw.begin()->isBusy == true){
        cout<< "  正在服务  "<< " 窗口类型: " << "对公 "<< "客户编号: " << obw.begin()->client->id;
        if (t - obw.begin()->serviceStartTime >= 4){
            obw.begin()->client->getServed();
            Flag=true;
            obw.begin()->isBusy = false;//将当前位置的User清空
        }
    }
    else{
        cout << "  等待  "<<endl;
    }
    cout<<endl;

}


void Simulater::simulateCallCustomer(){//从队列里面呼叫
    //普通用户窗口
    list<NormalBankWindow>::iterator itor;
    itor=nbw.begin();
    while(itor!=nbw.end()){
        if (itor->isBusy == false && !NormalUserQueue.empty()){
            itor->client = &NormalUserQueue.front();
            cout<<itor->client->id<<"请进入"<<itor->id<<"号普通窗口" ;
            itor->HandleUser();
            itor->isBusy = true;
            itor->serviceStartTime = t;
            NormalUserQueue.pop();
        }
        itor++;
    }
	if (vbw.begin()->isBusy == false){
        if (!VIPUserQueue.empty()){
            vbw.begin()->client = &VIPUserQueue.front();
            vbw.begin()->isBusy = true;
            vbw.begin()->serviceStartTime = t;
            VIPUserQueue.pop();
            cout <<vbw.begin()->client->id<< " 请进入VIP窗口" ;
            vbw.begin()->HandleUser();
        }
        else if (!NormalUserQueue.empty()){
            vbw.begin()->client = &NormalUserQueue.front();
            vbw.begin()->isBusy = true;
            vbw.begin()->serviceStartTime = t;
            NormalUserQueue.pop();
            cout <<vbw.begin()->client->id<< " 请进入VIP窗口" ;
            vbw.begin()->HandleUser();
        }
        else{}
    }
	//对公用户窗口
    if (obw.begin()->isBusy == false){
        if (!OfficialUserQueue.empty()){
            obw.begin()->client = &OfficialUserQueue.front();
            obw.begin()->isBusy = true;
            obw.begin()->serviceStartTime = t;
            OfficialUserQueue.pop();
            cout <<obw.begin()->client->id<< " 请进入对公窗口" ;
            obw.begin()->HandleUser();
        }
        else if (!NormalUserQueue.empty()){
            obw.begin()->client = &NormalUserQueue.front();
            obw.begin()->isBusy = true;
            obw.begin()->serviceStartTime = t;
            NormalUserQueue.pop();
            cout <<obw.begin()->client->id<< " 请进入对公窗口" ;
            obw.begin()->HandleUser();
        }
        else {}
    }
}

void Simulater::Simulate(){
    nbw.push_back(NormalBankWindow(false,0,'n'));
    nbw.push_back(NormalBankWindow(false,1,'n'));
    nbw.push_back(NormalBankWindow(false,2,'n'));
    vbw.push_back(VIPBankWindow(false,3,'v'));
    obw.push_back(OfficialBankWindow(false,4,'o'));
    cout << "------------------------模  拟  开  始---------------------" << endl;


 while(t<=12){
        cout<<"t= "<<t<<" 时 :"<<endl;
        customerEnter();
        simulateCallCustomer();
        simulateCustomerEnter();
        if(Flag){
            Flag=false;
            //customerEnter();
            simulateCallCustomer();
            simulateCustomerEnter();
        }
        cout<<endl<<"**********************************************************"<<endl;

        //时间增加
        t+=2;
    }

}

int main(){
    Simulater A;
    A.Simulate();
    return 0;
}

