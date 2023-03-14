///////////////////////////////////////////////////////////////////////////////////////////////////////
// Header file LinkedList.h                                                                          //
// This is the interface for the template class LinkedList.                                          //
// Also, this contains the implementation of the class LinkedList.                                   //
// This class includes the class Student, DomesticStudent, InternationalStudent, ToeflScore.         //
// This class contains a head node and a tail node pointing to class T.                              //
// Last-Modified: 2020/03/22                                                                         //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Student.h"
#include "DomesticStudent.h"
#include "InternationalStudent.h"
#include "ToeflScore.h"

template<class T>
class LinkedList
{
private:
	T* head, *tail;

public:
	//Constructors
	LinkedList();

	//Getters
	T* getHead() const;

	//Inserting Functions
	void insert(T* student); //This function inserts DomesticStudent / InternationalStudent pointer to the list
	//Prequest: DomesticStudent / InternationalStudent pointer
	void insertStudent(); //This function inserts a DomesticStudent / InternationalStudent object to the list

	//Deleting Functions
	void deleteStudent(); //This function deletes one student node from the list who match the name
	void deleteHeadTail(); //This function deletes a head node and a tail node from the list
	void deleteList(bool signal); //This function deletes entire list
	//The input signal for display different messege
	//Prerequest: singal = true / 1 for working in the program, signal = false / 0 for closing the program

	//Serching Functions
	void searchId(const int id) const;
	void searchName(const string firstName, const string lastName);
	void searchCgpa(const float cgpa) const;
	void searchResearchScore(const int researchScore) const;
	void searchSatified() const; //This function searches and displays students who meet the minimum Research Score and CGPA

	//Displaying Functions
	void displayTitle() const; //This function displays the title of the list
	void displayList() const; //This function displays the data in the list

	//Merging Functions
	void merge(LinkedList<DomesticStudent> &list1, LinkedList<InternationalStudent> &list2); //This function merges two linked lists into one linked list

	//Inputing Functions
	void storeDomesticStudentData(); //This function inputs the data from the domestic-stu.txt document
	void storeInternationalStudentData(); //This function inputs the data from the international-stu.txt document

	//Checking Functions
	void checkInput_field(string &line); //This function checks the validity of the input

	//Modifying Functions
	void modifyName(string& name); //This function modifies the first letter in uppercase and the remaining letters in lowercase
};
//Constructors
template<class T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	tail = NULL;
}

//Getters
template<class T>
T* LinkedList<T>::getHead() const
{
	return head;
}

//Inserting Functions
template<class T>
void LinkedList<T>::insert(T* student)
{
	//Empty linked list
	if (head == NULL)
	{
		head = student;
		tail = student;
		return;
	}
	//Compare to the head node
	else if (compareAll(*student, *head) >= 0)
	{
		student->setLink(head);
		head = student;
		return;
	}
	//Compare from the second node
	else
	{
		T* left = head;
		T* right = head->getLink();
		//Insert before the larger than or equal to the right pointer
		while (left != tail)
		{
			if (compareAll(*student, *right) >= 0)
			{
				student->setLink(right);
				left->setLink(student);
				return;
			}
			else
			{
				left = left->getLink();
				right = right->getLink();
			}
		}
		//Insert at the tail
		tail->setLink(student);
		tail = student;
		return;
	}
}
template<class T>
void LinkedList<T>::insertStudent()
{
	T* temp = new T();
	cin >> *temp;
	insert(temp);
	
	cout << "\nThis student data added to this list" << endl;
	displayTitle();
	cout << *temp << endl;
}

