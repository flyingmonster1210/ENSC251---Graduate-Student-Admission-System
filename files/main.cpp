///////////////////////////////////////////////////////////////////////////////////////////////////////
// Main Function File main.cpp                                                                       //
// Project Title: Graduate Student Admission System                                                  //
// This program uses for selecting students to get into the SFU graduate school                      //
// Creaters: Ching Hang Lam (301385370) and Weijie Zeng (301379422)                                  //
// University: Simon Fraser University                                                               //
// Last-Modified: 2019/11/22                                                                         //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include "LinkedList.h"

//Non-member Function Declaration
//Menu Functions
void menuSystem(LinkedList<DomesticStudent>& list1, LinkedList<InternationalStudent>& list2, LinkedList<Student>& list3);
char menuSelectList();
char menuSelectFunction(char& choiceList);

int main()
{
	//Create three linked lists
	LinkedList<DomesticStudent> list1;
	LinkedList<InternationalStudent> list2;
	LinkedList<Student> list3;

	//Input all the data into lists
	list1.storeDomesticStudentData();
	list2.storeInternationalStudentData();
	cout << endl;

	char system;
	cout << "You want to open a Menu System or Unit Test System?" << endl;
	cout << "1. Menu System" << endl;
	cout << "2. Unit Test System" << endl;
	cout << "Enter your choice: "; cin >> system; cout << endl;
	while (system != '1' && system != '2')
	{
		cout << "You enter an incorrect selection. Please enter again!";
		cout << "Enter your choice: "; cin >> system; cout << endl;
	}
	if (system == '1')
	{
		menuSystem(list1, list2, list3);
	}
	else
	{
		//Unit Test
		char selection_function;
		char repeat;

		cout << "Which functions you want to test?" << endl;
		cout << "1. Insert a student data Function" << endl;
		cout << "2. Search by id, CGPA, research score Function" << endl;
		cout << "3. Search by first name and last name Function" << endl;
		cout << "4. Delete existing student data" << endl;
		cout << "5. Delete hail and tail student data" << endl;
		cout << "6. Merge two student lists" << endl;
		cout << "7. Search merged list with the minimum CGPA and the minimum research score" << endl;
		cout << "Enter your choice: "; cin >> selection_function; cout << endl;

		while (selection_function != '1' && selection_function != '2' && selection_function != '3'
			&& selection_function != '4' && selection_function != '5' && selection_function != '6'
			&& selection_function != '7')
		{
			cout << "You enter an incorrect selection. Please enter again!";
			cout << "Enter your choice: "; cin >> selection_function; cout << endl;
		}

		if (selection_function == '1')
		{
			do
			{
				//Test 1: Insert a student data Function
				cout << "Testing inserting Function" << endl;

				//Normal Cases
				cout << "Normal Cases" << endl;
				cout << "Domestic Student List" << endl;
				list1.displayList();
				cout << "Inserting a Student data" << endl;
				cout << "First Name: Abc, Last Name: Def, CGPA: 4.0, Research Score: 95, Province: ON" << endl;
				DomesticStudent* temp1 = new DomesticStudent("Abc", "Def", 4, 95, "ON");
				list1.insert(temp1);
				list1.displayList();
				cout << endl;

				cout << "International Student List" << endl;
				list2.displayList();
				cout << "Inserting a Student data" << endl;
				cout << "First Name: Abc, Last Name: Def, CGPA: 4.0, Research Score: 95, Country: China, reading: 25, listening: 26, speaking: 27, writing: 28" << endl;
				InternationalStudent* temp2 = new InternationalStudent("Abc", "Def", 4, 95, "China", 25, 26, 27, 28);
				list2.insert(temp2);
				list2.displayList();
				cout << endl;

				//Corner Cases
				cout << "Corner Cases" << endl;
				//All the scores are zero
				cout << "All the scores are zero" << endl;
				cout << "Domestic Student List" << endl;
				list1.displayList();
				cout << "Inserting a Student data" << endl;
				cout << "First Name: Abc, Last Name: Def, CGPA: 0, Research Score: 0, Province: ON" << endl;
				DomesticStudent* temp3 = new DomesticStudent("Abc", "Def", 0, 0, "ON");
				list1.insert(temp3);
				list1.displayList();
				cout << endl;

				cout << "International Student List" << endl;
				list2.displayList();
				cout << "Inserting a Student data" << endl;
				cout << "First Name: Abc, Last Name: Def, CGPA: 0, Research Score: 0, Country: China, reading: 0, listening: 0, speaking: 0, writing: 0" << endl;
				InternationalStudent* temp4 = new InternationalStudent("Abc", "Def", 0, 0, "China", 0, 0, 0, 0);
				list2.insert(temp4);
				list2.displayList();

				//Empty Linked List
				list1.deleteList(0);
				list2.deleteList(0);
				cout << "Empty Linked List" << endl;
				cout << "Domestic Student List" << endl;
				list1.displayList();
				cout << "Inserting a Student data" << endl;
				cout << "First Name: Abc, Last Name: Def, CGPA: 4.0, Research Score: 95, Province: ON" << endl;
				DomesticStudent* temp5 = new DomesticStudent("Abc", "Def", 4, 95, "ON");
				list1.insert(temp5);
				list1.displayList();
				cout << endl;

				cout << "International Student List" << endl;
				list2.displayList();
				cout << "Inserting a Student data" << endl;
				cout << "First Name: Abc, Last Name: Def, CGPA: 4.0, Research Score: 95, Country: China, reading: 25, listening: 26, speaking: 27, writing: 28" << endl;
				InternationalStudent* temp6 = new InternationalStudent("Abc", "Def", 4, 95, "China", 25, 26, 27, 28);
				list2.insert(temp6);
				list2.displayList();
				cout << endl;

				//Illegal Cases
				char illegal;
				cout << "Do you want to test the illegal cases?" << endl;
				cout << "Enter y for yes or n for no: "; cin >> illegal;
				if (illegal == 'y' || illegal == 'Y')
				{
					//Illegal Province
					cout << "Illegal Province" << endl;
					cout << "Domestic Student List" << endl;
					list1.displayList();
					cout << "Inserting a Student data" << endl;
					cout << "First Name: Abc, Last Name: Def, CGPA: -1, Research Score: 95, Province: AA" << endl;
					DomesticStudent* temp7 = new DomesticStudent("Abc", "Def", 0, 95, "AA");
					list1.insert(temp7);
					list1.displayList();
					cout << endl;

					//Illegal Country
					cout << "Illegal Country" << endl;
					cout << "International Student List" << endl;
					list2.displayList();
					cout << "Inserting a Student data" << endl;
					cout << "First Name: Abc, Last Name: Def, CGPA: 4.0, Research Score: 95, Country: Abc, reading: 25, listening: 26, speaking: 27, writing: 28" << endl;
					InternationalStudent* temp8 = new InternationalStudent("Abc", "Def", 4, 95, "Abc", 25, 26, 27, 28);
					list2.insert(temp8);
					list2.displayList();
					cout << endl;
				}

				//Test by input
				char input;
				cout << "Do you want to input the data to test?" << endl;
				cout << "Enter y for yes or n for no: "; cin >> input;
				if (input == 'y' || input == 'Y')
				{
					string firstName, lastName, province, country;
					int researchScore, reading, listening, speaking, writing;
					float cgpa;
					cout << "Domestic Student List" << endl;
					cout << "Enter First Name: "; cin >> firstName;
					cout << "Enter Last Name: "; cin >> lastName;
					cout << "Enter CGPA: "; cin >> cgpa;
					cout << "Enter Research Score: "; cin >> researchScore;
					cout << "Enter Province: "; cin >> province;
					DomesticStudent* temp9 = new DomesticStudent(firstName, lastName, cgpa, researchScore, province);
					list1.insert(temp9);
					list1.displayList();
					cout << endl;

					cout << "International Student List" << endl;
					cout << "Domestic Student List" << endl;
					cout << "Enter First Name: "; cin >> firstName;
					cout << "Enter Last Name: "; cin >> lastName;
					cout << "Enter CGPA: "; cin >> cgpa;
					cout << "Enter Research Score: "; cin >> researchScore;
					cout << "Enter Country: "; cin >> country;
					cout << "Enter reading: "; cin >> reading;
					cout << "Enter listening: "; cin >> listening;
					cout << "Enter speaking: "; cin >> speaking;
					cout << "Enter writing: "; cin >> writing;
					InternationalStudent* temp10 = new InternationalStudent(firstName, lastName, cgpa, researchScore, country, reading, listening, speaking, writing);
					list2.insert(temp10);
					list2.displayList();
					cout << endl;
				}

				cout << "Test again? Enter y for yes or n for no: "; cin >> repeat;
				cout << endl;
				list1.deleteList(0);
				list2.deleteList(0);
				list1.storeDomesticStudentData();
				list2.storeInternationalStudentData();
			} while (repeat == 'y' || repeat == 'Y');
		}
		else if (selection_function == '2')
		{
			do
			{
				//Test 2: Searching Function(Searched by ID, CGPA, Research Score)
				cout << "Testing searching Function(Searched by ID, CGPA, Research Score)" << endl;

				//Normal Cases
				cout << "Normal Cases" << endl;
				cout << "Domestic Student List" << endl;
				cout << "Searching ID: 20200001" << endl;
				list1.searchId(20200001);
				cout << "Searching CGPA: 4.0" << endl;
				list1.searchCgpa(4.0);
				cout << "Searching Research Score: 95" << endl;
				list1.searchResearchScore(95);
				cout << endl;

				cout << "International Student List" << endl;
				cout << "Searching ID: 20200101" << endl;
				list2.searchId(20200101);
				cout << "Searching CGPA: 4.0" << endl;
				list2.searchCgpa(4.0);
				cout << "Searching Research Score: 95" << endl;
				list2.searchResearchScore(95);
				cout << endl;

				//Corner Cases
				cout << "Corner Cases" << endl;
				cout << "Domestic Student List" << endl;
				cout << "Searching ID: 0" << endl;
				list1.searchId(0);
				cout << "Searching CGPA: 0.0" << endl;
				list1.searchCgpa(0);
				cout << "Searching Research Score 0" << endl;
				list1.searchResearchScore(0);
				cout << endl;

				cout << "International Student List" << endl;
				cout << "Searching ID: 0" << endl;
				list2.searchId(0);
				cout << "Searching CGPA: 0.0" << endl;
				list2.searchCgpa(0);
				cout << "Searching Research Score: 0" << endl;
				list2.searchResearchScore(0);
				cout << endl;

				//Illegal Cases
				cout << "Illegal Cases" << endl;
				cout << "Domestic Student List" << endl;
				cout << "Searching ID: -1" << endl;
				list1.searchId(-1);
				cout << "Searching CGPA: -1" << endl;
				list1.searchCgpa(-1);
				cout << "Searching Research Score -1" << endl;
				list1.searchResearchScore(-1);
				cout << endl;

				cout << "International Student List" << endl;
				cout << "Searching ID: -1" << endl;
				list2.searchId(-1);
				cout << "Searching CGPA: -1" << endl;
				list2.searchCgpa(-1);
				cout << "Searching Research Score: -1" << endl;
				list2.searchResearchScore(-1);
				cout << endl;

				//Test by input
				char input;
				cout << "Do you want to input the data to test?" << endl;
				cout << "Enter y for yes or n for no: "; cin >> input;
				if (input == 'y' || input == 'Y')
				{
					int id, researchScore;
					float cgpa;
					cout << "Domestic Student List" << endl;
					cout << "Enter the Id: "; cin >> id;
					list1.searchId(id);
					cout << "Enter the CGPA: "; cin >> cgpa;
					list1.searchCgpa(cgpa);
					cout << "Enter the research score: "; cin >> researchScore;
					list1.searchId(researchScore);
					cout << endl;

					cout << "International Student List" << endl;
					cout << "Enter the Id: "; cin >> id;
					list2.searchId(id);
					cout << "Enter the CGPA: "; cin >> cgpa;
					list2.searchCgpa(cgpa);
					cout << "Enter the research score: "; cin >> researchScore;
					list2.searchId(researchScore);
					cout << endl;
				}

				cout << "Test again? Enter y for yes or n for no: "; cin >> repeat;
				cout << endl;
				list1.deleteList(0);
				list2.deleteList(0);
				list1.storeDomesticStudentData();
				list2.storeInternationalStudentData();
			} while (repeat == 'y' || repeat == 'Y');
		}
		else if (selection_function == '3')
		{
			do
			{
				//Test 3: Searching Function(Searched by First Name and Last Name)
				cout << "Testing searching Function(Searched by First Name and Last Name)" << endl;

				//Normal Cases
				cout << "Normal Cases" << endl;
				cout << "Domestic Student List" << endl;
				list1.displayList();
				cout << "Searching first name: Mary and last name: White" << endl;
				list1.searchName("Mary", "White");
				cout << endl;

				cout << "International Student List" << endl;
				list2.displayList();
				cout << "Searching first name: Alex and last name: Zhang" << endl;
				list2.searchName("Alex", "Zhang");
				cout << endl;

				//Corner Cases
				//Insensitive Name
				cout << "Corner Cases" << endl;
				cout << "Insensitive Name" << endl;
				cout << "Domestic Student List" << endl;
				list1.displayList();
				cout << "Searching first name: mary and last name: white" << endl;
				list1.searchName("mary", "white");
				cout << endl;

				cout << "International Student List" << endl;
				list2.displayList();
				cout << "Searching first name: alex and last name: zhang" << endl;
				list2.searchName("alex", "zhang");
				cout << endl;

				//No this student
				cout << "No this student" << endl;
				cout << "Domestic Student List" << endl;
				list1.displayList();
				cout << "Searching first name: abc and last name: abc" << endl;
				list1.searchName("abc", "abc");
				cout << endl;

				cout << "International Student List" << endl;
				list2.displayList();
				cout << "Searching first name: abc and last name: abc" << endl;
				list2.searchName("abc", "abc");
				cout << endl;

				//Illegal Cases
				cout << "Illegal Cases" << endl;
				cout << "Domestic Student List" << endl;
				list1.displayList();
				cout << "Searching first name: -1 and last name: -2" << endl;
				list1.searchName("-1", "-2");
				cout << endl;

				cout << "International Student List" << endl;
				list2.displayList();
				cout << "Searching first name: -1 and last name: -2" << endl;
				list2.searchName("-1", "-2");
				cout << endl;

				//Test by input
				char input;
				cout << "Do you want to input the data to test?" << endl;
				cout << "Enter y for yes or n for no: "; cin >> input;
				if (input == 'y' || input == 'Y')
				{
					string firstName, lastName;
					cout << "Domestic Student List" << endl;
					list1.displayList();
					cout << "Enter the first name: "; cin >> firstName;
					cout << "Enter the last name: "; cin >> lastName;
					list1.searchName(firstName, lastName);
					cout << endl;

					cout << "International Student List" << endl;
					list2.displayList();
					cout << "Enter the first name: "; cin >> firstName;
					cout << "Enter the last name: "; cin >> lastName;
					list2.searchName(firstName, lastName);
					cout << endl;
				}

				cout << "Test again? Enter y for yes or n for no: "; cin >> repeat;
				cout << endl;
				list1.deleteList(0);
				list2.deleteList(0);
				list1.storeDomesticStudentData();
				list2.storeInternationalStudentData();
			} while (repeat == 'y' || repeat == 'Y');
		}
		else if (selection_function == '4')
		{
			do
			{
				//Test 4: Delecting Function(Delected by First Name and Last Name)
				cout << "Testing delecting Function(Delected by First Name and Last Name)" << endl;

				//Normal Cases
				cout << "Normal Cases" << endl;
				cout << "Domestic Student List" << endl;
				list1.displayList();
				cout << "Delete a Student" << endl;
				cout << "Enter the first name : Mary and last name : White" << endl;
				list1.deleteStudent();
				list1.displayList();
				cout << endl;

				cout << "International Student List" << endl;
				list2.displayList();
				cout << "Delete a Student" << endl;
				cout << "Enter the first name: Alex and last name: Zhang" << endl;
				list2.deleteStudent();
				list2.displayList();
				cout << endl;

				//Corner Cases
				cout << "Corner Cases" << endl;
				//Insensitive Name
				cout << "Insensitive Name" << endl;
				cout << "Domestic Student List" << endl;
				list1.displayList();
				cout << "Delete a Student" << endl;
				cout << "Enter the first name : mike and last name : hwang" << endl;
				list1.deleteStudent();
				list1.displayList();
				cout << endl;

				cout << "International Student List" << endl;
				list2.displayList();
				cout << "Delete a Student" << endl;
				cout << "Enter the first name: peter and last name: choi" << endl;
				list2.deleteStudent();
				list2.displayList();
				cout << endl;

				//No this student
				cout << "No this student" << endl;
				cout << "Domestic Student List" << endl;
				list1.displayList();
				cout << "Delete a Student" << endl;
				cout << "Enter the first name : mike and last name : hwang" << endl;
				list1.deleteStudent();
				list1.displayList();
				cout << endl;

				cout << "International Student List" << endl;
				list2.displayList();
				cout << "Delete a Student" << endl;
				cout << "Enter the first name: peter and last name: choi" << endl;
				list2.deleteStudent();
				list2.displayList();
				cout << endl;

				//Illegal Cases
				cout << "Illegal Cases" << endl;
				cout << "Domestic Student List" << endl;
				list1.displayList();
				cout << "Delete a Student" << endl;
				cout << "Enter the first name : -1 and last name : -2" << endl;
				list1.deleteStudent();
				list1.displayList();
				cout << endl;

				cout << "International Student List" << endl;
				list2.displayList();
				cout << "Delete a Student" << endl;
				cout << "Enter the first name: -1 and last name: -2" << endl;
				list2.deleteStudent();
				list2.displayList();
				cout << endl;

				//Test by input
				char input;
				cout << "Do you want to input the data to test?" << endl;
				cout << "Enter y for yes or n for no: "; cin >> input;
				if (input == 'y' || input == 'Y')
				{
					string firstName, lastName;
					cout << "Domestic Student List" << endl;
					list1.displayList();
					cout << "Delete a Student" << endl;
					list1.deleteStudent();
					list1.displayList();
					cout << endl;

					cout << "International Student List" << endl;
					list2.displayList();
					cout << "Delete a Student" << endl;
					list2.deleteStudent();
					list2.displayList();
					cout << endl;
				}

				cout << "Test again? Enter y for yes or n for no: "; cin >> repeat;
				cout << endl;

				list1.deleteList(0);
				list2.deleteList(0);
				list1.storeDomesticStudentData();
				list2.storeInternationalStudentData();
			} while (repeat == 'y' || repeat == 'Y');
		}
		else if (selection_function == '5')
		{
			do
			{
				//Test 5: Delecting Function(Delected Head and Tail)
				cout << "Testing delecting Function(Delected Head and Tail)" << endl;

				//Normal Cases
				cout << "Normal Cases" << endl;
				cout << "Domestic Student List" << endl;
				list1.displayList();
				cout << "Delete Head and Tail" << endl;
				list1.deleteHeadTail();
				list1.displayList();
				cout << "International Student List" << endl;
				list2.displayList();
				cout << "Delete Head and Tail" << endl;
				list2.deleteHeadTail();
				list2.displayList();
				cout << endl;

				//Corner Cases
				//Only one student
				cout << "Corner Cases" << endl;
				cout << "Only one student" << endl;
				cout << "Domestic Student List" << endl;
				list1.deleteList(0);
				DomesticStudent* temp1 = new DomesticStudent("Abc", "Def", 0.0, 0, "ON");
				list1.insert(temp1);
				list1.displayList();
				cout << "Delete Head and Tail" << endl;
				list1.deleteHeadTail();
				list1.displayList();
				cout << "International Student List" << endl;
				list2.deleteList(0);
				InternationalStudent* temp2 = new InternationalStudent("Abc", "Def", 0.0, 0, "China", 25, 25, 25, 25);
				list2.insert(temp2);
				list2.displayList();
				cout << "Delete Head and Tail" << endl;
				list2.deleteHeadTail();
				list2.displayList();
				cout << endl;

				//Empty Linked List
				cout << "Empty Linked List" << endl;
				cout << "Domestic Student List" << endl;
				list1.deleteList(0);
				list1.deleteHeadTail();
				cout << "International Student List" << endl;
				list2.deleteList(0);
				list2.deleteHeadTail();
				cout << endl;

				//Illegal Cases
				cout << "Illegal Cases" << endl;
				cout << "There is no illegal case." << endl;
				cout << endl;

				cout << "Test again? Enter y for yes or n for no: "; cin >> repeat;
				cout << endl;

				list1.deleteList(0);
				list2.deleteList(0);
				list1.storeDomesticStudentData();
				list2.storeInternationalStudentData();
			} while (repeat == 'y' || repeat == 'Y');
		}
		else if (selection_function == '6')
		{
			do
			{
				//Test 6: Merging Function
				cout << "Testing mergeing Function" << endl;

				//Normal Cases
				cout << "Normal Cases" << endl;
				cout << "Merging Domestic Student List and International List" << endl;
				list3.merge(list1, list2);
				list3.displayList();
				cout << endl;

				//Corner Cases
				cout << "Corner Cases" << endl;
				//Domestic Student List is an empty linked list
				cout << "Domestic Student List is an empty linked list" << endl;
				list1.deleteList(0);
				list3.merge(list1, list2);
				list3.displayList();
				cout << endl;

				//International Student List is an empty linked list
				cout << "International Student List is an empty linked list" << endl;
				list1.storeDomesticStudentData();
				list2.deleteList(0);
				list3.merge(list1, list2);
				list3.displayList();
				cout << endl;

				//Both Student Lists are empty linked lists
				cout << "Both Student Lists are empty linked lists" << endl;
				list1.deleteList(0);
				list3.merge(list1, list2);
				list3.displayList();
				cout << endl;

				//Illegal Cases
				cout << "Illegal Cases" << endl;
				cout << "There is no illegal case." << endl;
				cout << endl;

				cout << "Test again? Enter y for yes or n for no: "; cin >> repeat;
				cout << endl;

				list1.deleteList(0);
				list2.deleteList(0);
				list1.storeDomesticStudentData();
				list2.storeInternationalStudentData();
			} while (repeat == 'y' || repeat == 'Y');
		}
		else if (selection_function == '7')
		{
			do
			{
				//Test 7: Search Merged list Function
				cout << "Testing search Merged list Function" << endl;

				//Normal Cases
				cout << "Normal Cases" << endl;
				list3.merge(list1, list2);
				list3.displayList();
				cout << "For the minimum CPGA = 3 and the minimum research score = 90" << endl;
				cout << "Please set the minimum CPGA = 3 and the minimum research score = 90" << endl;
				list3.searchSatified();
				cout << endl;

				//Corner Cases
				cout << "Corner Cases" << endl;
				//The minimum CPGA = 0 and the minimum research score = 0
				cout << "For the minimum CPGA = 0 and the minimum research score = 0" << endl;
				cout << "Please set the minimum CPGA = 0 and the minimum research score = 0" << endl;
				list3.searchSatified();
				cout << endl;
				//The minimum CPGA = 4.33 and the minimum research score = 100
				cout << "For the minimum CPGA = 4.33 and the minimum research score = 100" << endl;
				cout << "Please set the minimum CPGA = 4.33 and the minimum research score = 100" << endl;
				list3.searchSatified();
				cout << endl;

				//Illegal Cases
				cout << "Illegal Cases" << endl;
				//The minimum CPGA = 101 and the minimum research score = 101
				cout << "For the minimum CPGA = 101 and the minimum research score = 101" << endl;
				cout << "Please set the minimum CPGA = 101 and the minimum research score = 101" << endl;
				list3.searchSatified();
				cout << endl;

				cout << "Test again? Enter y for yes or n for no: "; cin >> repeat;
				cout << endl;

				list1.deleteList(0);
				list2.deleteList(0);
				list1.storeDomesticStudentData();
				list2.storeInternationalStudentData();
			} while (repeat == 'y' || repeat == 'Y');
		}
	}

	//Delete all the lists
	list1.deleteList(0);
	list2.deleteList(0);

	cout << "This program is closed." << endl;
	return 0;
}

