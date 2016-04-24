#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 25
int stack[MAX];
int top=-1;
void push(int ele)
{
	stack[++top]=ele;
}
int pop()
{
	int temp;
	temp=stack[top--];
	return(temp);
}
main()
{
	char postfix[MAX],ch;
	int i=0;
	int op1,op2;
	printf("Enter the Expression\n");
	scanf("%s",postfix);
	while(postfix[i]!='\0')
	{	ch=postfix[i];
		i++;
		if(isdigit(ch))
			push(ch-'0');
		else
		{
			op2=pop();
			op1=pop();
		switch(ch)
		{
			case '+': push(op1+op2);
	  				break;
			case '-': push(op1-op2);
	  				break;
			case '*': push(op1*op2);
	  				break;
			case '/': push(op1/op2);
	  				break;
		}
		}
	}
printf("\nResult of stack is %d\n",stack[top]);
}