//Deleting Functions
template<class T>
void LinkedList<T>::deleteStudent()
{
	//Empty linked list
	if (head == NULL)
	{
		cout << "There is no any data in this list" << endl;
		cout << "You can not delete any data" << endl;
		return;
	}

	string firstName, lastName;
	cout << "Enter the First Name: "; cin >> firstName;
	cout << "Enter the Last Name: "; cin >> lastName;
	cout << endl;
	modifyName(firstName);
	modifyName(lastName);

	bool found = false;
	//Compare to the head node
	while(head->getFirstName() == firstName && head->getLastName() == lastName)
	{
		//There is not only one node
		if (head != tail)
		{
			found = true;
			T* temp = head;
			head = head->getLink();
			delete temp;
		}
		//There is only one node
		else
		{
			T* temp = head;
			head = NULL;
			tail = NULL;
			delete temp;
			cout << "The Student " << firstName << " " << lastName << " was deleted" << endl;
			return;
		}
	}

	//Compare from the second node
	if (head->getLink() != NULL)
	{
		T* left = head;
		T* right = head->getLink();

		//Compare before the right pointer reaching the tail node
		while(right != tail)
		{
			if (right->getFirstName() == firstName && right->getLastName() == lastName)
			{
				found = true;
				T* temp = right;
				right = right->getLink();
				left->setLink(right);
				delete temp;
			}
			else
			{
				left = left->getLink();
				right = right->getLink();
			}
		}
		//Compare the tail node
		if (tail->getFirstName() == firstName && tail->getLastName() == lastName)
		{
			found = true;
			T* temp = tail;
			tail = left;
			tail->setLink(NULL);
			delete temp;
		}
	}

	//No match found
	if (!found)
		cout << "No match found" << endl;
	else
		cout << "The Student " << firstName << " " << lastName << " was deleted" << endl;
	return;
}
template<class T>
void LinkedList<T>::deleteHeadTail()
{
	//Empty linked list
	if (head == NULL)
	{
		cout << "There is no any data in this list" << endl;
		cout << "You can not delete the head and tail node" << endl;
		return;
	}
	//There is only one node
	else if (head == tail)
	{
		T* temp = head;
		head = NULL;
		tail = NULL;
		delete temp;
		cout << "The head node was deleted" << endl;
		cout << "The tail node was deleted" << endl;
		cout << "There is no any data in this list" << endl;
		return;
	}
	//Delete the head node
	else
	{
		T* temp = head;
		head = head->getLink();
		delete temp;
		cout << "The head node was deleted" << endl;

		//There is only one node
		if (head == tail)
		{
			T* temp = head;
			head = NULL;
			tail = NULL;
			delete temp;
			cout << "The tail node was deleted" << endl;
			cout << "There is no any data in this list" << endl;
			return;
		}
	}
	//Delete the tail node
	T* left = head;
	T* right = head->getLink();
	while (right != tail)
	{
		left = left->getLink();
		right = right->getLink();
	}
	delete right;
	tail = left;
	tail->setLink(NULL);
	cout << "The tail node was deleted" << endl;
	return;
}
template<class T>
void LinkedList<T>::deleteList(bool signal)
{
	//Empty linked list
	if (head == NULL)
	{
		//If signal = true / 1, show this messege
		if (signal)
		{
			cout << "There is no any data in this list" << endl;
			cout << "You can not delete any data in this list" << endl;
			return;
		}
		//If signal = false / 0, show this messege
		else
		{
			if (typeid(T) == typeid(DomesticStudent))
				cout << "All the data in the Domestic Student List was successfully deleted" << endl;
			else if (typeid(T) == typeid(InternationalStudent))
				cout << "All the data in the International Student List was successfully deleted" << endl;
			return;
		}
	}
	

	//Loop for deleting the head node until head node equals to tail node
	while(head != tail)
	{
		T* temp = head;
		head = head->getLink();
		delete temp;
	}

	//There is only one node;
	T* temp = head;
	head = NULL;
	tail = NULL;
	delete temp;

	if (typeid(T) == typeid(DomesticStudent))
		cout << "All the data in the Domestic Student List was successfully deleted" << endl;
	else if (typeid(T) == typeid(InternationalStudent))
		cout << "All the data in the International Student List was successfully deleted" << endl;
}

