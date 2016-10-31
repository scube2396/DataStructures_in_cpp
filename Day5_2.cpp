#include<iostream>

#define null 0
using namespace std;

class node
{
public:
	int data;
        string name;
	node *prev;
	node *next;
}*head;

class dcll
{
public:
	dcll();
	void create(int,string );
	void display();
	void insertashead();
	void insertaslastnode();
	void search();
	void insertatanyposition();
	void reverse();
	void dele();
};

dcll::dcll()
{
 head=null;
}

void dcll::create(int num,string name)
{
node *temp,*p;
if(head==null)
{
	temp=new node;
	temp->data=num;
	temp->name=name;
	temp->next=temp;
	temp->prev=temp;
	head=temp;
}                                         
else
{
temp=head;
while(temp->next!=head)
temp=temp->next;
p=new node;
p->data=num;
p->name=name;
p->prev=temp;
p->next=head;
temp->next=p;
head->prev=p;
}
}

void dcll::display()
{
int i,data;
node *temp,*new1;
if(head==null)
{}
else{
	temp=head;
	cout<<"\nThe values in the list are:\n";
	do
	{
	cout<<temp->data<<"--"<<temp->name<<"<->";
	temp=temp->next;
	}while(temp!=head);
    }
}

void dcll::insertashead()
{
int num;
string name;
node *temp,*p;
cout<<"\nEnter the number to be entered:\n";
cin>>num;
cout<<"\nEnter the name to be entered:\n";
cin>>name;
if(head==null)
{
	temp=new node;
	temp->data=num;
	temp->name=name;
	temp->prev=temp;
	temp->next=temp;
	head=temp;
}
else
{
	temp=head;
	while(temp->next!=head)
	temp=temp->next;
	p=new node;
	p->data=num;
	p->name=name;
	p->next=head;
	p->prev=temp;
	temp->next=p;
	head->prev=p;
	head=p;
}
}

void dcll::insertaslastnode()
{
node *temp,*p;
int num;
string name;
cout<<"\nEnter the number to be entered:\n";
cin>>num;
cout<<"\nEnter the name to be entered:\n";
cin>>name;
if(head==null)
create(num,name);
else
{
	temp=head;
	while(temp->next!=head)
	temp=temp->next;
	p=new node;
	p->data=num;
	p->name=name;
	p->prev=temp;
	p->next=head;
	temp->next=p;
	head->prev=p;
}
}

void dcll::search()
{
node *temp;
temp=head;
int n,flag=0,count=1;
if(head==null)
	cout<<"\nNo values found.!!\n";
else
{
	cout<<"\nEnter the number to be searched:\n";
	cin>>n;
if(n==temp->data)
	flag=1;
else
{
do
{
	temp=temp->next;
	count++;
if(n==temp->data)
{
	flag=1;
break;
}
}while(temp->next!=head);
}
if(flag==1)
	cout<<"\nMatch found at\t"<<count<<"th location";
else
	cout<<"\nMatch not found\n";
}
}

void dcll::reverse()
{
node*temp;
if(head==null)
cout<<"\nNo values found..!!\n";
else{
temp=head;
while(temp->prev!=head)
{
temp=temp->prev;
cout<<"<->"<<temp->data<<"--"<<temp->name;
}
temp=temp->prev;
cout<<"<->"<<temp->data<<"--"<<temp->name;
}
}

void dcll::insertatanyposition()
{
node *temp,*p;
string name;
int c3=1,pos,i,num;
if(head==null)
{
cout<<"\nEnter the number to be entered:\n";
cin>>num;
cout<<"\nEnter the name to be entered:\n";
cin>>name;
create(num,name);
}
else{
temp=head;
while(temp->next!=head)
{
temp=temp->next;
c3++;
}
cout<<"\nThe length is\n"<<c3;
cout<<"\nenter the position at which node is to be inserted:\n";
cin>>pos;
cout<<"\nEnter the data to be entered in node:\n";
cin>>num;
cout<<"\nEnter the name to be entered:\n";
cin>>name;
for(i=0;i<pos-1;i++)
{
temp=temp->next;
}
p=new node;
p->data=num;
p->name=name;
p->next=temp->next;
temp->next=p;
p->prev=temp;
}
}

void dcll::dele()
{
node *temp,*p;
string name;
int c3=1,pos,i,num;
if(head==null)
{
cout<<"\nNo value exists..!!\n";
}
else{
temp=head;
while(temp->next!=head)
{
temp=temp->next;
c3++;
}
cout<<"\nThe length is\n"<<c3;
temp=head;
p=head;
cout<<"\nEnter the position of node which is to be deleted:\n";
cin>>pos;
if(pos==1)
{
temp=temp->next;
p=p->prev;
temp->prev=p;
p->next=temp;
temp=temp->prev->next;
head=temp;
}
else
{
p=p->next;
for(i=0;i<pos-2;i++)
{
temp=temp->next;
p=p->next;
}
temp->next=p->next;
p->next->prev=temp;
}
}
}

int main()
{

int num,choice=0;
string name;
dcll d;
do
{
cout<<"\nPLEASE ENTER YOUR CHOICE:\n1.CREATE\n2.INSERT AS FIRST NODE\n3.INSERT AS LAST NODE\n4.SEARCH\n5.REVERSE\n6.INSERT AT ANY POSITION\n7.DELETE\n8.EXIT";
cin>>choice;
switch(choice)
{
case 1: cout<<"\nENTER THE ROLL_NO. TO BE INSERTED IN THE LIST:\n";
	cin>>num;
	cout<<"\nENTER THE NAME\n";
	cin>>name;
	d.create(num,name);
	d.display();
	break;
case 2: d.insertashead();
	d.display();
	break;
case 3: d.insertaslastnode();
	d.display();
	break;
case 4: d.search();
	d.display();
	break;
case 5: d.reverse();
	d.display();
	break;
case 6: d.insertatanyposition();
	d.display();
	break;
case 7: d.dele();
	d.display();
	break;
case 8: cout<<"\nTHANK YOU\n";
	break;
default:cout<<"you have entered a wrong option";
}
}while(choice!=8);


}
