
#include <bits/stdc++.h>
using namespace std;
int arr[10000];

bool check(int c,int &x){
	return c<=x;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("nady.txt","rt",stdin);
    #endif
    int n;
    cin>>n;
    while(n--)
    {
          int z,x;
    bool f=0;
     for(int i=0;i<z;++i){
      cin>>arr[i];
    if(arr[i]==x){
    	 cout<<i+1<<endl;
    	f=1; 
    }
    else if(arr[i]==(x-1))
    {
    	 cout<<i+1<<endl;
    	 f=1;
    }
    else if(f==1)
    break;
	}
  
    }
}
