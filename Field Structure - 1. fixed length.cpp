/*

Field Structure
	1. Fixed length

*/


#include <iostream>
#include <fstream>
using namespace std;

struct student {
	char fname[10];
	char lname[10];
	char address[20];
};

int main(){

	// get number of students from user
	int num_of_students;
	cout << "Enter number of students: ";
	cin >> num_of_students;

	// get data from user and write it to file
	fstream out;
	out.open("file.txt", ios::out | ios::binary);
	student s;
	for(int i = 0; i < num_of_students; i++){
		// fname
		cout << "Enter first name\n";
		cin >> s.fname;
		// lname
		cout << "Enter last name\n";
		cin >> s.lname;
		// address
		cout << "Enter address\n";
		cin >> s.address;
		// write data to file
		out.write((char*)&s, sizeof(s));
	}
	out.close();


	// read data from file
	fstream in;
	in.open("file.txt", ios::in | ios::binary);
	student s2;
	int counter = 0;
	in.read((char*)&s2, sizeof(s2));
	while(!in.eof()){
		cout << "######## Student " << ++counter << " ########\n";
		cout << "fname: " << s2.fname << endl;
		cout << "lname: " << s2.lname << endl;
		cout << "address: " << s2.address << endl;
		in.read((char*)&s2, sizeof(s2));
	}
	in.close();


	system("pause");
	return 0;
}