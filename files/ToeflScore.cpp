///////////////////////////////////////////////////////////////////////////////////////////////////////
// Implementation file ToeflScore.cpp                                                                //
// This is the implementation of the class ToeflScore.                                               //
// The interface for the class ToeflScore is in the header file ToeflScore.h                         //
// Last-Modified: 2020/03/22                                                                          //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include "ToeflScore.h"

//Public Member Functions
//Constructors
ToeflScore::ToeflScore()
{
	reading = 0;
	listening = 0;
	speaking = 0;
	writing = 0;
	totalScore = 0;
}
ToeflScore::ToeflScore(int reading, int listening, int speaking, int writing)
{
	checkScore(reading);
	checkScore(listening);
	checkScore(speaking);
	checkScore(writing);

	this->reading = reading;
	this->listening = listening;
	this->speaking = speaking;
	this->writing = writing;

	calculateTotalScore();
}

//Getters
int ToeflScore::getReading() const
{
	return reading;
}
int ToeflScore::getListening() const
{
	return listening;
}
int ToeflScore::getSpeaking() const
{
	return speaking;
}
int ToeflScore::getWriting() const
{
	return writing;
}
int ToeflScore::getTotalScore() const
{
	return totalScore;
}

//Setters
void ToeflScore::setReading(const int reading)
{
	checkScore(reading);
	this->reading = reading;
	calculateTotalScore();
}
void ToeflScore::setListening(const int listening)
{
	checkScore(listening);
	this->listening = listening;
	calculateTotalScore();
}
void ToeflScore::setSpeaking(const int speaking)
{
	checkScore(speaking);
	this->speaking = speaking;
	calculateTotalScore();
}
void ToeflScore::setWriting(const int writing)
{
	checkScore(writing);
	this->writing = writing;
	calculateTotalScore();
}

//Checking Functions
void ToeflScore::checkScore(const int &score)
{
	if (score < 0 || score > 30)
	{
		cout << "This score " << score << " is invalid." << endl;
		cout << "It should be in the range between 0 to 30." << endl;
		cout << "Illegal intput data. Exit the program." << endl;
		exit(1);
	}
}
void ToeflScore::calculateTotalScore()
{
	totalScore = reading + listening + speaking + writing;
}

//Operator Overloading Functions
ostream& operator << (ostream &out, const ToeflScore& t)
{
	out << setw(10) << t.reading;
	out << setw(10) << t.listening;
	out << setw(10) << t.speaking;
	out << setw(10) << t.writing;
	out << setw(10) << t.totalScore;

	return out;
}
istream& operator >> (istream &in, ToeflScore& t)
{
	int reading, listening, speaking, writing;
	cout << "Enter the reading score: "; in >> reading;
	t.checkScore(reading);
	cout << "Enter the listening score: "; in >> listening;
	t.checkScore(listening);
	cout << "Enter the speaking score: "; in >> speaking;
	t.checkScore(speaking);
	cout << "Enter the writing score: "; in >> writing;
	t.checkScore(writing);

	t.reading = reading;
	t.listening = listening;
	t.speaking = speaking;
	t.writing = writing;
	t.calculateTotalScore();

	return in;
}