//Non-member Function Implementation
//Menu Functions
void menuSystem(LinkedList<DomesticStudent>& list1, LinkedList<InternationalStudent>& list2, LinkedList<Student>& list3)
{
	char choiceList;
	char choiceFunction;

	//Display the menu messege
	cout << endl;
	cout << setw(55) << "Graduate Student Admission System" << endl;
	cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
	cout << endl;

	//Open the menu select list
	choiceList = menuSelectList();
	if (choiceList == 'Q')
		return;

	//Open the menu select function
	choiceFunction = menuSelectFunction(choiceList);
	if (choiceFunction == 'B')
	{
		menuSystem(list1, list2, list3);
		return;
	}
	else if (choiceFunction == 'Q')
		return;

	//Select Domestic Student List
	if (choiceList == '1')
	{
		if (choiceFunction == '1')
			list1.displayList();
		else if (choiceFunction == '2')
			list1.insertStudent();
		else if (choiceFunction == '3')
			list1.deleteStudent();
		else if (choiceFunction == '4')
			list1.deleteHeadTail();
		else if (choiceFunction == '5')
			list1.deleteList(1);
		else if (choiceFunction == 'I')
		{
			int id;
			cout << "Enter the ID: "; cin >> id;
			cout << endl;
			list1.searchId(id);
		}
		else if (choiceFunction == 'N')
		{
			string firstName, lastName;
			cout << "Enter the First Name: "; cin >> firstName;
			cout << "Enter the Last Name: "; cin >> lastName;
			cout << endl;
			list1.searchName(firstName, lastName);
		}
		else if (choiceFunction == 'C')
		{
			float cgpa;
			cout << "Enter the CGPA: "; cin >> cgpa;
			cout << endl;
			list1.searchCgpa(cgpa);
		}
		else if (choiceFunction == 'R')
		{
			int researchScore;
			cout << "Enter the Research Score: "; cin >> researchScore;
			cout << endl;
			list1.searchResearchScore(researchScore);
		}
	}
	//Select International Student List
	else if (choiceList == '2')
	{
		if (choiceFunction == '1')
			list2.displayList();
		else if (choiceFunction == '2')
			list2.insertStudent();
		else if (choiceFunction == '3')
			list2.deleteStudent();
		else if (choiceFunction == '4')
			list2.deleteHeadTail();
		else if (choiceFunction == '5')
			list2.deleteList(1);
		else if (choiceFunction == 'I')
		{
			int id;
			cout << "Enter the ID: "; cin >> id;
			cout << endl;
			list2.searchId(id);
		}
		else if (choiceFunction == 'N')
		{
			string firstName, lastName;
			cout << "Enter the First Name: "; cin >> firstName;
			cout << "Enter the Last Name: "; cin >> lastName;
			cout << endl;
			list2.searchName(firstName, lastName);
		}
		else if (choiceFunction == 'C')
		{
			float cgpa;
			cout << "Enter the CGPA: "; cin >> cgpa;
			cout << endl;
			list2.searchCgpa(cgpa);
		}
		else if (choiceFunction == 'R')
		{
			int researchScore;
			cout << "Enter the Research Score: "; cin >> researchScore;
			cout << endl;
			list2.searchResearchScore(researchScore);
		}
	}
	//Select Combined Student List
	else if (choiceList == '3')
	{
		list3.merge(list1, list2);

		if (choiceFunction == '1')
			list3.displayList();
		else if (choiceFunction == '2')
			list3.searchSatified();
	}

	menuSystem(list1, list2, list3);
	return;
}
char menuSelectList()
{
	//Display the selection of lists
	cout << setw(42) << "Database" << endl;
	cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
	cout << setw(48) << "1. Domestic Student List" << endl;
	cout << setw(53) << "2. International Student List" << endl;
	cout << setw(48) << "3. Combined Student List" << endl;
	cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
	cout << setw(47) << "Q: Quit the program" << endl;
	cout << "Enter the your choice: ";

	//Wait for the user to enter their choice
	char choiceList;
	cin >> choiceList;

	//Loop for the user input an incorrect selection
	while (choiceList != '1' && choiceList != '2' && choiceList != '3' &&
		choiceList != 'Q')
	{
		cout << "You do not eneter a correct selection" << endl;
		cout << "Please select a list from the above choices" << endl;
		cout << "Enter the your choice: ";
		cin >> choiceList;
	}

	//Display the message of selection
	if (choiceList == '1')
		cout << "You selected the Domestic Student List" << endl;
	else if (choiceList == '2')
		cout << "You selected the International Student List" << endl;
	else if (choiceList == '3')
		cout << "You selected the Combined Student List" << endl;
	else if (choiceList == 'Q')
		cout << "You selected to quit the program" << endl;
	cout << endl;

	return choiceList;
}
char menuSelectFunction(char& choiceList)
{
	//Display the selection of functions for Domestic Student List and International Student List
	if (choiceList == '1' || choiceList == '2')
	{
		if (choiceList == '1')
			cout << setw(48) << "Domestic Student List" << endl;
		else
			cout << setw(51) << "International Student List" << endl;

		cout << setw(42) << "Functions" << endl;
		cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
		cout << setw(60) << "1: Display all the student data in this list" << endl;
		cout << setw(44) << "2: Insert a new student data" << endl;
		cout << setw(40) << "3: Delete a student data" << endl;
		cout << setw(53) << "4: Delete the head node and tail node" << endl;
		cout << setw(59) << "5: Delete all the student data in this list" << endl;
		cout << setw(44) << "I: Search student data by ID" << endl;
		cout << setw(46) << "N: Search student data by Name" << endl;
		cout << setw(46) << "C: Search student data by CGPA" << endl;
		cout << setw(56) << "R: Search student data by Research Score" << endl;
		cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
		cout << setw(43) << "B: Back to menu" << endl;
		cout << setw(47) << "Q: Quit the program" << endl;
		cout << "Enter the your choice: ";

		//Wait for the user to enter their choice
		char choiceFunction;
		cin >> choiceFunction;

		//Loop for the user input an incorrect selection
		while (choiceFunction != '1' && choiceFunction != '2' && choiceFunction != '3' &&
			choiceFunction != '4' && choiceFunction != '5' && choiceFunction != 'I' &&
			choiceFunction != 'N' && choiceFunction != 'C' && choiceFunction != 'R' &&
			choiceFunction != 'B' && choiceFunction != 'Q')
		{
			cout << "You do not eneter a correct selection" << endl;
			cout << "Please select a function from the above choices" << endl;
			cout << "Enter the your choice: ";
			cin >> choiceFunction;
		}

		//Display the message of selection
		if (choiceFunction == '1')
			cout << "You selected to display all the student data in this list" << endl;
		else if (choiceFunction == '2')
			cout << "You selected to insert a new student data" << endl;
		else if (choiceFunction == '3')
			cout << "You selected to delete a student data" << endl;
		else if (choiceFunction == '4')
			cout << "You selected to delete the head node and tail node" << endl;
		else if (choiceFunction == '5')
			cout << "You selected to delete all the student data in this list" << endl;
		else if (choiceFunction == 'I')
			cout << "You selected to search student data by ID" << endl;
		else if (choiceFunction == 'N')
			cout << "You selected to search student data by Name" << endl;
		else if (choiceFunction == 'C')
			cout << "You selected to search student data by CGPA" << endl;
		else if (choiceFunction == 'R')
			cout << "You selected to search student data by Research Score" << endl;
		else if (choiceFunction == 'B')
			cout << "You selected to back to menu" << endl;
		else if (choiceFunction == 'Q')
			cout << "You selected to quit this program" << endl;
		cout << endl;

		return choiceFunction;
	}
	else
	{
		//Display the selection of functions for Combined Student List
		cout << setw(47) << "Combined Student List" << endl;
		cout << setw(42) << "Functions" << endl;
		cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
		cout << setw(55) << "1: Display all the student data in this list" << endl;
		cout << setw(65) << "2: Setting the minimum CGPA and the minmum Research Score" << endl;
		cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
		cout << setw(43) << "B: Back to menu" << endl;
		cout << setw(47) << "Q: Quit the program" << endl;
		cout << "Enter the your choice: ";

		//Wait for the user to enter their choice
		char choiceFunction;
		cin >> choiceFunction;

		//Loop for the user input an incorrect selection
		while (choiceFunction != '1' && choiceFunction != '2' && choiceFunction != 'B' &&
			choiceFunction != 'Q')
		{
			cout << "You do not eneter a correct selection" << endl;
			cout << "Please select a function from the above choices" << endl;
			cout << "Enter the your choice: ";
			cin >> choiceFunction;
		}

		//Display the message of selection
		if (choiceFunction == '1')
			cout << "You selected to display all the student data in this list" << endl;
		else if (choiceFunction == '2')
			cout << "You selected to setting the minimum CGPA and the minmum Research Score" << endl;
		else if (choiceFunction == 'B')
			cout << "You selected to back to menu" << endl;
		else if (choiceFunction == 'Q')
			cout << "You selected to quit this program" << endl;
		cout << endl;

		return choiceFunction;
	}
}