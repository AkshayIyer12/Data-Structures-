#include<iostream>
#include<iomanip>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node *NODE;
class bin_tree
{
	NODE root;
public:
	bin_tree();
	void insert(int);
	void inorder(NODE);
	void preorder(NODE);
	void postorder(NODE);
	NODE getroot();
};
bin_tree::bin_tree()
{
	root=NULL;
}
void bin_tree::insert(int ele)
{
	NODE newnode;
	newnode = new struct node;
	newnode->data=ele;
	newnode->left=newnode->right=NULL;
	if(root==NULL)
	{
		root=newnode;
		return;
	}
	NODE cur= root,prev;
	while(cur)
	{
		prev=cur;
		if(ele < cur->data)
			cur=cur->left;
		else
			cur=cur->right;
	}
	if(ele < prev-> data)
		prev->left=newnode ;
	else 
		prev->right=newnode;
}
void bin_tree::preorder(NODE root)
{
	if(root)
	{
		cout<<root->data<<setw(5);
		preorder(root->left);
		preorder(root->right);
	}
}
void bin_tree::inorder(NODE root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<setw(5);
		inorder(root->right);
	}
}
void bin_tree::postorder(NODE root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<setw(5);
	}
}
NODE bin_tree::getroot()
{
	return root;
}
int main()
{
	bin_tree b;
	int ch,ele;
	do
	{
		cout<<endl<<"Binary Tree Operations:"<<endl<<"Press 1 for Insert\nPress 2 for Preorder\nPress 3 for Inorder\nPress 4 for Postorder"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter an Element to Insert:";
				cin>>ele;
				b.insert(ele);
				break;
			case 2:
				cout<<"****PreOrder****"<<endl<<endl;
				b.preorder(b.getroot());
				break;
			case 3:
				cout<<"****InOrder****"<<endl<<endl;
				b.inorder(b.getroot());
				break;
				
			case 4:
				cout<<"****PostOrder****"<<endl<<endl;
				b.postorder(b.getroot());
				break;
				
			default: exit(1);
		}
	}while(1);
}


