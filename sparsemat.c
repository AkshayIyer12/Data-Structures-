#ifdef HAVE_CONFIG_H
#include<config.h>
#endif
#include<stdio.h>
#include<stdlib.h>
#define MAX 25
typedef struct
{
	int col,row,value;
}term;
void creatsm(term a[],int r, int c)
{
	int i,j,ti,ch,k,co,column,ele;
	a[0].col=c;
	a[0].row=r;
	a[0].value=0;
	ti=1;
	for(i=0,j=0;j<r&&i<r*c;j++,i+=c)
	{
		printf("Do you have any non-zero element for the row %d\n",j);
		printf("For YES Press 1 and For NO Press 0::");
		scanf("%d",&ch);
		if(ch==0)
			continue;
		else
		{ 
			printf("How many non-zero elements are in row %d\n",j);
			scanf("%d",&co);
			for(k=0;k<co;k++)
			{
				printf("\nEnter column and value");
				scanf("%d%d",&column,&ele);
				a[ti].value=ele;
				a[0].value++;
				a[ti].col=column;
				a[ti].row=j;
				ti++;
			}
		}
	}
}
void search(term a[])
{
	int i,key,z=0;
	printf("Enter key element you want to search\n");
	scanf("%d",&key);
	for(i=1;i<=a[0].value;i++)
	{
		if(a[i].value==key)
		{
			z=z+1;
			break;
		}	
	}
	if(z==1)
		printf("Value %d found at ROW %d and COLUMN %d\n",a[i].value,a[i].row,a[i].col);
	else
		 printf("Value not found\n");
}
int main()
{
	term a[MAX+1];
	int m,n,ch;
	printf("Enter the order of matrix\n");
	
	scanf("%d%d",&m,&n);
	
	printf("\nEnter the Sparse Matrix\n");
	creatsm(a,m,n);
	search(a);
	return EXIT_SUCCESS;
}

