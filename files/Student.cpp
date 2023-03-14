///////////////////////////////////////////////////////////////////////////////////////////////////////
// Implementation file Student.cpp                                                                   //
// This is the implementation of the class Student.                                                  //
// The interface for the class Student is in the header file Student.h                               //
// Last-Modified: 2020/03/22                                                                        //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Student.h"

//Private static Variables
int Student::studentCount = 0;

//Public Member Functions
//Constructors
Student::Student()
{
	id = (++studentCount) + STARTING_ID;
	firstName = "";
	lastName = "";
	cgpa = 0.0;
	researchScore = 0;
	link = NULL;
}
Student::Student(string firstName, string lastName, float cgpa, int researchScore)
{
	checkName(firstName);
	checkName(lastName);
	checkCgpa(cgpa);
	checkResearchScore(researchScore);

	this->id = (++studentCount) + STARTING_ID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->cgpa = cgpa;
	this->researchScore = researchScore;
	link = NULL;
}

//Getters
int Student::getId() const
{
	return id;
}
string Student::getFirstName() const
{
	return firstName;
}
string Student::getLastName() const
{
	return lastName;
}
float Student::getCgpa() const
{
	return cgpa;
}
int Student::getResearchScore() const
{
	return researchScore;
}
Student* Student::getLink() const
{
	return link;
}

//Setters
void Student::setFirstName(const string firstName)
{
	checkName(firstName);
	this->firstName = firstName;
}
void Student::setLastName(const string lastName)
{
	checkName(lastName);
	this->lastName = lastName;
}
void Student::setCgpa(const float cgpa)
{
	checkCgpa(cgpa);
	this->cgpa = cgpa;
}
void Student::setResearchScore(const int researchScore)
{
	checkResearchScore(researchScore);
	this-> researchScore = researchScore;
}
void Student::setLink(Student* link)
{
	this->link = link;
}

//Checking Functions
void Student::checkName(const string &name) const
{
	int length = name.length();

	//Empty name
	if (length == 0)
	{
		cout << "This name is a empty name which is invalid." << endl;
		cout << "Illegal input data. Exit the program." << endl;
		exit(1);
	}
	
	//Check the first letter
	if (name[0] < 'A' || name[0] > 'Z')
	{
		cout << "This name " << name << " is invalid." << endl;
		cout << "The first letter of the name should be in uppercase." << endl;
		cout << "Illegal input data. Exit the program." << endl;
		exit(1);
	}

	//Check the remaining letters
	for (int i = 1; i < length; i++)
	{
		if (name[i] >= 'A' && name[i] <= 'Z')
		{
			cout << "This name " << name << " is invalid." << endl;
			cout << "All the remaining letters of the name should be in lowercase." << endl;
			cout << "Illegal input data. Exit the program." << endl;
			exit(1);
		}
	}
}
void Student::checkCgpa(const float &cgpa) const
{
	if (cgpa < 0.0 || cgpa > 4.33)
	{
		cout << "This CGPA " << cgpa << " is invalid." << endl;
		cout << "The range of CGPA is 0 to 4.33." << endl;
		cout << "Illegal input data. Exit the program.\n";
		exit(1);
	}
}
void Student::checkResearchScore(const int &researchScore) const
{
	if (researchScore < 0 || researchScore > 100)
	{
		cout << "This Research Score " << researchScore << " is invalid." << endl;
		cout << "The range of Research Score is 0 to 100." << endl;
		cout << "Illegal input data. Exit the program.\n";
		exit(1);
	}
}

//Virtual Functions
void Student::printStudent() const
{
	cout << setw(10) << id;
	cout << setw(15) << firstName;
	cout << setw(15) << lastName;
	cout << setw(10) << cgpa;
	cout << setw(10) << researchScore;
}
bool Student::checkToeflScore() const
{
	return true;
}

//Friend Functions
//Operator Overloading Functions
ostream& operator << (ostream &out, const Student &s)
{
	s.printStudent();

	return out;
}
istream& operator >> (istream &in, Student &s)
{
	string firstName, lastName;
	float cgpa;
	int researchScore;

	cout << "Enter the first name: "; in >> firstName;
	s.checkName(firstName);
	cout << "Enter the last name: "; in >> lastName;
	s.checkName(lastName);
	cout << "Enter the cgpa: "; in >> cgpa;
	s.checkCgpa(cgpa);
	cout << "Enter the research score: "; in >> researchScore;
	s.checkResearchScore(researchScore);

	s.firstName = firstName;
	s.lastName = lastName;
	s.cgpa = cgpa;
	s.researchScore = researchScore;

	return in;
}

//Comparing Functions
//Ascending Order: First Name, Last Name
//Descending Order: CGPA, Research Score
//Return 1 - the first student has higher priority
//Return -1 - the second student has higher priority
//Return 0 - they are the same
int compareFirstName(const Student &s1, const Student &s2) 
{
    if(s1.firstName < s2.firstName) 
		return 1;
    else if(s1.firstName > s2.firstName) 
		return -1;
	else
		return 0;
}
int compareLastName(const Student &s1, const Student &s2) 
{
    if(s1.lastName < s2.lastName) 
		return 1;
    else if(s1.lastName > s2.lastName)
		return -1;
	else
		return 0;
}
int compareCgpa(const Student &s1, const Student &s2)
{
    if(s1.cgpa > s2.cgpa)
		return 1;
    else if(s1.cgpa < s2.cgpa)
		return -1;
	else
		return 0;
}
int compareResearchScore(const Student &s1, const Student &s2) 
{
    if(s1.researchScore > s2.researchScore)
		return 1;
    else if(s1.researchScore < s2.researchScore)
		return -1;
	else
		return 0;
}
int compareAll(const Student &s1, const Student &s2)
{
	int compareIndex = compareResearchScore(s1, s2);
	if (compareIndex != 0)
		return compareIndex;
	else
	{
		compareIndex = compareCgpa(s1, s2);
		if (compareIndex != 0)
			return compareIndex;
		else
			return 0;
	}
}