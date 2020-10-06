#include<fstream> // �� Ŭ������ ������Ʈ�� ���Ϲ��� ��ü�� ���� ��Ʈ�� ���۷� ����, �� ���۰� ����� ����(�ִ� ���)���� �Է�/��� �۾� ����.
#include<iostream> // (�⺻) ���� �������� �Է��� �а� �ؼ� ����
#include<string> // ���ڿ��� ��� Ŭ���� 
#include<cstdlib> // ���� �޸� ����, ���� ����, ȯ����� ���, �������, �˻�, ���� �� ��ȯ�� ������ �� ���� ���� ����� ����
#include <cstring> // C ���ڿ��� �迭�� �����ϴ� �� ���� ����� ����

#include<stdio.h>           // C ����� ǥ�� ���̺귯�� �Լ��� ��ũ�� ����, ���, ���� ���� ����� �Լ��� ���Ե� ��� ����
using namespace std;
class file{
public:
    file(){
        ofstream fout;           // ofsream: ���� ���� ���(ifstream: ���� �б�) // https://blockdmask.tistory.com/322
        fout.open("anish.txt");  
        fout<<"anish";
        fout.close();
    }
};
class earn{
        public:
        double profit;
        void show()
		{
		ifstream x("ooo.txt");    // ifstream: �� �ּ� ����
        if(!x)
        cout<<"PROFIT = 0 ";
        else{
        x>>profit;
        cout<<"\nTOTAL STARTING PROFIT:  "<<profit<<endl;
        x.close();
        }
        
        }

};
class product:public virtual earn{
public:
           int quan;
           char name[20];
           char id[20];
           double percost;
           double persell;
           double cost;
           double sell;
           void cal()
		   {
		    cost=percost*quan;
        	sell=persell*quan;
            profit=profit +(sell-cost)*365;
			}
           void file(); // 76���ٿ� ���ǵ�
           void get();  // �ٷ� �ؿ� ���ǵ�

};
void product::get()
{
 int s;
cout<<"\nnumber of products produced?\n";
cin>>s;
for(int i=0;i<s;i++)
{
  cout<<"\ninput product name: \n";
  cin>>name;
  cout<<"\ninput product id: \n";
  cin>>id;
  cout<<"\ninput cost price of product: \n";
  cin>>percost;
  cout<<"\ninput selling price of product: \n";
  cin>>persell;
  cout<<"\ntotal product quantity: \n";
  cin>>quan;
    cal();     // 44���ٿ� ���ǵ�
    file();    // 76���ٿ� ���ǵ�
  }
 
}
void product::file()
{
char file[20];
strcpy(file,id);
strcat(file,".txt");
ofstream f(file);
f<< "\nproduct name: "<<name<< "\nproduct id: "<<id<<"\ncost price of product: " <<percost<<"\nselling price of product: "<<persell<<"\nquantity: "<<quan<<"\n total cost: "<<cost<<"\nsell: "<<sell;
f.close();
}

class staff:public virtual earn{
         protected:
         double salary;
         char post[12];
         char empid[10];
         int postquan;
         void cal()
         {
		 profit=(profit-salary*postquan)*12;
         }
         void getstaff();  //96 ���ٿ� ����
         void file();
};
void staff::getstaff()
{
  cout<<"\ninput salary: \n";
  cin>>salary;
  cout<<"\ninput number of employees: \n";
  cin>>postquan;
  for(int i=0;i<postquan;i++)
  {
  	cout<<"input employee name\n";
  	cin>>post;
  cout<<"\ninput employee ID\n";
  cin>>empid;
  cal();
  file();
}
}
 void staff::file()
{  char file[20];
strcpy(file,empid);
strcat(file,".txt");
ofstream f(file);
f<< "\nnumber of working employees: "<<postquan<< "\nemployee salary: "<<salary<< "\nemployee name :"<<post<<"\nemployee id: "<<empid;
f.close();
}

class amount:public staff, public product
{

