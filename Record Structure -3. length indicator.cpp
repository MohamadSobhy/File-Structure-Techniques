//////////////////////////////////////
//									//
//			Record Structure		//
//			3) length indicator		//
//									//
//////////////////////////////////////

/*
In the file, we store the length of the record before the record data.
We read the length first.
Depending on the length, we read the whole record into the buffer.
After we have the record in the buffer, we can its fields.
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

		// writing record size (length of buffer) followed by the record data
		int length = strlen(buffer);
		if(length < 10)
			out << 0;
		out << length << buffer;
	}
	out.close();


	//================= Reading data from the file ======================//
	student s2;
	ifstream in("file.txt");
	int counter = 0;
	while(!in.eof()){
		// initializing length array and variable
		char length_arr[2];
		int length = 0;

		/////// read the whole record into the buffer //////
		// read length
		in >> length_arr[0] >> length_arr[1];
		if(in.fail()) // check end of file
			break;
		length = atoi(length_arr);
		// read record (depending on length)
		for(int i = 0; i < length; i++)
			in >> buffer[i];
		buffer[length] = '\0';

		//////////// read fields from the buffer ////////////////
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
		
	}
	in.close();
	
	system("pause");
}