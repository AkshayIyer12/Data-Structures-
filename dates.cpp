#include<iostream>
using namespace std;
class date
{ public:	
	int mm,dd,yy;
	
	date()
	{
		mm=0;
		dd=0;
		yy=0;
	}
	date(int m,int d,int y)
	{
	mm=m;
	dd=d;
	yy=y;
	}
	date operator+(long);
	long operator-(date);
	int getdays();
	int isleap(int);
	void isvalid();
	friend istream& operator>>(istream &is,date &d);
	friend ostream& operator<<(ostream &os,date &d);
};
istream& operator>>(istream &is,date &d)
{
	is>>d.dd;
	is>>d.mm;
	is>>d.yy;
	return(is);
}
ostream& operator<<(ostream &os,date &d)
{
	os<<d.dd<<" / ";
	os<<d.mm<<" / ";
	os<<d.yy;
	return(os);
}
date date::operator+(long no_of_days)
{
	date temp;
	temp.dd=dd;
	temp.mm=mm;
	temp.yy=yy;
	temp.dd+=no_of_days;
while(temp.dd>temp.getdays())
{
	temp.dd-=temp.getdays();
	temp.mm++;
	if(temp.mm>12)
	{
		temp.yy++;
		temp.mm-=12;
	}
}
return(temp);
}
long date::operator-(date d)
{
	long no_of_days=0;
	no_of_days=dd-d.dd;
	while(yy!=d.yy)
	{
		no_of_days+=d.getdays();
		d.mm++;
		if(d.mm>12)
		{
			d.yy++;
			d.mm-=12;
		}
	}
	while(mm!=d.mm)
	{
		no_of_days+=d.getdays();
		d.mm++;
	}
	return(no_of_days);
}
int date::getdays()
{
	int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(mm==2 && isleap(yy))
		return 29;
	else
		return month[mm];
}
int date::isleap(int y)
{
	if(((y%4==0)&&(y%100!=0))||(y%400==0))
		return(1);
 
		return(0);
}
void date::isvalid()
{
	if((dd>getdays())||mm>12)
	{
		cout<<"Date is invalid"<<endl;
		exit(0);
	}
return;
}
main()
{
	date d1,d2,d3;
	long no_of_days;

	cout<<"Enter First Date: ";
	cin>>d1;
	d1.isvalid();

	cout<<"\nEnter Second Date: ";
	cin>>d2;
	d2.isvalid();

	no_of_days=d1-d2;
	cout<<"\nDifference between 2 dates ="<<no_of_days<<endl;

	cout<<"Enter the no of days to be added : ";
	cin>>no_of_days;

	d3=d1+no_of_days;
	cout<<"New date after adding "<<no_of_days<<" is "<<d3;

}






