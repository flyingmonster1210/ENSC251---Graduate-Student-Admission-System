///////////////////////////////////////////////////////////////////////////////////////////////////////
// Header file ToeflScore.h                                                                          //
// This is the interface for the class ToeflScore.                                                   //
// This class contains the TOEFL Score (reading, listening, speaking, writing, total score).         //
// Last-Modified: 2020/03/22                                                                    //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef TOEFLSCORE_H
#define TOEFLSCORE_H

#include "Student.h"

class ToeflScore
{
//Private Member Variables
private:
	int reading, listening, speaking, writing;
	int totalScore;

//Public Member Functions
public:
	//Constructors
	ToeflScore();
	ToeflScore(int reading, int listening, int speaking, int writing);

	//Getters
	int getReading() const;
    int getListening() const;
    int getSpeaking() const;
    int getWriting() const;
    int getTotalScore() const;

	//Setters
	void setReading(const int reading);
    void setListening(const int listening);
    void setSpeaking(const int speaking);
    void setWriting(const int writing);

	//Checking Functions
	void checkScore(const int &score); //This function checks the input (cgpa) that satisfied between 0 - 30
	//Error out if the input is not satisfied
	void calculateTotalScore(); //Call this function to recalculate the TOEFL Score if there is any change in one of the categories

	//Operator Overloading Functions
	friend ostream& operator << (ostream &out, const ToeflScore& t);
	friend istream& operator >> (istream &in, ToeflScore& t);
};
#endif