//Serching Functions
template<class T>
void LinkedList<T>::searchId(const int id) const
{
	//Empty linked list
	if (head == NULL)
	{
		cout << "There is no any data in this list" << endl;
		cout << "You can not search any data" << endl;
		return;
	}

	bool found = false;
	bool signal = false;
	//Loop for searching the same id
	for (T* current = head; current != NULL; current = current->getLink())
	{
		if (current->getId() == id)
		{
			found = true;
			if (!signal)
			{
				cout << "This data is found" << endl;
				displayTitle();
				signal = true;
			}
			cout << *current << endl;
		}
	}

	//Display messege for no match found
	if (!found)
		cout << "No match found" << endl;
	return;
}
template<class T>
void LinkedList<T>::searchName(const string firstName, const string lastName)
{
	//Empty linked list
	if (head == NULL)
	{
		cout << "There is no any data in this list" << endl;
		cout << "You can not search any data" << endl;
		return;
	}

	string firstName_temp = firstName;
	string lastName_temp = lastName;
	modifyName(firstName_temp);
	modifyName(lastName_temp);

	bool found = false;
	bool signal = false;
	//Loop for searching the same name
	for (T* current = head; current != NULL; current = current->getLink())
	{
		if (current->getFirstName() == firstName_temp &&
			current->getLastName() == lastName_temp)
		{
			found = true;
			if (!signal)
			{
				cout << "This data is found" << endl;
				displayTitle();
				signal = true;
			}
			cout << *current << endl;
		}
	}

	//Display messege for no match found
	if (!found)
		cout << "No match found" << endl;
	return;
}
template<class T>
void LinkedList<T>::searchCgpa(const float cgpa) const
{
	//Empty linked list
	if (head == NULL)
	{
		cout << "There is no any data in this list" << endl;
		cout << "You can not search any data" << endl;
		return;
	}

	bool found = false;
	bool signal = false;
	//Loop for searching the same cgpa
	for (T* current = head; current != NULL; current = current->getLink())
	{
		if (current->getCgpa() == cgpa)
		{
			found = true;
			if (!signal)
			{
				cout << "This data is found" << endl;
				displayTitle();
				signal = true;
			}
			cout << *current << endl;
		}
	}

	//Display messege for no match found
	if (!found)
		cout << "No match found" << endl;
	return;
}
template<class T>
void LinkedList<T>::searchResearchScore(const int researchScore) const
{
	//Empty linked list
	if (head == NULL)
	{
		cout << "There is no any data in this list" << endl;
		cout << "You can not search any data" << endl;
		return;
	}

	bool found = false;
	bool signal = false;
	//Loop for searching the same research score
	for (T* current = head; current != tail; current = current->getLink())
	{
		if (current->getResearchScore() == researchScore)
		{
			found = true;
			if (!signal)
			{
				cout << "This data is found" << endl;
				displayTitle();
				signal = true;
			}
			cout << *current << endl;
		}
	}

	//Display messege for no match found
	if (!found)
		cout << "No match found" << endl;
	return;
}
template<class T>
void LinkedList<T>::searchSatified() const
{
	//Empty linked list
	if (head == NULL)
	{
		cout << "There is no any data in this list" << endl;
		cout << "You can not search any data" << endl;
		return;
	}

	float cgpa;
	int researchScore;
	cout << "Enter the minimum CGPA: "; cin >> cgpa;
	cout << "Enter the minimum Research Score: "; cin >> researchScore;
	cout << endl;
	
	int count = 0;
	bool found = false;
	bool signal = false;
	//Loop for finding the student who are satisfied the minimum CGPA and the minimum Research Score
	for (T* current = head; current != NULL; current = current->getLink())
	{
		if (current->getCgpa() >= cgpa && current->getResearchScore() >= researchScore)
		{
			found = true;
			if (!signal)
			{
				cout << "This data is found" << endl;
				displayTitle();
				signal = true;
			}
			cout << *current << endl;
			count++;
		}
	}

	if (!found)
		cout << "No match found" << endl;
	cout << "Total number of Students in this list: " << count << endl;
}

