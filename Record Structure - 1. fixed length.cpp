//////////////////////////////////////
//									//
//			Record Structure		//
//			1) Fixed length			//
//									//
//////////////////////////////////////

/*
We fix the size of the record as 100 bytes
We store all fields of one record in a char array called buffer with size = 100
For example: we store the fields in the buffer as:
	"Ahmed|Mohammed|Cairo"
This takes 20 bytes of the buffer. So, we fill the remaining 80 bytes with spaces
	"Ahmed|Mohammed|Cairo<---- Spaces ----->"
In this way, the record size will always be 100 bytes
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
	char buffer[100];
	for(int i = 0; i < num_of_students; i++){
		// print record number
		cout << "______________ Student " << i+1 << "______________\n";

		// fname
		cout << "Enter fname: ";
		cin >> s1.fname;
		strcpy_s(buffer, s1.fname);
		strcat_s(buffer, "|");

		// lname
		cout << "Enter lname: ";
		cin >> s1.lname;
		strcat_s(buffer, s1.lname);
		strcat_s(buffer, "|");

		// city
		cout << "Enter city: ";
		cin >> s1.city;
		strcat_s(buffer, s1.city);
		strcat_s(buffer, "|");

		// padding the buffer with spaces
		int num_of_spaces = sizeof(buffer)-strlen(buffer)-1; // the -1 because we must leave the last position in the buffer for \0
		for(int i = 0; i < num_of_spaces; i++){
			strcat(buffer, " ");
		}

		// writing the buffer to the file
		out.write((char*)&buffer, sizeof(buffer));
	}
	out.close();


	//================= Reading data from the file ======================//
	student s2;
	ifstream in("file.txt");
	int rrn = 0;
	while(!in.eof()){
		// seek to the beginning of record (offset = RRN * record size)
		in.seekg(rrn*sizeof(buffer), ios::beg);

		// fname
		in.getline(s2.fname, sizeof(s2.fname), '|');
		if(in.fail()) // check end of file
			break;
		cout << "______________ Student " << rrn+1 << "______________\n";
		cout << "Fname: " << s2.fname << endl;

		// lname
		in.getline(s2.lname, sizeof(s2.lname), '|');
		cout << "Fname: " << s2.lname << endl;

		// city
		in.getline(s2.city, sizeof(s2.city), '|');
		cout << "Fname: " << s2.city << endl;

		// increment RRN
		rrn++;
	}
	in.close();
	
	system("pause");
}