///////////////////////////////////////////////////////////////////////////////////////////////////////
// Header file DomesticStudent.h                                                                     //
// This is the interface for the class DomesticStudent.                                              //
// This class inherites from the class Student.                                                      //
// This class contains the student data (province).                                                  //
// Also, this contains a link pointing to another DomesticStudent object.                            //
// Last-Modified: 2020/03/22                                                                         //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef DOMESTICSTUDENT_H
#define DOMESTICSTUDENT_H

#include "Student.h"

class DomesticStudent : public Student
{
//Private static Variables
private:
	static const int CANADA_PROVINCE_SIZE = 13;
	static const string CANADA_PROVINCE[];

//Protected Member Variables
protected:
	string province;
	DomesticStudent* link;

//Public Member Functions
public:
	//Constructors
	DomesticStudent();
	DomesticStudent(string firstName, string lastName, float cgpa, int researchScore, string province);

	//Getters
	string getProvince() const;
	DomesticStudent* getLink() const;

	//Setters
	void setProvince(const string province);
	void setLink(DomesticStudent* link);

	//Checking Functions
	void checkProvince(const string &province) const;

	//Virtual Functions
	void printStudent() const;

	//Friend Functions
	//Operator Overloading Functions
	friend ostream& operator << (ostream &out, const DomesticStudent &s);
	friend istream& operator >> (istream &in, DomesticStudent &s);

	//Comparing Functions
	//Ascending Order: Province
	//CompareAll Order: Research, CGPA, Province
	//Return 1 - the first student has higher priority
	//Return -1 - the second student has higher priority
	//Return 0 - they are the same
	friend int compareProvince(const DomesticStudent &s1, const DomesticStudent &s2);
	friend int compareAll(const DomesticStudent &s1, const DomesticStudent &s2);
};
#endif