//Displaying Functions
template<class T>
void LinkedList<T>::displayTitle() const
{
	if (typeid(T) == typeid(DomesticStudent))
		cout << setw(10) << "ID" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(10) << "CGPA" << setw(10) << "Research" << setw(10) << "Province" << endl;
	else if (typeid(T) == typeid(InternationalStudent))
		cout << setw(10) << "ID" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(10) << "CGPA" << setw(10) << "Research" << setw(10) << "Country"
		<< setw(10) << "Reading" << setw(10) << "Listening"<< setw(10) << "Speaking"<< setw(10) << "Writing"<< setw(10) << "Total"<< setw(10) << "Pass\\Fail" << endl;
	else if (typeid(T) == typeid(Student))
		cout << setw(10) << "ID" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(10) << "CGPA" << setw(10) << "Research" << setw(10) << "Place"
		<< setw(10) << "Reading" << setw(10) << "Listening"<< setw(10) << "Speaking"<< setw(10) << "Writing"<< setw(10) << "Total"<< setw(10) << "Pass\\Fail" << endl;
}
template<class T>
void LinkedList<T>::displayList() const
{
	//Empty linked list
	if (head == NULL)
		cout << "There is no any data in this list" << endl;
	//Display the data
	else
	{
		displayTitle();
		int count = 0;
		for(T* current = head; current != NULL; current = current->getLink())
		{
			cout << *current << endl;
			count++;
		}
		cout << "Total number of Students in this list: " << count << endl;
	}
}

//Merging Functions
template<class T>
void LinkedList<T>::merge(LinkedList<DomesticStudent> &list1, LinkedList<InternationalStudent> &list2)
{
	//Setting the left and right pointer for two linked lists
	DomesticStudent* left = list1.getHead();
	InternationalStudent* right = list2.getHead();
	
	//Head node and tail node selection
	//List1 is empty linked list
	if (left == NULL)
	{
		//List2 is empty linked list or list2 head is not satisfied
		if (right == NULL || !right->checkToeflScore())
		{
			head = NULL;
			tail = NULL;
			return;
		}
		//List2 head is satisfied
		else
		{
			head = right;
			tail = right;
			right = right->getLink();
		}
	}
	//List1 is not empty linked list
	else
	{
		//List2 is empty linked list or list2 head is not satisfied)
		if (right == NULL || !right->checkToeflScore())
		{
			head = left;
			tail = left;
			left = left->getLink();
			right = NULL;
		}
		//List2 is not empty linked list and list2 head is satisfied
		else
		{
			if (compareAll(*left, *right) >= 0)
			{
				head = left;
				tail = left;
				left = left->getLink();
			}
			else
			{
				head = right;
				tail = right;
				right = right->getLink();
			}
		}
	}

	//Insert one of the data at the tail node
	//Both pointers are not point to NULL
	while(left != NULL && right != NULL && right->checkToeflScore())
	{
		if (compareAll(*left, *right) >= 0)
		{
			tail->setLink(left);
			tail = left;
			left = left->getLink();
		}
		else
		{
			tail->setLink(right);
			tail = right;
			right = right->getLink();
		}
	}
	//The left pointer does not reach the tail node, but right pointer reaches the tail node or not satisfied
	while(left != NULL)
	{
		tail->setLink(left);
		tail = left;
		left = left->getLink();
	}
	//The right pointer does not reach the tail node, but left pointer reaches the tail node
	while(right != NULL && right->checkToeflScore())
	{
		tail->setLink(right);
		tail = right;
		right = right->getLink();
	}
	//Set the tail node link to NULL - In some cases, the node is no longer link to NULL
	tail->setLink(NULL);
}

