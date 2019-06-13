#include<iostream>

using namespace std;

int sum(int x,int y)
{
	int z;
	z=x+y;
	return z;
}

int main()
{
	int a,b;
	cout<<"enter two values:"<<endl;
	cin>>a>>b;
	cout<<sum(a,b)>>endl;
}
