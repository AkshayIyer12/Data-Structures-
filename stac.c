#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 15
int top =-1;
char s[SIZE];
int prior(char ch)
{
	if(ch=='('||ch=='#')
 		return 1;
	if(ch=='+'||ch=='-')
 		return 2;
	if(ch=='*'||ch=='/')
 		return 3;
	if(ch=='$'||ch=='^')
 		return 4;
}
char pop()
{
char ele;
if(top==-1)
{
printf("\nStack Underflow!\n");
}
ele=s[top];
top--;
return ele;
}
void push(char ele)
{
if(top==(SIZE-1))
{printf("\nStack Overflow!n");
return;
}
top++;
s[top]=ele;
}
int main()
{
	char infix[SIZE],sufix[SIZE];
	int i,j=0;
	push('#');
	printf("Enter the infix expression : ");
	scanf("%s",infix);
	for(i=0;infix[i]!='\0';i++)
	{
		if(isalnum(infix[i]))
			sufix[j++]=infix[i];
		else if(infix[i]=='(')
			push(infix[i]);
		else if(infix[i]==')')
		{
			while(s[top]!='(')
			sufix[j++]=pop();
			pop();
		}
		else
		{
			while(prior(s[top])>=prior(infix[i]))
			sufix[j++]=pop();
			push(infix[i]);
		}
}
while(s[top]!='#')
sufix[j++]=pop();
sufix[j]='\0';
printf("The postfix Expression is : %s\n",sufix);
return(0);
}