//Inputing Functions
template<class T>
void LinkedList<T>::storeDomesticStudentData()
{
	cout << "Starting to store Domestic Student Data into the list ......" << endl;

	//Open the domestic-stu.txt document
	//If the file is unable to open, then the program is out
    string line;
    ifstream domesticFile("F:/myCode/SFU/ensc251/Graduate Student Admission System/files/domestic-stu.txt");
    if(!domesticFile.is_open())
	{
        cout << "Unable to open file domestic-stu.txt" << endl;
        exit(1);
    }

    //Read the first line of domestic-stu.txt, which specifies the file format
    getline(domesticFile, line);

	//Input the information of Domestic Student appliants to this program
    while(getline(domesticFile, line) )
	{
		//Check the validity of the input
		checkInput_field(line);

		//Variables
        istringstream ss(line);
        string firstName, lastName, province, s_cgpa, s_researchScore;
        float cgpa;
        int researchScore;

        //get firstName separated by comma
        getline(ss, firstName, ',');
		//All the lastName in the format: The first letter is capital and the remaining letters are lowercase
		modifyName(firstName);

        //get lastName separated by comma
        getline(ss, lastName, ',');
		//All the lastName in the format: The first letter is capital and the remaining letters are lowercase
		modifyName(lastName);

        //get province separated by comma
        getline(ss, province, ',');

        //get cpga separated by comma, and convert string to float
        getline(ss, s_cgpa, ',');
        cgpa = atof(s_cgpa.c_str());

        //get researchScore separated by comma, and convert it to int
        getline(ss, s_researchScore, ',');
        researchScore = atoi(s_researchScore.c_str());

		//Pass all the values to the DomesticStudent Object
		DomesticStudent *temp = new DomesticStudent(firstName, lastName, cgpa, researchScore, province);
		insert(temp);
    }

    //close file
    domesticFile.close();

	cout << "All the Domestic Student data has been successfully stored in the list." << endl;
}
template<class T>
void LinkedList<T>::storeInternationalStudentData()
{
	cout << "Starting to store International Student Data into the list ......" << endl;

	//Open the international-stu.txt document
	//If the file is unable to open, then the program is out
    string line;
    ifstream internationalFile("F:/myCode/SFU/ensc251/Graduate Student Admission System/files/international-stu.txt");
    if(!internationalFile.is_open())
	{
        cout << "Unable to open file international-stu.txt" << endl;
        exit(1);
    }

    //Read the first line of international-stu.txt, which specifies the file format
    getline(internationalFile, line);

	//Input the information of International Student appliants to this program
    while(getline(internationalFile, line) )
	{
		//Check the validity of the input
		checkInput_field(line);

		//Variables
        istringstream ss(line);
        string firstName, lastName, country, s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;
        float cgpa;
        int researchScore, reading, listening, speaking, writing;

        //get firstName separated by comma
        getline(ss, firstName, ',');
		//All the lastName in the format: The first letter is capital and the remaining letters are lowercase
		modifyName(firstName);

        //get lastName separated by comma
        getline(ss, lastName, ',');
		//All the lastName in the format: The first letter is capital and the remaining letters are lowercase
		modifyName(lastName);

        //get country separated by comma
        getline(ss, country, ',');

        //get cpga separated by comma, and convert string to float
        getline(ss, s_cgpa, ',');
        cgpa = atof(s_cgpa.c_str());

        //get researchScore separated by comma, and convert it to int
        getline(ss, s_researchScore, ',');
        researchScore = atoi(s_researchScore.c_str());

		//get reading score separated by comma, and convert it to int
		getline(ss, s_reading, ',');
        reading = atoi(s_reading.c_str());

		//get listening score separated by comma, and convert it to int
		getline(ss, s_listening, ',');
        listening = atoi(s_listening.c_str());

		//get speaking score separated by comma, and convert it to int
		getline(ss, s_speaking, ',');
        speaking = atoi(s_speaking.c_str());

		//get writing score separated by comma, and convert it to int
		getline(ss, s_writing, ',');
        writing = atoi(s_writing.c_str());

		//Pass all the values to the InternationalStudent Object
        InternationalStudent* temp = new InternationalStudent(firstName, lastName, cgpa, researchScore, country, reading, listening, speaking, writing);
		insert(temp);
    }

    //close file
    internationalFile.close();

	cout << "All the International Student data has been successfully stored in the list." << endl;
}

//Checking Functions
template<class T>
void LinkedList<T>::checkInput_field(string &line)
{
	int count = 0;
	int length = line.length();

	for (int i = 0; i < length; i++)
	{
		if (line[i] == ',')
			count++;
	}

	if (typeid(T) == typeid(DomesticStudent))
	{
		if (count != 4)
		{
			cout << "Input Error! One of the field is missing. Exit the program.\n";
			exit(1);
		}
	}
	else if (typeid(T) == typeid(InternationalStudent))
	{
		if (count != 8)
		{
			cout << "Input Error! One of the field is missing. Exit the program.\n";
			exit(1);
		}
	}
}

//Modifying Functions
template<class T>
void LinkedList<T>::modifyName(string& name)
{
	name[0] = toupper(name[0]);
	for (int i = 1; i < name.length(); i++)
	{
		name[i] = tolower(name[i]);
	}
}
#endif //LINKEDLIST_H