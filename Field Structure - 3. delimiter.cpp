/*

Field Structure:
	3. Delimiter

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
		// fname
		cout << "Enter first name\n";
		cin >> s.fname;
		out << s.fname << '#';
		// lname
		cout << "Enter last name\n";
		cin >> s.lname;
		out << s.lname << '#';
		// address
		cout << "Enter address\n";
		cin >> s.address;
		out << s.address << '#';
	}
	out.close();




	//##################################### read data from file #####################################
	ifstream in;
	in.open("file.txt");
	student s2;
	while(!in.eof()){

		// fname ----------------------------------------------------
		in.getline(s2.fname, sizeof(s2.fname), '#');
		if(in.fail()) // check end of file
			break;
		cout << "fname: " << s2.fname << endl;


		// lname ----------------------------------------------------
		in.getline(s2.lname, sizeof(s2.lname), '#');
		cout << "lname: " << s2.lname << endl;


		// address ----------------------------------------------------
		in.getline(s2.address, sizeof(s2.address), '#');
		cout << "address: " << s2.address << endl;

	}
	in.close();


	system("pause");
	return 0;
}