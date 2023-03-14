///////////////////////////////////////////////////////////////////////////////////////////////////////
// Header file InternationalStudent.h                                                                //
// This is the interface for the class InternationalStudent.                                         //
// This class inherites from the class Student and includes the class ToeflScore.                    //
// This class contains the student data (country, TOEFL Score).                                      //
// Also, this contains a link pointing to another InternationalStudent object.                       //
// Last-Modified: 2020/03/22                                                                          //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef INTERNATIONALSTUDENT_H
#define INTERNATIONALSTUDENT_H

#include "Student.h"
#include "ToeflScore.h"

class InternationalStudent : public Student
{
//Private static Variables
private:
	static const int COUNTRY_SIZE = 5;
	static const string COUNTRY[];

//Private Member Variables
private:
	string country;
	ToeflScore score;
	InternationalStudent* link;

//Public Member Functions
public:
	//Constructors
	InternationalStudent();
	InternationalStudent(string firstName, string lastName, float cgpa, int researchScore, string country, int reading, int listening, int speaking, int writing);

	//Getters
	string getCountry() const;
	int getReading() const;
    int getListening() const;
    int getSpeaking() const;
    int getWriting() const;
    int getTotalScore() const;
	InternationalStudent* getLink() const;

	//Setters
	void setCountry(const string country);
	void setReading(const int reading);
    void setListening(const int listening);
    void setSpeaking(const int speaking);
    void setWriting(const int writing);
	void setLink(InternationalStudent* link);

	//Checking Functions
	bool checkCountry(const string &country); //This function checks the country is valid or not
	//Returns true if it is valid, otherwise returns false
	void fixCountry(string &country); //This function fixes the country name if the input is "Idian"

	//Virtual Functions
	virtual void printStudent() const;
	virtual bool checkToeflScore() const; //This function checks the TOEFL Score is satisified the entry requirement
	//Requirement: Minimum 20 in each categorie and the minimum 93 in total score
	//Returns true if it is satisfied, otherwise returns false

	//Friend Functions
	//Operator Overloading Functions
	friend ostream& operator << (ostream &out, const InternationalStudent &s);
	friend istream& operator >> (istream &in, InternationalStudent &s);

	//Comparing Functions
	//Ascending Order: Country
	//CompareAll Order: Research, CGPA, Country
	//Return 1 - the first student has higher priority
	//Return -1 - the second student has higher priority
	//Return 0 - they are the same
	//Remark: always return -1 if the first student Toefl Score is not satisfy
	friend int compareCountry(const InternationalStudent &s1, const InternationalStudent &s2);
	friend int compareAll(const InternationalStudent &s1, const InternationalStudent &s2);
};
#endif