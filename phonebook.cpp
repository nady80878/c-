#include <iostream>
#include<windows.h>
#include<string.h>
#include<fstream>
#include <stdio.h>

using namespace std;

class phonebook{


public:
	char Phone_number[30];
	char First_name[30];
	char Last_name[30];
	char Address[100];
	char City[30];
	char E_mail[30];
	void Start(int key);
    void All_search_normal();
	void All_search_binary();
	void Insert_new(int key);
	int Check_Phone_num(char a[30]);
	int Check_E_mail(char a[30]);
	void View();
	void Search_phone_num();
	void Search_First_name();
	void search_last_name();
	void Search_City();
	void Search_E_mail();
	void Delete_contact();
	void Update_contact();
};



void phonebook::Start(int key){
	int option ,k,pass;

	if(key==1){
	cout<<" WELCOME TO YOUR PHONEBOOK PLEASE ENTER YOUR PASSWORD";
	cin>>pass;
	if(pass==000){

		cout << "\tfor add new contact press 1:\n\tto view all contact press 2:\n\tto search press 3:\n\tto delete contact press 4:\n\tto update old  contact info press 5:\n\to print  contacts press 6:\n\tfor Exite press 7:\n ";
		cout << "\n";
		cin >> option;
		 	switch(option){
           	case 1 :

             Insert_new(1);
         break;
          case 2 :
            View();
         break;
         /*
          case 3 :
             Binary_search();
         break;
         case 4 :
            delete();
         break;
         case 5 :
            update();
         break;
         case 6 :
            print();
        */ break;

         case 7:
            cout<<"THANK YOU FOR USE PHONE BOOK";
         break;
        default :

          		cout << "\n\tto Start over again press 1:\n";
}          		cin>>k;
                Start(k);


	}
	else{
        cout<<"ERROR in the password \n";
        cout<<"to start again press1";
        cin>>k;
        Start(k);


	}

}
}


void phonebook::Insert_new(int key){
    int again;
    if(key==1){

	phonebook phone;
	ofstream Object;
	Object.open("phonebook.txt", ios::app);
	cout << "\n";
	int Ch_Phone_num ,Ch_E_mail;
		cout << "\n\t Enter phone number \n";
		cin.ignore();
		cin.getline(phone.Phone_number, 30);
		Ch_Phone_num= Check_Phone_num(phone.Phone_number);
		 cout<<Ch_Phone_num;
		 if (Ch_Phone_num == 0){
			cout << "\n\t Enter first name \n";
			cin.ignore();
			cin.getline(phone.First_name, 30);
			cout << "\n\t Enter last name \n";
			cin.ignore();
			cin.getline(phone.Last_name, 30);
			cout << "\n\t Enter Your Address \n";
			cin.ignore();
			cin.getline(phone.Address, 30);
			cout << "\n\t Enter Your City \n";
			cin.ignore();
			cin.getline(phone.City, 30);
			cout << "\n\t Enter Your  E-mail address \n";
			cin.ignore();
			cin.getline(phone.E_mail, 30);
			Ch_E_mail = Check_E_mail(phone.E_mail);
			if (Ch_E_mail == 0){
				Object << phone.Phone_number << '|' << phone.First_name << '|' << phone.Last_name << '|' << phone.Address << '|' << phone.City << '|' << phone.E_mail << '\n';
			}
			else{
                cout << "\n \a this E-mail are here before";}

 			 }

		else { cout << "\n \athis are here before"; }
		cout << "\n\t to INSERT again press 1 \n";
		cin >>again ;
	//	cin.ignore();
		Insert_new(again);

	Object.close();
}
}


int phonebook::Check_Phone_num(char a[30]){

	phonebook phone;
	fstream object;
	object.open("phonebook.txt", ios::in);
	int x = 0;
	while (!object.eof()){
		object.getline(phone.Phone_number, 30, '|');
		object.getline(phone.First_name, 30, '|');
		object.getline(phone.Last_name,30, '|');
		object.getline(phone.Address, 100, '|');
		object.getline(phone.City,30, '|');
		object.getline(phone.E_mail, 30);
		if (strcmp(phone.Phone_number, a) == 0){
			x = 1;
		}
	}
	object.close();
	if (x == 1){
	    return 1;
    }
	else{
            return 0;
    }
}
int phonebook::Check_E_mail(char a[30]){
	phonebook phone;
	fstream object;
	object.open("phonebook.txt", ios::in);
	int x = 0;
	while (!object.eof()){
		object.getline(phone.Phone_number, 30, '|');
		object.getline(phone.First_name, 30, '|');
		object.getline(phone.Last_name, 30, '|');
		object.getline(phone.Address, 100, '|');
		object.getline(phone.City, 30, '|');
		object.getline(phone.E_mail, 30);
		if (strcmp(phone.E_mail, a) == 0){
			x = 1;
		}
	}
	object.close();
	if (x == 1){ return 1; }
	else{ return 0; }

}


void phonebook::View(){
	phonebook phone;
	fstream object;
	 object.open("phonebook.txt", ios::in);

	cout << "\n\tPhoneNum\tFirstname\tLastname\tAddress\tCity\tE-mail\n";
	while (! object.eof()){
		object.getline(phone.Phone_number, 30, '|');
		object.getline(phone.First_name, 30, '|');
		object.getline(phone.Last_name, 30, '|');
		object.getline(phone.Address, 100, '|');
		object.getline(phone.City, 30, '|');
		object.getline(phone.E_mail, 30);
		cout << "\n\t" << phone.Phone_number << "\t" << phone.First_name << "\t" << phone.Last_name << "\t" << phone.Address << "\t" << phone.City << "\t" << phone.E_mail << "\n";
	}
	object.close();


}
















int main(){
	phonebook object;
	object.Start(1);
	cout << "created by \n\t\t\tStudent:- salma *** shorouk *** shimaa \n\t\t\tsec 6 \n\t\t\tto:\n\t\t\tEng::-\n\t\t\t\tHamada !" << endl;
	return 0;
}



