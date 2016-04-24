#include<iostream>
using namespace std;
class employee
{
private:
char name[10];
int empno;
int bs;
int alw;
int it;
int ns;
public:
void read_data();
void cal_data();
void print_data();
};
void employee::read_data()
{
cout<<"Enter Employee Number\n"<<"Enter Employee Name\n"<<"\nEnter the Basic Salary"<<endl;
cin>>empno>>name>>bs;
}
void employee::cal_data()
{
int gross;
alw=(123*bs)/100;
gross=bs+alw;
it=(30*gross)/100;
ns=bs+alw-it;
}
void employee::print_data()
{
cout<<"Employee No.\t"<<"Name\t"<<"Basic Salary\t"<<"Allowances\t"<<"Gross Salary\t"<<"Income Tax\t"<<"Net Salary"<<endl;
cout<<empno<<"\t"<<name<<"\t"<<bs<<"\t"<<alw<<"\t"<<gross<<"\t"<<it<<"\t"<<ns<<endl;
}
int main()
{
employee e[20];
int n,i;
cout<<"Enter the number of Employees"<<endl;
cin>>n;
cout<<"Enter the details of the Employee"<<endl;
for(i=0;i<n;i++)
{
e[i].read_data();
e[i].cal_data();
e[i].print_data();
}
cout<<"\n\n";
return 0;
}

















