#include<iostream>
using namespace std;
#define MAX 3
class STACK
{
private:
	int a[MAX];
	int top;
public:
	 STACK()
	{
		top =-1;
	}
	STACK operator+(int ele)
	{//check for overflow
		if(top==MAX-1)
		cout<<"Stack is Full"<<endl;
		else
		a[++top]=ele;
		return(*this);
	}
	STACK operator-(int temp)
	{//check for underflow
		if(top==-1)
		cout<<"Stack is empty"<<endl;
		else
		cout<<"Deleted Element is "<<a[top--]<<endl;
		return(*this);
	}
	friend ostream& operator<<(ostream &o, STACK &s);
};
ostream& operator<<(ostream &o, STACK &s)
{
	if(s.top==-1)
	o<<"Empty Stack Cannot Display"<<endl;
	else
	{
		for(int i=s.top;i>=0;i--)
		{
			o<<s.a[i]<<"\t";
		}
	}

}
int main()
{
	STACK s;
	int ch,s1;
	do
	{
		cout<<"Press 1 for Push, 2 for Pop, 3 for Display"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1: 
				cout<<"Enter the Element"<<endl;
				cin>>s1;
				s=s+s1;
				break;
			case 2:
				s=s-1;
				break;
			case 3:
				cout<<s<<endl;
				break;
			default: exit(0);
		}
	}while(ch!=0);
}

