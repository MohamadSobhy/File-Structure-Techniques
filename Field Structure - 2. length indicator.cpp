/*

Field Structure:
	2. Length indicator

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

	//##################################### get data from user and write it to file #####################################
	ofstream out;
	out.open("file.txt");
	student s;
	for(int i = 0; i < num_of_students; i++){
		// variable to store length
		int length;

		// fname
		cout << "Enter first name\n";
		cin >> s.fname;
		length = strlen(s.fname); // calculate length
		if(length < 10){
			out << '0'; // to store values from 0 to 9 as 2 digits with 0 on the left
		}
		out << length << s.fname;
		// lname
		cout << "Enter last name\n";
		cin >> s.lname;
		length = strlen(s.lname);
		if(length < 10){
			out << '0';
		}
		out << length << s.lname;
		// address
		cout << "Enter address\n";
		cin >> s.address;
		length = strlen(s.address); 
		if(length < 10){
			out << '0';
		}
		out << length << s.address;
	}
	out.close();




	//##################################### read data from file #####################################
	ifstream in;
	in.open("file.txt");
	student s2;
	while(!in.eof()){
		// array to store the length as characters
		char length_arr[2];

		// variable to store the length as int
		int length;

		// fname ----------------------------------------------------
		in >> length_arr[0] >> length_arr[1]; // read length into the array
		length = atoi(length_arr); // convert the array to int
		for(int i = 0; i < length; i++){
			// read characters from file into fname
			in >> s2.fname[i];
		}
		s2.fname[length] = '\0'; // null terminator
		
		// check end of file 
		if(in.fail()) 
			break;

		// print fname
		cout << "fname: " << s2.fname << endl;


		// lname ----------------------------------------------------
		in >> length_arr[0] >> length_arr[1]; // read length into the array
		length = atoi(length_arr); // convert the array to int
		for(int i = 0; i < length; i++){
			// read characters from file into lname
			in >> s2.lname[i];
		}
		s2.lname[length] = '\0'; // null terminator
		cout << "fname: " << s2.lname << endl; // print lname


		// address ----------------------------------------------------
		in >> length_arr[0] >> length_arr[1]; // read length into the array
		length = atoi(length_arr); // convert the array to int
		for(int i = 0; i < length; i++){
			// read characters from file into address
			in >> s2.address[i];
		}
		s2.address[length] = '\0'; // null terminator
		cout << "fname: " << s2.address << endl << endl; // print address


	}
	in.close();


	system("pause");
	return 0;
}