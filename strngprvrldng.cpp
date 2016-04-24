#include<iostream>
using namespace std;
class STRING
{
	char s[30];
public:
	STRING()
	{
		strcpy(s," ");
	}
	STRING(char t[30])
	{
		strcpy(s,t);
	}
	STRING(const STRING &a)
	{
		strcpy(s,a.s);
	}
	friend STRING operator+(STRING s1,STRING s2);
	
	friend ostream& operator<<(ostream &dout,STRING &t);
	
};
	STRING operator+(STRING s1,STRING s2)
	{
		STRING s3;
		strcpy(s3.s,s1.s);
		strcat(s3.s," ");
		strcat(s3.s,s2.s);
		return(s3);
	}
	ostream& operator<<(ostream &dout,STRING &t)
	{
		dout<<t.s<<endl;
	}
int main()
{
STRING s1("BELGAUM"), s2("VTU"), s3;
cout<<"String S1: "<<s1<<endl;
cout<<"String S2: "<<s2<<endl;
s3=s1 + s2;
cout<<"String S3: "<<s3;
return(1);
} 