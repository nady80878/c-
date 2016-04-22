#include<bits/stdc++.h>;
using namespace std;
int main()
{
	int t;
	while(cin>>t)
	{
		if(t==0)
		break;
		int sum=0;
		for(int i=0;i<=t;i++){
			sum+= multiplies<int>()(i,i);
		}
			cout<<sum<<endl;
	}

}
