#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
using namespace std;

class nady{
	public:
string password(){
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

int main(){
	
	cout<<"* insert 1 to add new student\n";
	cout<<"* insert 2 search a student \n";
	cout<<"* insert 3 to delete a student record\n";
	cout<<"* insert 4 to know a student degrees and percent and your table\n";
	cout<<"* insert 5 to update data of a student\n";
	q3 :
	cout<<"\t\t---------------------------------------"<<endl<<" enter your choise : ";
	char x1;
	cin>>x1;
	cin.ignore();
if(x1=='1'){
	cout<<"please enter the new data like (user name_password_d1_d2_d3_d4_d5_group number)\n";
		ofstream myfile("test.txt",ios::app);
		string s10;
		while(getline(cin,s10)){
			myfile<<s10<<endl;
		}
		myfile.close();
	}	
else if(x1=='2'){
		q1:
			ifstream myfile1("test.txt");
		string s2,g2,r1,r2,r4;
		int a=0;
	    cout<<" enter the name you want to search : ";
	   getline(cin,g2);
		while(getline(myfile1,s2)){
		if(s2.find(g2)==0){
			r4="";
			stringstream ss(s2);
			ss>>r1>>r2;
			r4=r1+" "+r2;
			cout<<"\nthe student name : "<<r4;
			a=1;
		}		
		}
		if(a==1){
			cout<<"\n=====================\nthe student exist!\n"<<endl;
		}
		else{
			cout<<"\n=====================\nthe student not exist!\n"<<endl;
			}
		myfile1.close();
		}
			else if(x1=='3'){
			
					ifstream myfile2("test.txt");;
					ofstream myfile3("text.txt");
	
		string s3,g3,r1,r2,r3,r4;
		g3=nad.password();
		while(getline(myfile2,s3)){
		if(s3.find(g3)==0){
				r4="";
			stringstream ss(s3);
			ss>>r1>>r2>>r3;
			r4=r1+" "+r2+" "+r3;
			if(r4==g3){
		continue;
		}}
		myfile3<<s3<<endl;
		}
		cout<<"\n\ndone !!\n";
		myfile3.close();
		myfile2.close();
		if(remove("test.txt")==0)
		rename("text.txt","test.txt");
		
	}
			else if(x1=='4'){
				q10 :
						ifstream myfile4("test.txt");
		string s4,g5,g6,r1,r2,r3,r4;
		float z1,z2,z3,z4,z5,z6,sum=0,percent;
			g6=nad.password();
			int a=0;
		while(getline(myfile4,s4)){
		    	if(s4.find(g6)==0){
		    			r4="";
			stringstream ss(s4);
			ss>>r1>>r2>>r3;
			r4=r1+" "+r2+" "+r3;
			if(r4==g6){
					stringstream ss(s4);
				ss>>g5>>g5>>g5>>z1>>z2>>z3>>z4>>z5>>z6;
					sum=z1+z2+z3+z4+z5;
					percent=(sum/500)*100;
					cout<<"\n================================your degree==============================\n";
					cout<<"\nphysics : "<<z1<<endl<<"\nmaths 2 : "<<z2<<endl<<"\nprobability : "<<z3<<endl<<"\nlogic : "<<z4<<endl<<"\nalogrithm : "<<z5<<endl<<"\nsum : " <<sum<<ends<<"\tpercent : "<<percent<<"%"<<endl;
				a=1;
				break;
				}
		}}
	
			if(a!=1){
			cout<<"\n\nenter agood information.........try again\n";
				goto q10;
			}
		else{
		cout<<"\n\n================================your table==============================\n\n";
			if(z6==1){
				ifstream myfile5("text1.txt");
				cout<<myfile5.rdbuf();
				myfile5.close();	
	        	}
	    else{
			ifstream myfile5("text2.txt");
				cout<<myfile5.rdbuf();
				myfile5.close();	
         	}}
	myfile4.close();
}
			else if(x1=='5'){
				q5:
							ifstream myfile6("test.txt");
					ofstream myfile7("text.txt");
	int a=0;
		string s5,g7,g8,r1,r2,r3,r4;
		g7=nad.password();
		while(getline(myfile6,s5)){	
		if(s5.find(g7)==0){
			r4="";
			stringstream ss(s5);
			ss>>r1>>r2>>r3;
			r4=r1+" "+r2+" "+r3;
			if(r4==g7){
			cout<<"\n\nthe old data : " <<s5<<endl;
			a=1;
		continue;
		}}
		myfile7<<s5<<endl;
		}
		if(a==1){
		cout<<"enter the new data : ";
		getline(cin,g8);
		myfile7<<g8<<endl;
		cout<<"\ndone !!\n";
	
       }
       else{
       cout<<"\n\nenter a valid information......try again\n\n";
       
	   			}

				   			goto q5;
	myfile7.close();
		myfile6.close();
		if(remove("test.txt")==0)
		rename("text.txt","test.txt");
	}
	else{
							cout<<"\nenter a valid choise......try again\n";
							goto q3;
}
		
		
	return 0;
}