 public:
    void add();          // 133 ���� ����
    void update_item();  // 162 ���� ����
    void update_emp();   // 195 ���� ����

};
void amount::add()
{
	int ch;
	char name[20];
	while(1)
	{
		cout<<"1.)Input for product\n2.)Input for employee\n3.)Exit\n";
		cout<<"Enter choice\n";
		cin>>ch;
		if(ch==1){
				get();
				ofstream x("ooo.txt");
 				x<<profit;
 				x.close();
			}
			else if(ch==2){
				getstaff();
				ofstream x("ooo.txt");
 				x<<profit;
 				x.close();
				}
			else if(ch==3)
				break;
			else
				cout<<"Invaid Option. Please re-enter\n";
			}
		}

 
	void amount::update_item()
	{
	char id[20];
	char pid[20];
    char c;
    cout<<"\nINPUT product ID to modify\n";
    cin>>id;
    char file[20];
    char file2[20];
    strcpy(file,id);
    strcat(file,".txt");
    fstream fout(file, ios::in|ios::out);
    if(!fout)
    {
    	cout<<"file couldn't be opened. product ID not found. \n";
	}
	else {
	cout<<"file found! \n";
    cout<<"\nupdate product name: \n";
  	cin>>name;
 	cout<<"\nupdate percost of product: \n";
  	cin>>percost;
 	cout<<"\nupdate persell of product: \n";
  	cin>>persell;
 	cout<<"\nupdate total product quantity: \n";
 	cin>>quan;
    cost=percost*quan;
    sell=persell*quan;
	profit=profit +(sell-cost)*365;
  	fout<<"\nproduct name: "<<name<< "\nproduct id: "<<id<<"\npercost ofproduct: " <<percost<<"\npersell of product: "<<persell<<"\nquantity: "<<quan<<"\n total cost: "<<cost<<"\nsell: "<<sell;
	fout.close();
}
}
   void amount::update_emp()	
	{
	char id[20];
    char c;
    cout<<"\nINPUT employee ID to modify: ";
    cin>>id;
    char file[20];
    strcpy(file,id);
    strcat(file,".txt");
    fstream fout(file, ios::in|ios::out);
     if(!fout)
    {								
    	cout<<"file couldn't be opened. product ID not found. \n";
	}
	cout<<"modify employee name: \n";
  	cin>>post;
  	fout<< "\nnumber of working employees: "<<postquan<< "\nemployee salary: "<<salary<< "\nemployee name :"<<post<<"\nemployee id: "<<empid;
 	fout.close();
}

void admin()
{
  while(1)
  {
 	cout<<"\n\t\t\t==============================\n";
	cout<<"\n\t\t\t     WELCOME TO THE SHOP  \n";
	cout<<"\n\t\t\t==============================\n\n";
	cout<<"\n\t\t\t* * * * * * * * * * * * * * * *\n";
 	cout<<"\n\t\t\t1. Add Entries\n\n\t\t\t2. Show profit\n\n\t\t\t3. Search Product Details\n\n\t\t\t4. Search Employee Details\n\n\t\t\t5. Modify Product Details\n\n\t\t\t6. Modify Employee Details\n\n\t\t\t7. Exit\n";
  cout<<"\n\n\t\t\tSelect your choice\n";
  int u;
  cin>>u;
if(u==1)
  {
  amount a;
  a.show();  // 21���� ����
  a.add();   // 133���� ����
}
  else if(u==2)
  {
  amount d;
  d.show();  // 21���� ����
}
  else if(u==3)
  {  
   char id[20];
   char c;
    cout<<"\nINPUT ID to search\n";
    cin>>id;
    char file[20];
    strcpy(file,id);
    strcat(file,".txt");
    ifstream x(file);
    if(!x)
    {
    	cout<<"file couldn't be opened. product ID not found. \n";
	}
    while(x)
    {x.get(c);   //54���� ����
     cout<<c;
    }
    

    x.close();
}
   else if(u==4)
   {
   	char eid[20];
   	char d;
   	cout<<"\nINPUT employee ID to search\n";
    cin>>eid;
   	char file[20];
   	strcpy(file,eid);
   	strcat(file,".txt");
   	ifstream y(file);
   	 if(!y)
    {
    	cout<<"file couldn't be opened. employee ID not found. \n";
	}
   	while(y)
   	{
   	y.get(d);   //54���� ����
   	cout<<d;
   }
 
   y.close();
}
else if(u==5)
{
	amount u;
	u.update_item();  // 162���� ����
}
 else if(u==6)
 {
 	amount v;
 	v.update_emp();  // 195���� ����
 }
  else if(u==7)
  {
  break;
}
  else cout<<"Invalid option. Please select one of the available options\n";
 }

}

int main(){
    int ch;
    char  username[20];
    char password[20];
    char pwd[20];
    while(1){
        cout<<"\n \t\t\t=========================\n";
        cout<<"\n\t\t\tWELCOME TO MY SHOP  \n";
        cout<<"\n \t\t\t=========================\n\n";
        cout<<"\n \t\t\t* * * * * * * * * * * * ";
        cout<<"\n\t\t\t  1. ENTER SYSTEM";
        cout<<"\n\t\t\t  2. EXIT";
        cout<<"\n\t\t\t* * * * * * * * * * * *\n";
        cout<<"\n\t\t\t Enter Your choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                admin(); // 215���ٿ� ����
                break;
            case 2:
                exit(0);
                break;
            default:
                cout<<"Enter valid choice\n";
                break;
        }
    }
    return 0;
}


