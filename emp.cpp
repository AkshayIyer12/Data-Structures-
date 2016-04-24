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
int gross;
public:
void read_data();
void cal_data();
void print_data();
};
void employee::read_data()
{
cout<<"Enter Employee Number, Employee Name, Basic Salary"<<endl;
cin>>empno>>name>>bs;
}
void employee::cal_data()
{
alw=(123*bs)/100;
gross=bs+alw;
it=(30*gross)/100;
ns=bs+alw-it;
}
void employee::print_data()
{

cout<<empno<<"\t"<<name<<"\t"<<bs<<"\t"<<alw<<"\t"<<it<<"\t"<<ns<<endl;
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
}
for(i=0;i<n;i++)
e[i].cal_data();

cout<<"EmpNo.\t"<<"Name\t"<<"BS\t"<<"AllW\t"<<"IT\t"<<"NS"<<endl;
for(i=0;i<n;i++)
{
e[i].print_data();
}
cout<<"\n\n";
return 0;
}