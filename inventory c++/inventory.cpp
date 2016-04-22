#include <iostream>
#include <fstream>
#include <vector>
#include<windows.h>
#include <string.h>
using namespace std;

class inventory{
private:
	vector<pair< string , string> > vec;
	
	void updateRecord(char Item_Id[20],string record){
	int index = binarySearch(Item_Id);
	vec[index] = make_pair(string(Item_Id),record);
	}
	
	string getRecord(char Item_Id[10],char Item_Name[20],char Item_Amount[20],char Price[20],char Type[20],char Shelf_Number[20]){
		string record;
		record.append(Item_Id);
		record.append("|");
		record.append(Item_Name);
		record.append("|");
		record.append(Item_Amount);
		record.append("|");
		record.append(Price);
		record.append("|");
		record.append(Type);
		record.append("|");
		record.append(Shelf_Number);
		return record;
	}

public:
	string getRecordData(int index){
		return vec[index].second;
	}
	void loadFile(){	
		char Item_Id[20];
		char Item_Name[20];
		char Item_Amount[20];
		char Price[20];
		char Type[20];
		char Shelf_Number[20];
		ifstream file("inventory.txt");
		while(!file.eof()){
			file.getline(Item_Id , 20 , '|' );
			file.getline(Item_Name , 20 , '|' );
			file.getline(Item_Amount , 20 , '|' );
			file.getline(Price , 20 , '|' );
			file.getline(Type , 20 , '|' );
			file.getline(Shelf_Number , 20 , '\n' );
			if(strcmp(Item_Id,"") != 0){
			string record  = getRecord(Item_Id,Item_Name,Item_Amount,Price,Type,Shelf_Number);
		    vec.push_back(make_pair(string(Item_Id) , record));
			}
			
		}
		file.close();
	}
	
	void insert(char Item_Id[20],char Item_Name[20],char Item_Amount[20],char Price[20],char Type[20],char Shelf_Number[20]){
      string record = getRecord(Item_Id,Item_Name,Item_Amount,Price,Type,Shelf_Number);
		if(binarySearch(Item_Id) == -1){
			for(int  i = 0 ; i < vec.size() ; ++i){			
			if(strcmp(Item_Id , vec[i].first.c_str()) < 0){
				vec.insert(vec.begin()+i , make_pair(string(Item_Id) , record));
				return;
			}
		}
		vec.push_back(make_pair(string(Item_Id) , record));
		}
		else{
			updateRecord(Item_Id , record);
		}	
		
	}
	
	void update (char Item_Id[20],char Item_Name[20],char Item_Amount[20],char Price[20],char Type[20],char Shelf_Number[20]){
		string record = getRecord(Item_Id,Item_Name,Item_Amount,Price,Type,Shelf_Number);
		int index = binarySearch(Item_Id);
		if(index == -1){
			cout<<"The record doesn't exist"<<endl;
		}
		else{
			updateRecord(Item_Id , record);
			cout<<"the record deleted successfully..."<<endl;
		}
			
	}
	
	
	void del (char Item_Id[20]){
	int index = binarySearch(Item_Id);
	if(index == -1){
		cout<<"The record doesn't exist"<<endl;
	}
	else{
		vec.erase(vec.begin() + index);
		cout<<"the record updated successfully..."<<endl;
	}
	
	}
	
	
	
	int binarySearch(char Item_Id[20]){
		
		int low = 0 , high = vec.size() - 1;
		while(low <= high){
			int mid = (low+high)/2;
			if(strcmp(Item_Id , vec[mid].first.c_str()) == 0)
			return mid;
			else if (strcmp(Item_Id , vec[mid].first.c_str()) < 0)
			high = mid - 1;
			else
			low = mid + 1; 
		}
		
		return -1 ;
	}
	
