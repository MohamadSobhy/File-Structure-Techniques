//////////////////////////////////////
//									//
//			Record Structure		//
//			2) Predictable number 	//
//				of fields			//
//////////////////////////////////////
/*
We know that each record has 3 fields. Idea is to place all fields for all records next to each other in the file like this:
Ahmed|Mohammed|Cairo|Ali|Ahmed|Alex|
We read 3 fields for each record.
First record:
	fname: Ahmed
	lname: Mohammed
	ciry:  Cairo
Second record:
	fname: Ali
	lname: Ahmed
	ciry:  Alex
*/

#include <iostream>
#include <fstream>
using namespace std;

// struct
struct student {
	char fname[30];
	char lname[30];
	char city[25];
};


// main
void main(){

	// getting number of students
	int num_of_students = 0;
	cout << "Enter number of students: ";
	cin >> num_of_students;

	//================= Getting data from user and writing it to the file ======================//
	student s1;
	ofstream out("file.txt");
	for(int i = 0; i < num_of_students; i++){
		// print record number
		cout << "______________ Student " << i+1 << "______________\n";

		// fname
		cout << "Enter fname: ";
		cin >> s1.fname;
		out << s1.fname << '|';

		// lname
		cout << "Enter lname: ";
		cin >> s1.lname;
		out << s1.lname << '|';

		// city
		cout << "Enter city: ";
		cin >> s1.city;
		out << s1.city << '|';
	}
	out.close();


	//================= Reading data from the file ======================//
	student s2;
	ifstream in("file.txt");
	int counter = 0;
	while(!in.eof()){

		// fname
		in.getline(s2.fname, sizeof(s2.fname), '|');
		if(in.fail()) // check end of file
			break;
		cout << "______________ Student " << ++counter << "______________\n";
		cout << "Fname: " << s2.fname << endl;

		// lname
		in.getline(s2.lname, sizeof(s2.lname), '|');
		cout << "Fname: " << s2.lname << endl;

		// city
		in.getline(s2.city, sizeof(s2.city), '|');
		cout << "Fname: " << s2.city << endl;
	}
	in.close();
	
	system("pause");
}