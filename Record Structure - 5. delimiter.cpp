//////////////////////////////////////
//									//
//			Record Structure		//
//			5) Delimiter			//
//									//
//////////////////////////////////////

/*
Seperate records by #
seperate fields by |
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
	ofstream out("file.txt");
	student s1;
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

		// record delimiter
		out << '#';

	}
	out.close();

	// ============================= reading data from the file =============================================
	char buffer[100];
	int counter = 0; // to count records as we read them
	student s2;
	ifstream in("file.txt");
	while(!in.eof()){

		// read record into buffer
		in.getline(buffer, sizeof(buffer), '#');

		// check end of file
		if(in.fail())
			break;
	
		//***************** read fields from the buffer ********************//
		cout << "______________ Student " << ++counter << "______________\n";
		int i, j;
		// fname
		i = 0;
		j = 0;
		while(buffer[i] != '|'){
			s2.fname[j] = buffer[i];
			i++;
			j++;
		}
		s2.fname[j] = '\0';
		cout << "Fname: " << s2.fname << endl;
		// lname
		i++; // skip the delimiter '|'
		j = 0; // reset j
		while(buffer[i] != '|'){
			s2.lname[j] = buffer[i];
			i++;
			j++;
		}
		s2.lname[j] = '\0';
		cout << "Lname: " << s2.lname << endl;
		// city
		i++; // skip the delimiter '|'
		j = 0; // reset j
		while(buffer[i] != '|'){
			s2.city[j] = buffer[i];
			i++;
			j++;
		}
		s2.city[j] = '\0';
		cout << "City: " << s2.city << endl;
		//************************************************************//
	}
	in.close();

	system("pause");
}