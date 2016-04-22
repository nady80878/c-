#include "operation.h"
#include <bits/stdc++.h>
using namespace std;

File::File(string &fileName ){
	if(fileName.find(".txt")==-1)
	this->fileName = fileName+".txt";
	else
	this->fileName = fileName;
	loadFile();
}

File::~File(){
	system("cls");
	cout<<"Thanks for using our control system program ..."<<endl;
}
/**
* display some information about the project
* coder name @author nady shalaby
* project name 
* file size
*/
void File::projectHeader(){
	cout<<"coder : Nady sopieh shalaby "<<endl;
	cout<<"The project Name : control system "<<endl;
	ifstream file(fileName.c_str());
	file.seekg(0 , ios::end);
	cout<<"The file size: "<<file.tellg()<<" byte"<<endl;
	cout<<"****************(^_^)****************"<<endl;
	file.close();
}

/**
* take the student grade 
* and return his rating 
* (passed , good , very good , excellent , ...)
*/
string File::getRate(string &grade){
	stringstream ss(grade);
	int grad ; 
	ss>>grad;
	string word;
	if(grad >= 50 && grad < 64 )
	word = "passed";
	else if(grad >= 64 && grad < 74 )
	word = "good";
	else if(grad >= 74 && grad < 84 )
	word = "very good";
	else if(grad >= 84  )
	word = "excellent";
	else
	word = "bad";
	return word;
}

/**
* insert records in the database file
* check for pervious existing records
*/

void File::insert(string &studentId , string &firstName, string &lastName, string &department, string &totalGrade , string rating){
	string str = studentId+"|"+firstName+"|"+lastName+"|"+department+"|"+totalGrade+"|"+rating;
	if (binSearchById(studentId) > -1){
		cout << "Sorry , can't insert it , the record already exists..."<< endl;
		return;
	}
	int size = data.size();
	for(int i = 0 ; i < size ; ++i){
		if(studentId.compare(data[i].first) < 0){
			data.insert(data.begin()+i , make_pair(studentId,str));
			cout<<"\nthe record inserted successfully..."<<endl;
			return;
       }
	}
	//if the vector is empty or there isn't value larger than the id insert at last
	data.push_back(make_pair(studentId,str));
	cout<<"\nthe record inserted successfully..."<<endl;	
}
	

/**
*reading the whole file buffer
*/
void File::readAllFile(){
	updateDataFile();
	ifstream file(fileName.c_str());
	cout<<"press (1) - to display the file in note pad . "<<endl;
	cout<<"press (2) - to display the file in cmd . "<<endl;
	cout<<"press (3) - to display the file in cmd in table form. \nEnter your choise: "<<endl;
	int check ;
	cin>>check;
	if(check == 1){
		string command = "notepad "+fileName;
		system(command.c_str());
	}	
	else if(check == 2){
		cout<<"The file \""<<fileName<<"\" content: "<<endl<<endl;
		cout<< file.rdbuf();
	}
	else
	displayTable();
	
}

/**
* loading the index file in the index vector 
* sort the index vector*/
void File::loadFile(){
	string str;
	ifstream file(fileName.c_str());
	while(getline(file , str)){		
		data.push_back(make_pair(getID(str) , str));	 
	}
	file.close();
}

/**
* take the record string and get the id field
*/

string File::getID(string& str){	
	return str.substr(0 , str.find("|"));
}

string File::getRecord(int& index){
	return data[index].second;
}

/**
* invoke the updateDataFile method
* that rewrite the vector data sorted in data file
*/

void File::close(){
	updateDataFile();
}

/**
* take the new record 
* check if it exists or not 
* if it exists update the old record with the new one
*/

void File::update(string &studentId , string &firstName, string &lastName, string &department, string &totalGrade , string rating){
	string str = studentId+"|"+firstName+"|"+lastName+"|"+department+"|"+totalGrade+"|"+rating;
	int index = 0;
	if ((index = binSearchById(studentId)) > -1){
		data[index] = make_pair(studentId , str);
		cout << "\nthe update is done correctly..."<< endl;
		return;
	}
	
	cout << "Sorry , can't update it , the record doesn\'t exist..."<< endl;
}

/**
* take the id 
* check if the id exists or not 
* if it exists delete its record
*/

void File::del(string& id){
	int index = 0;
		if ((index = binSearchById(id)) > -1){
	         data.erase(data.begin()+index);
		cout << "the delete is done correctly..."<< endl;
		return;
	    }
	
	cout << "Sorry , can't delete it , the record doesn\'t exist..."<< endl;

}
/**
* rewrite the vector data sorted in data file
*/

void File::updateDataFile(){
	int size = data.size();
	ofstream file(fileName.c_str());
	for(int i  = 0 ; i < size ; ++i){
		file<<data[i].second<<endl;
	}
	file.close();
}


/**
* printing the file content in form of table of data
*/
void File::displayTable(){
	cout<<"-------------------------------------------------------------------------------"<<endl;
	cout<<"|     ID       |  first name |   last name |  department |  grade      |rating "<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
	for (int i = 0 ; i < data.size() ; ++i){
		int index = -1;
		int current = 0;
		string word;
		cout<<"|";
		while(data[i].second.find("|",index+1,1) != -1){
			index = data[i].second.find("|",index+1,1);
			word = data[i].second.substr( current , index-current);
			current=index;
			int size = 14- word.length();
			cout<<word;
			for(int j = 0 ; j < size ; ++j)
			cout<<" ";
		}
		word = data[i].second.substr( current);
		cout<<word<<endl;
	cout<<"--------------------------------------------------------------------------------";
	}
}

/**
* binary search for the specified record in the data vector
*/
int File::binSearchById(string& id){
	
	int low = 0 , high = data.size()-1;
	while(low<=high){
		int mid = (low+high)/2;
		if(id.compare(data[mid].first) == 0)
		return mid;
		else if(id.compare(data[mid].first) > 0)
		low= mid + 1;
		else
		high = mid - 1;
	}
	
	return -1;	
}

/**
* sequential search for other fields in data vector
*/
vector<string> File::SearchByOther(string & word){
	vector<string> vec;
	int size = data.size();
	for(int i = 0 ; i < size ; ++i){
		if(data[i].second.find(word) != -1){
			vec.push_back(data[i].second);
		}
		
	}
	return vec;
} 

