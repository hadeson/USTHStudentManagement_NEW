#include "StudentList.h"

//"Add student" main screen for users
//Display lines:
//1. Search.
//2. Enter student info.
//3. Direct Add.
//0. Back.
//Enter a number:
////////////////////
//When user input, do the respective functions:
//'1': mainSearch()
//'2': createStudent()
//'3': directAddStudent()
//'0': return;
//Otherwise: print "Invalid command", ask for other input.
void StudentList::mainAddStudent() {
	for (;;) {	
		cout << endl << endl;
		cout << "Add a student: " << endl;
		cout << "1. Search." << endl;
		cout << "2. Enter student info." << endl;
	  cout << "3. Direct add" << endl;  
	  cout << "0. Back." << endl;
	  
	  cout << "Enter a number: ";
	  
	  // Verify a command if it is integer and belong to {0..3}
	  int command;  
		while (true) {
			cin >> command;
			if (cin && (command < 4) && (command > -1)) break;
			cout << "Invalid command!" << endl;
			cin.clear();
			cin.ignore(256,'\n');
		} 
		//////////////////////////////////////////////////////////
		
	  switch (command) {
	  	case 1: mainSearch();
	  					break;
	  					//mainAddStudent();
	  	case 2: createStudent();
	  					break;
	  					//mainAddStudent();
	  	case 3: //directAddStudent();
	  					//mainAddStudent();  					
	  					break;
	  	case 0: return;
	  	default: 
	  		cout << "Invalid command!" << endl;
	  		break;
	  		
	  }
	}
}

//Let the user input all required info of the new student
//re-enter if the info is invalid
//After all the info has been filled, display options:
//1. Add student //call addStudent() 
//2. Re enter info //mainAddStudent() 
//0. return;
void StudentList::createStudent() {
	string new_name, new_dob, new_address, new_class_name, new_major;
	int new_enter_year;
	cout << "Name: ";
	cin.ignore();
	getline(cin, new_name);
	cout << "DOB: ";
	//cin.ignore();
	getline(cin, new_dob);
	cout << "Address: ";
	//cin.ignore();
	getline(cin, new_address);
	cout << "Enter year: ";
	while (!(cin >> new_enter_year)||new_enter_year<0) {
		cout << "Invalid number!" << endl;
		cin.clear();
		cin.ignore(256,'\n');
	}	
	cout << "Class: ";
	cin.ignore();
	getline(cin, new_class_name);
	cout << "Major: ";
	//cin.ignore();
	getline(cin, new_major);	
	int new_id = newID();	
	Student newbie( new_id, 
									new_name, 
									new_dob, 
									new_address, 
									new_enter_year,
									new_class_name, 
									new_major);
	cout << "Choose one: " << endl;
	cout << "1. Add student" << endl;
	cout << "0. Back" << endl;
	cout << "Enter Your option: ";
	int command;
	while (true) {
			cin >> command;
			if (cin && (command < 4) && (command > -1)) break;
			cout << "Invalid command!" << endl;
			cin.clear();
			cin.ignore(256,'\n');
		} 
	switch (command) {
	  	case 1: if (userConfirm()) {
	  						addStudent(newbie);
								cout << "Add success! New student info: " << endl;
								newbie.Print();
								cout << endl;
	  					} else {
	  						cout << "No change is commited";
	  					}	  					
	  					break;	  						  
	  	case 0: return;
	  	default: 
	  		cout << "Invalid command!" << endl;
	  		break;
	  		
	  }
}

//UPDATE LATER
////Direct add a student by enter his info
////call Student() constructor with the input info
////call addStudent() with the Student just created
////If the input is incorrect, print "Invalid command", ask for other input
//void directAddStudent(int id, string name, string dOB, string address,int enter_year, string class_name, string major) {
//	
//}

//Add student newbie into the end of  usth_student_list[], size++
//write to the output text file
void StudentList::addStudent(Student newbie) {		
	//l[size] = newbie;
	int lastStudentID = stu_list.back().Get_id();
	int newID = lastStudentID + 1;
	newbie.Set_id(newID);
	stu_list.push_back(newbie);
	//l[size].Set_id(newId);
	//size++;				
	writeFile(output_text_file);
}
