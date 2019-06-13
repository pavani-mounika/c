#include<iostream>

using namespace std;

int fun(int *x,int *y)
{
	*x=*x+10;
	*y=*y+10;
}

int main()
{
	int a,b;
	cout<<"enter a and b vals"<<endl;
	cin>>a>>b;
	fun(&a,&b);
	cout<<"val of a:"<<a<<endl<<"val of b:"<<b<<endl;
}
