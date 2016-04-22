#include <bits/stdc++.h>
#include "operation.h"
using namespace std;

int main(int argc, char** argv) {
    bool check = 1;
    string fileName , id , firstName , lastName ,department, word , grade;
	int index;
	cout << "please, Enter the name of your file to open or create: ";
	getline(cin,fileName);
    while(check){
    	char option; 
		system("cls");
		File file(fileName);
    	file.projectHeader();	
    	int flag = 1;   		
    	cout<<"press (1) - to insert new record in your file: \""<<fileName<<"\""<<endl;
    	cout<<"press (2) - to update old record in your file: \""<<fileName<<"\""<<endl;
    	cout<<"press (3) - to delete old record from your file: \""<<fileName<<"\""<<endl;
    	cout<<"press (4) - to search by id for old record in your file: \""<<fileName<<"\""<<endl;
    	cout<<"press (5) - to search by other for old record in your file: \""<<fileName<<"\""<<endl;
    	cout<<"press (6) - to display all your file: \""<<fileName<<"\""<<endl;
    	cout<<"press (any other key) - to close"<<endl;
    	cout<<"\nEnter your option : ";
    	cin>>option;
    	system("cls");
    	switch(option){
    		case '1':
    			while(flag){
    				cout<<"Enter the id: ";
    			cin>>id;
    			cout<<"\nEnter the first name: ";
    			cin>>firstName;
    			cout<<"\nEnter the last name: ";
    			cin>>lastName;
    			cout<<"\nEnter the department: ";
    			cin>>department;
    			cout<<"\nEnter the total grade: ";
    			cin>>grade;
    			file.insert(id,firstName,lastName,department,grade,file.getRate(grade));
    			cout<<"\nto insert an other record press (1) in not press(0) : ";
    			cin>>flag;
    			system("cls");
    			}
    			
    			break;
    		case '2':
    			cout<<"Enter the id: ";
    			cin>>id;
    			cout<<"\nEnter the new first name: ";
    			cin>>firstName;
    			cout<<"\nEnter the new last name: ";
    			cin>>lastName;
    			cout<<"\nEnter the new department: ";
    			cin>>department;
    			cout<<"\nEnter the new total grade: ";
    			cin>>grade;
    			file.update(id,firstName,lastName,department,grade,file.getRate(grade));
    			break;
    		case '3':
    			cout<<"Enter the id: ";
    			cin>>id;
    			file.del(id);
    			break;
    		case '4':
    			cout<<"Enter the id: ";
    			cin>>id;
    			index = file.binSearchById(id);
    			if(index != -1){
    				cout<<"\n the record found in : \" "<<file.getRecord(index)<<" \""<<endl;
    			}else{
    				cout<<"\nthe record isn\'t found in your file \""<<fileName<<"\""<<endl;
    			}
    			break;
    		case '5':
    			while(flag){
    			cout<<"press (1) - to search by first name in your file: \""<<fileName<<"\""<<endl;
    			cout<<"press (2) - to search by last name in your file: \""<<fileName<<"\""<<endl;
    			cout<<"press (3) - to search by department in your file: \""<<fileName<<"\""<<endl;
    			cout<<"press (4) - to search by grade in your file: \""<<fileName<<"\""<<endl;
    			cout<<"press (5) - to search by rating in your file: \""<<fileName<<"\""<<endl;
    			cout<<"\nEnter your option: ";
    			cin>>option;
    			switch(option){
    				case '1':
    					cout<<"\nEnter the first name: ";
    					cin>>word;
    					break;
    				case '2':
    					cout<<"\nEnter the last name: ";
    					cin>>word;
    					break;
    				case '3':
    					cout<<"\nEnter the department: ";
    					cin>>word;
    					break;
    				case '4':
    					cout<<"\nEnter the grade: ";
    					cin>>word;
    					break;
    				case '5':
    					cout<<"\nEnter the rating: ";
    					cin>>word;
    					break;
    				default:
    					cout<<"\nEnter a valid choise...try again";
    					flag = 0;	
    	    	}
    	    	if(flag){
    	    		system("cls");
    	    		cout<<"\n The search results : "<<endl<<endl;
    	    		vector<string> vec = file.SearchByOther(word);
    	    		int size = vec.size();
    	    		if(size == 0){
    	    			cout<<"No results found"<<endl;
    	    		}
    	    		else
    	    		for(int i = 0 ; i < size ; ++i){
    	    			cout<<vec[i]<<endl;
    	    		}
    	    		
    	    	cout<<"\nto search again press (1) in not press(0) : ";
    			cin>>flag;
    			system("cls");
    	    	}
    			}
    			
    			break;
    		case '6':
    			file.readAllFile();
    			break;
    		default:
    			exit(0);
    	
		}
	    cout<<"\nif you want to continue press(1) if not press(0)"<<endl;
		cin>>check;
		if(check != 1){
			check = 0;
		}
		file.close();
    }
	
	return 0;
}
