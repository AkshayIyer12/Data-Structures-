#include<stdio.h>
#define MAX 3
int r=-1;
int f=-1;
int Q[MAX];
void insert();
void delete();
void display();
int main()
{
do
{
int ch;
printf("Press 1 for Insertion\nPress 2 for Deletion\nPress 3 for Display\n");
scanf("%d",&ch);
switch(ch)
{
case 1:insert();
	break;
case 2:delete();
	break;
case 3:display();
	break;
default: printf("Wrong Input\n");
}
}while(!0);
return (0);
}
void insert()
{
int ele;
printf("Enter element\n");
scanf("%d",&ele);
if(r==(MAX-1))
printf("Queue is full element\n");
else
Q[++r]=ele;
}
void delete()
{
if(r==f)
printf("Queue is empty\n");
else
printf("Element deleted is %d\n",Q[++f]);
}
void display()
{
int i=0;
if(f==-1&&r==-1)
printf("Queue is empty\n");
else
for(i=f+1;i<=r;i++)
printf("%d\t",Q[i]);
}
