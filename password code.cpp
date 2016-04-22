#include <iostream>

using namespace std;
#include <algorithm>
#include <math.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <conio.h>
class nady{
	public:
string password(){
		cout<<"please enter your user name and password (5 < digits < 20 ) \n";
	start :
    
	string s,m,f;
	char x[20],c; 
	cout<<"\n your user name : ";
	

   getline(cin,s);
	cout<<" your password : ";
	int i;
	for(i=0;;){
		c=getch();
		if((c>='a'&&c<='z')||(c>='0'&&c<='9')||(c>='A'&&c<='Z')){
		m+=x[i]=c;
			i++;
			cout<<"*";
		}
		if(c=='\b'&&i>=1){
			--i;
			cout<<"\b \b";
		}
		if(c=='\r'){
			x[i]='\0';
		break;
			
		}
	}
		if(i<=5){
				cout<<"\nMinimum 6 digits needed.\nEnter Again\n";
				goto start;
			}
				f="";
				f=s+" "+m;
			s="";
				system("cls");
				
			return f;
				
}
}nad;
int main(int argc, char** argv) {
//freopen("text.txt","rt",stdin);

   /* START:
    system("cls");
    string s;
    getline(cin,s);
    cout<<"\nEnter Password  : ";
    char pass[32];//to store password.
    int i = 0;
    char a;//a Temp char
    for(i=0;;)//infinite loop
    {
        a=getch();//stores char typed in a
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        //check if a is numeric or alphabet
        {
            pass[i]=a;//stores a in pass
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//if user typed backspace
        //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            pass[i]='\0';//null means end of string.
            break;//break the loop
        }
    }
    cout<<"\nYou entered : "<<pass;
    //here we can even check for minimum digits needed
    if(i<=5)
    {
        cout<<"\nMinimum 6 digits needed.\nEnter Again";
        getch();//It was not pausing 
        goto START;
    }*/
  
//Lets check for errors.
//You can even put file system.*/
/*string s="123456789";
cout<<s.substr(0,9);*/
cout<<nad.password();
cout<<nad.password();

  return 0;
  
}
