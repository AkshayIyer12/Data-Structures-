#include<iostream>
using namespace std;
struct node
{
	int info;
	struct node *next;
};
class LIST
{
	struct node *head;
	public:
		LIST()
		{
			head=NULL;
		}
		void insert(int n);
		void delet();
		void display();
};
void LIST::insert(int n)
{
	struct node*p;
	p=new struct node;
	p->info=n;
	p->next=head;
	head=p;
}
void LIST::delet()
{
	struct node*p;
	p=head;
	if(head==NULL)
	{
		cout<<"List is Empty "<<endl;
	}
	else
	{
		head=head->next;
		cout<<"Deleted Element is "<<p->info;
	}
}
void LIST::display()
{
	struct node *head1;
	if(head==NULL)
	{
		cout<<"List is Empty"<<endl;
	}
	else
	{
		head1=head;
		while(head!=NULL)
		{
			cout<<head->info<<"\t";
			head=head->next;
		}
		head=head1;
	}
}
int main(int argc,char *argv[])
{
	LIST ob;
	int n,ch;
	do
	{
		cout<<"\nEnter Your choice\n1.Insertion\n2.Deletion\n3.Display"<<endl;
		cin>>ch;
		switch(ch)
		{
		 	case 1:cout<<"Enter the Value"<<endl;
				cin>>n;
				ob.insert(n);
				break;
			case 2:ob.delet();
				break;
			case 3: ob.display();
				break;
			default: exit(0);
		}
	}while(ch!=0);
return EXIT_SUCCESS;
}