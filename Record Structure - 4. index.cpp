//////////////////////////////////////
//									//
//			Record Structure		//
//			4) index				//
//									//
//////////////////////////////////////

/*
We store the byte offset for each record in an index file.
When we write the records, we write the data in the data file and write the byte offset in the index file.
When we read the records, we read the byte offset first.
For each record, we know the offset_beg, offset_end
Record size = offset_end - offset_beg
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

	// declaring file objects
	fstream data_file, index_file;

	//================= Getting data from user and writing it to the file ======================//
	student s1;
	data_file.open("file.txt", ios::out);
	index_file.open("index.txt", ios::out);
	int offset = 0;
	index_file << "00|"; // first record offset is zero
	char buffer[100];
	for(int i = 0; i < num_of_students; i++){
		// print record number
		cout << "______________ Student " << i+1 << "______________\n";

		// fname
		cout << "Enter fname: ";
		cin >> s1.fname;
		strcpy(buffer, s1.fname);
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

		// write record to the data file
		data_file.write(buffer, strlen(buffer));

		// write offset to the index file
		offset += strlen(buffer);
		if(offset < 10)
			index_file << 0;
		index_file << offset << '|';

	}
	data_file.close();
	index_file.close();





	// ============================= reading =============================================
	data_file.open("file.txt", ios::in);
	index_file.open("index.txt", ios::in);
	int offset_beg;
	int offset_end = 0;
	int record_size;  
	int counter = 0; // to count records as we read them
	student s2;
	char temp[2];
	while(!index_file.eof()){

		//******************* Step 1: Get offset_beg ************************//
		// for first record, read first offset from index)
		if(offset_end == 0){
			index_file >> temp[0] >> temp[1];
			index_file.get(); // skip delimiter
			offset_beg = atoi(temp);
		}
		// for other records, offset_beg = old value of offset_end
		else 
			offset_beg = offset_end;
		//************************************************


		//******************* Step 2: Get offset_end ************************//
		index_file >> temp[0] >> temp[1];
		index_file.get(); // skip delimiter
		offset_end = atoi(temp);
		if(index_file.fail()) // check end of file
			break;
		//*******************************************************************
		

		//***************** Step 3: calculate record size = end - beg ********************//
		record_size = offset_end - offset_beg;
		//******************************************************************************
		

		//***************** Step 4: read the record into the buffer ******************//
		data_file.read(buffer, record_size);
		//*****************************************************************************


		//***************** Step 5: read fields from the buffer ********************//
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
	index_file.close();
	data_file.close();

	system("pause");
}