///////////////////////////////////////////////////////////////////////////////////////////////////////
// Implementation file InternationalStudent.cpp                                                      //
// This is the implementation of the class InternationalStudent.                                     //
// The interface for the class InternationalStudent is in the header file InternationalStudent.h     //
// Last-Modified: 2020/03/22                                                                       //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include "InternationalStudent.h"

//Private static Variables
const string InternationalStudent::COUNTRY[COUNTRY_SIZE] = {"Canada", "China", "India", "Iran", "Korea"};

//Public Member Functions
//Constructors
InternationalStudent::InternationalStudent() : Student(), score()
{
	country = "";
	link = NULL;
}
InternationalStudent::InternationalStudent(string firstName, string lastName, float cgpa, int researchScore,
	string country, int reading, int listening, int speaking, int writing) : Student(firstName, lastName, cgpa,
	researchScore), score(reading, listening, speaking, writing)
{
	if (!checkCountry(country))
		fixCountry(country);

	this->country = country;
	link = NULL;
}

//Getters
string InternationalStudent::getCountry() const
{
	return country;
}
int InternationalStudent::getReading() const
{
	return score.getReading();
}
int InternationalStudent::getListening() const
{
	return score.getListening();
}
int InternationalStudent::getSpeaking() const
{
	return score.getSpeaking();
}
int InternationalStudent::getWriting() const
{
	return score.getWriting();
}
int InternationalStudent::getTotalScore() const
{
	return score.getTotalScore();
}
InternationalStudent* InternationalStudent::getLink() const
{
	return link;
}

//Setters
void InternationalStudent::setCountry(const string country)
{
	string temp = country;
	if (!checkCountry(temp))
		fixCountry(temp);

	this->country = temp;
}
void InternationalStudent::setReading(const int reading)
{
	score.setReading(reading);
}
void InternationalStudent::setListening(const int listening)
{
	score.setListening(listening);
}
void InternationalStudent::setSpeaking(const int speaking)
{
	score.setSpeaking(speaking);
}
void InternationalStudent::setWriting(const int writing)
{
	score.setWriting(writing);
}
void InternationalStudent::setLink(InternationalStudent* link)
{
	this->link = link;
}

//Checking Functions
bool InternationalStudent::checkCountry(const string &country)
{
	for (int i = 0; i < 5; i++)
	{
		if (country == COUNTRY[i])
			return true;
	}
	return false;
}
void InternationalStudent::fixCountry(string& country)
{
	if (country == "Idian")
	{
		// cout << "This country name " << country << " is invalid." << endl;
		country = "India";
		// cout << "It has been modified as " << country << "." << endl;
	}
	else
	{
		// cout << "This country name " << country << " is invalid." << endl;
		// cout << "The country name should be one of the";
		for (int i = 0; i < COUNTRY_SIZE; i++)
			// cout << " " << COUNTRY[i];
		// cout << "." << endl;
		// cout << "Illegal input data. Exit the program." << endl;
		exit(1);
	}
}

//Virtual Functions
void InternationalStudent::printStudent() const
{
	static_cast<Student>(*this).printStudent();
	cout << setw(10) << country;
	cout << score;

	if (checkToeflScore())
		cout << setw(10) << "P";
	else
		cout << setw(10) << "F";
}
bool InternationalStudent::checkToeflScore() const
{
	if (getTotalScore() < 93)
		return false;
	else if (getReading() < 20 || getListening() < 20 || getSpeaking() < 20 || getWriting() < 20)
		return false;

	return true;
}

//Friend Functions
//Operator Overloading Functions
ostream& operator << (ostream &out, const InternationalStudent &s)
{
	s.printStudent();

	return out;
}
istream& operator >> (istream &in, InternationalStudent &s)
{
	Student &temp = s;
	ToeflScore &tempScore = s.score;
	in >> temp;
	in >> tempScore;
	
	string country;
	cout << "Enter the country: "; in >> country;
	if (!s.checkCountry(country))
		s.fixCountry(country);

	s.country = country;

	return in;
}

//Comparing Functions
//Ascending Order: Country
//CompareAll Order: Research, CGPA, Country
//Return 1 - the first student has higher priority
//Return -1 - the second student has higher priority
//Return 0 - they are the same
int compareCountry(const InternationalStudent &s1, const InternationalStudent &s2)
{
	if(s1.country < s2.country) 
		return 1;
    else if(s1.country > s2.country) 
		return -1;
	else
		return 0;
}
int compareAll(const InternationalStudent &s1, const InternationalStudent &s2)
{
	//Always return -1 if the first student Toefl Score is not satisfy
	if (!s1.checkToeflScore())
		return -1;
	//Returns 1 if the second student Toefl Score is not satisfy
	else if (!s2.checkToeflScore())
		return 1;

	int compareIndex = compareResearchScore(s1, s2);
	if (compareIndex != 0)
		return compareIndex;
	else
	{
		compareIndex = compareCgpa(s1, s2);
		if (compareIndex != 0)
			return compareIndex;
		else
			return compareCountry(s1, s2);
	}	
}