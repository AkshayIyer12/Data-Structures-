#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int h[MAX];
int n=0;
void insert(int ele)
{
	int childpo,parentpo;
	childpo=n;
	parentpo=(childpo-1)/2;
	h[childpo]=ele;
	while(childpo!=0 && h[childpo]>h[parentpo])
	{
		h[childpo]=h[parentpo];
		h[parentpo]=ele;
		childpo=parentpo;
		parentpo=(childpo-1)/2;
	}
	h[childpo]=ele;
	n=n+1;
}

void display()
{
	int i;
	printf("Elements of the heap are: \n");
	for(i=0;i<n;i++)
	{
		printf("%d \n",h[i]);
	}
}
int main()
{
	int ch,ele;
	do
	{
		printf("1.INSERT\n2.DISPLAY\n3.EXIT\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the element to be inserted\n");
				scanf("%d",&ele);
				insert(ele);
				break;
			case 2: display();
				break;
			default: exit(0);

		}
	}while(1);
}	