	void printTable(){
	cout<<"-------------------------------------------------------------------------------"<<endl;
	cout<<"|     ID       |name         |amount       |price        |type         |shelf   ";
    cout<<"-------------------------------------------------------------------------------"<<endl;
	for (int i = 0 ; i < vec.size() ; ++i){
		int index = -1;
		int current = 0;
		string word;
		cout<<"|";
		while(vec[i].second.find("|",index+1,1) != -1){
			index = vec[i].second.find("|",index+1,1);
			word = vec[i].second.substr( current , index-current);
			current=index;
			int size = 14- word.length();
			cout<<word;
			for(int j = 0 ; j < size ; ++j)
			cout<<" ";
		}
		word = vec[i].second.substr( current);
		cout<<word<<endl;
	cout<<"--------------------------------------------------------------------------------";
	}
	}

   void readFile(){
   for(int i = 0 ; i < vec.size() ; ++i){
   	cout<<vec[i].second<<endl;
   }
   }
   
   void rewriteFile(){
   	ofstream file ("inventory.txt");
   	for(int i = 0 ; i < vec.size() ; ++i){
   	file<<vec[i].second<<endl;
    }
    file.close();
   }		
};
int main(){
	inventory invent;
	invent.loadFile();
    bool flag = 1;
	while(flag){
	char Item_Id[20];
	char Item_Name[20];
	char Item_Amount[20];
	char Price[20];
	char Type[20];
	char Shelf_Number[20];
	
	int x;
	cout<<"PRESS THE NUMBER OF BROCESS YOU WANT:-"<<endl;
	cout<<" to read file press (1)"<<endl<<"to insert a record press (2)"<<endl<<"to search for record press (3)"<<endl<< "to delete record press (4)"<<endl<<"to update record press (5)"<<endl ;
	cin>>x;

	if(x==1){
	invent.printTable();
	}
	else if(x==2){
	cout<<"ENTER THE ITEM ID IN THE FORM nn-nnn-nnn :";
	cin>>Item_Id;
	cout<<"ENTER THE ITEM NAME : "<<endl;
	cin>>Item_Name;
	cout<<"ENTER THE ITEM AMOUNT: "<<endl;
	cin>>Item_Amount;
	cout<<"ENTER THE ITEM PRICE: "<<endl;
	cin>>Price;
	cout<<"ENTER THE ITEM TYPE : "<<endl;
	cin>>Type;
	cout<<"ENTER THE SHELF NUMBER: "<<endl;
	cin>>Shelf_Number;
	invent.insert(Item_Id, Item_Name, Item_Amount, Price, Type,Shelf_Number);
	}
	else if(x==3){
		cout<<"enter id of record you want search for: ";
		cin>>Item_Id;
		int index = invent.binarySearch(Item_Id);
		if(index != -1)
		cout<<"\nthe search results : "<<invent.getRecordData(index)<<endl;
		else
		cout<<"\nthe record not found"<<endl;	
	}
	else if(x==4)
	{
		cout<<"enter id of record you want delete: ";
		cin>>Item_Id;
		invent.del(Item_Id);
	}
	else {
		
	cout<<"ENTER THE ITEM ID IN THE FORM nn-nnn-nnn :";
	cin>>Item_Id;
	cout<<"ENTER THE ITEM NAME : "<<endl;
	cin>>Item_Name;
	cout<<"ENTER THE ITEM AMOUNT: "<<endl;
	cin>>Item_Amount;
	cout<<"ENTER THE ITEM PRICE: "<<endl;
	cin>>Price;
	cout<<"ENTER THE ITEM TYPE : "<<endl;
	cin>>Type;
	cout<<"ENTER THE SHELF NUMBER: "<<endl;
	cin>>Shelf_Number;
	
	invent.update( Item_Id, Item_Name, Item_Amount, Price, Type,Shelf_Number);
	
	}
 
cout<<"if you want to continue press (1) if not press (0) : ";
cin>>flag;	
system("cls");
}
	
invent.rewriteFile();
}
