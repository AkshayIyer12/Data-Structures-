#include<iostream>


using namespace std;
class OCTAL
{
private:
	int oct;
public:
	OCTAL(int x)
	{
		int rem=0,j=1,n;
		n=x;
		oct=0;
		while(n)
		{
			rem=n%8;
			n=n/8;
			oct=oct+rem*j;
			j*=10;
		}
	}
	int operator+(int k);
	friend ostream &operator<<(ostream &os,OCTAL);
};
int OCTAL::operator+(int k)
{
	int dec=0,j=1,rem=0,result;
	while(oct!=0)
	{
		rem=oct%10;
		oct=oct/10;
		dec=dec+rem*j;
		j*=8;
	}
	result=dec+k;
	return result;
}
ostream &operator<<(ostream &os,OCTAL o)
{
	os<<o.oct;
	return os;
}
int main()
{
	int x,k,y;
	
	cout<<"\nEnter the Number to be converted to octal"<<endl;
	cin>>x;
	OCTAL h=x;
	cout<<"\nOctal equivalent number of "<<x<<"is: "<<h;
	cout<<"\nEnter a  decimal number that needs to be added to previously entered number: ";
	cin>>k;
	y=h+k;
	cout<<"\nResult in decimal sysytem is: "<<y;
	OCTAL o(y);
	cout<<"\nResult in octal system is: "<<o;
	
	
}