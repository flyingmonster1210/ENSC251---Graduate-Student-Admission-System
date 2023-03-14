///////////////////////////////////////////////////////////////////////////////////////////////////////
// Implementation file DomesticStudent.cpp                                                           //
// This is the implementation of the class DomesticStudent.                                          //
// The interface for the class DomesticStudent is in the header file DomesticStudent.h               //
// Last-Modified: 2020/03/22                                                                        //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include "DomesticStudent.h"

//Private static Variables
const string DomesticStudent::CANADA_PROVINCE[CANADA_PROVINCE_SIZE] = {"NL", "PE", "NS", "NB", "QC", "ON", "MB", "SK", "AB", "BC", "YT", "NT", "NU"};

//Public Member Functions
//Constructors
DomesticStudent::DomesticStudent() : Student()
{
	province = "";
	link = NULL;
}
DomesticStudent::DomesticStudent(string firstName, string lastName, float cgpa, int researchScore, string province) : Student(firstName, lastName, cgpa, researchScore)
{
	checkProvince(province);
	this->province = province;
	link = NULL;
}

//Getters
string DomesticStudent::getProvince() const
{
	return province;
}
DomesticStudent* DomesticStudent::getLink() const
{
	return link;
}

//Setters
void DomesticStudent::setProvince(const string province)
{
	checkProvince(province);
	this->province = province;
}
void DomesticStudent::setLink(DomesticStudent* link)
{
	this->link = link;
}

//Checking Functions
void DomesticStudent::checkProvince(const string &province) const
{
	for (int i = 0; i < CANADA_PROVINCE_SIZE; i++)
	{
		if (province == CANADA_PROVINCE[i])
			return;
	}
	cout << "This province " << province << " is invalid." << endl;
	cout << "The province name should be one of the";
	for (int i = 0; i < CANADA_PROVINCE_SIZE; i++)
		cout << " " << CANADA_PROVINCE[i];
	cout << "." << endl;
	cout << "Illegal input data. Exit the program." << endl;
	exit(1);
}

//Virtual Functions
void DomesticStudent::printStudent() const
{
	static_cast<Student>(*this).printStudent();
	cout << setw(10) << province;
}

//Friend Functions
//Operator Overloading Functions
ostream& operator << (ostream &out, const DomesticStudent &s)
{
	s.printStudent();

	return out;
}
istream& operator >> (istream &in, DomesticStudent &s)
{
	Student &temp = s;
	in >> temp;

	string province;
	cout << "Enter the province: "; in >> province;
	s.checkProvince(province);
	s.province = province;

	return in;
}

//Comparing Functions
//Ascending Order: Province
//CompareAll Order: Research, CGPA, Province
//Return 1 - the first student has higher priority
//Return -1 - the second student has higher priority
//Return 0 - they are the same
int compareProvince(const DomesticStudent &s1, const DomesticStudent &s2)
{
	if(s1.province < s2.province) 
		return 1;
    else if(s1.province > s2.province) 
		return -1;
	else
		return 0;
}
int compareAll(const DomesticStudent &s1, const DomesticStudent &s2)
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
			return compareProvince(s1, s2);
	}
}