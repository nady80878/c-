#include<bits/stdc++.h>

using namespace std;

int main(){
float x;
cin>>fixed>>setprecision(2);
cin>>x;
cout<<"NOTAS:"<<endl;
int a=x/100;
x-=a*100;
cout<<a<<" nota(s) de R$ 100.00"<<endl;

int b=x/50;
x-=b*50;
cout<<b<<" nota(s) de R$ 50.00"<<endl;

int c=x/20;
x-=c*20;
cout<<c<<" nota(s) de R$ 20.00"<<endl;

int d=x/10;
x-=d*10;
cout<<d<<" nota(s) de R$ 10.00"<<endl;

int e=x/5;
x-=e*5;
cout<<e<<" nota(s) de R$ 5.00"<<endl;

int f=x/2;
x-=f*2;
cout<<f<<" nota(s) de R$ 2.00"<<endl;
cout<<"MOEDAS:"<<endl;
int g=x/1;
x-=g*1;
cout<<g<<" moeda(s) de R$ 1.00"<<endl;

int h=x/0.50;
x-=h*0.50;
cout<<h<<" moeda(s) de R$ 0.50"<<endl;

int i=x/0.25;
x-=i*0.25;
cout<<i<<" moeda(s) de R$ 0.25"<<endl;

int j=x/0.10;
x-=j*0.10;
cout<<j<<" moeda(s) de R$ 0.10"<<endl;

int k=x/0.05;
x-=k*0.05;
cout<<k<<" moeda(s) de R$ 0.05"<<endl;

int l=(x/0.01);
cout<<l<<" moeda(s) de R$ 0.01"<<endl;

}
