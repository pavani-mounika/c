#include<iostream>

using namespace std;

int main()
{
	int s,i;
	cout<<"enter s"<<endl;
	cin>>s;
	int arr[s];
	cout<<"wrinting data in arr"<<endl;
	for(i=0;i<s;i++)
		cin>>arr[i];
	cout<<"reading data from arr"<<endl;
	for(i=0;i<s;i++)
		cout<<arr[i]<<"\t";
	cout<<endl;
}
