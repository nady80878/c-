#ifndef OPERATION_H
#define OPERATION_H
#include <bits/stdc++.h>
using namespace std;
class File{
private:
	string  fileName;
	vector<pair<string , string > > data;
	string getID(string&);
	void loadFile();
	void updateDataFile();
	void displayTable();
	
public:
    File(string&);
	int binSearchById(string&);
	vector<string> SearchByOther(string&); 
	string getRecord(int&);
	string getRate(string&);
	void projectHeader();	
	void insert (string & , string &, string &, string &, string & , string );
	void update (string & , string &, string &, string &, string & , string );
	void del (string&);
	void readAllFile();
	void close();
    ~File();
};
#endif
