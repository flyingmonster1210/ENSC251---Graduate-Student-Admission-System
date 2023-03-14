///////////////////////////////////////////////////////////////////////////////////////////////////////
// Header file Student.h                                                                             //
// This is the interface for the class Student.                                                      //
// This class contains the student data (id, first name, last name, cgpa, research score).           //
// Also, this contains a link pointing to another Stduent object.                                    //
// Last-Modified: 2020/03/22                                                                          //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <typeinfo>
using namespace std;

class Student
{
//Private static Variables
private:
	static int studentCount; //This variable stores the total number of students
	static const int STARTING_ID = 20200000;

//Protected Member Variables
protected:
	int id;
	string firstName;
	string lastName;
	float cgpa;
	int researchScore;
	Student* link;

//Public Member Functions
public:
	//Constructors
	Student(); //Every time calling this constructor will increment the stu_count by 1
	Student(string firstName, string lastName, float cgpa, int researchScore); //Every time calling this constructor will increment the stu_count by 1

	//Getters
	int getId() const;
	string getFirstName() const;
	string getLastName() const;
	float getCgpa() const;
	int getResearchScore() const;
	Student* getLink() const;
	
	//Setters
	void setFirstName(const string firstName);
	void setLastName(const string lastName);
	void setCgpa(const float cgpa);
	void setResearchScore(const int researchScore);
	void setLink(Student* link);

	//Checking Functions (Error out if the input is not satisfied)
	void checkName(const string &name) const; //This function checks the first name or last name that satisfied the first letter is in uppercase and the remaining letters are in lowercase
	void checkCgpa(const float &cgpa) const; //This function checks the cgpa that satisfied between 0.0 - 4.33
	void checkResearchScore(const int &researchScore) const; //This function checks the research score is satisfied between 0 - 100

	//Virtual Functions
	virtual void printStudent() const;
	virtual bool checkToeflScore() const; //This returns true

	//Friend Functions
	//Operator Overloading Functions
	friend ostream& operator << (ostream &out, const Student &s);
	friend istream& operator >> (istream &in, Student &s);

	//Comparing Functions
	//Ascending Order: First Name, Last Name
	//Descending Order: CGPA, Research Score
	//Return 1 - the first student has higher priority
	//Return -1 - the second student has higher priority
	//Return 0 - they are the same
    friend int compareFirstName(const Student &s1, const Student &s2);
    friend int compareLastName(const Student &s1, const Student &s2);
	friend int compareCgpa(const Student &s1, const Student &s2);
	friend int compareResearchScore(const Student &s1, const Student &s2);
	friend int compareAll(const Student &s1, const Student &s2);
};
#endif