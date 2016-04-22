#include<bits/stdc++.h>
using namespace std;
int main()
{

int array[4];
for(int i=0;i<4;++i)
cin>>array[i];
int temp;
for(int i=0;i<3;++i){
	for(int j=i+1;j<4;++j)
	{
		if (array[j]<array[i])
		{
			temp=array[j];
			array[j]=array[i];
			array[i]=temp;
		}
	}
}
for(int i=0;i<4;++i)
cout<<array[i]<<" ";
}
