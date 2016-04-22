
#include<stdio.h>
int main(){

int arr[5]={0};
for(int i = 0 ; i < 5;++i)
scanf("%d",&arr[i]);
int max = arr[0];
for(int i = 0 ; i < 5;++i)
if(max < arr[i])
max = arr[i];

printf("The max : %d ",max);
}



























/*
 * Author : nady sopieh shalaby
 *
 * topic : bubble sort (c++)
 *
 * 
#include<bits/stdc++.h>
#define ll long long
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()
#define loop(i,n) for(int i=0;i<n;++i)
#define cloop(i,j,n) for(int i=j;i<=n;++i)
using namespace std;
int main(){
	freopen("nady.txt","r",stdin);
	int Num;
	while(cin>>Num){
		int res = ((((((Num*567)/9)+7492)*235)/47)-498);
		printf("%d\n",res);
	}
return 0;
}

*/

