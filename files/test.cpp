#include "Student.h"
#include "DomesticStudent.h"
#include "InternationalStudent.h"
#include "ToeflScore.h"

//Error testing (Classes)
int main()
{
	string firstName = "Vancouver";
	string lastName = "Burnaby";
	float cgpa = 4.33;
	int researchScore = 100;
	string province = "BC";
	int reading = 30, listening = 30, speaking = 30, writing = 30;
	string country = "Canada";

	/*
	//Student Class
	//Normal Case
	//Student s1(firstName, lastName, cgpa, researchScore);
	//cout << s1 << endl;

	//Test the First Name
	//Empty name
	//Student s2("", lastName, cgpa, researchScore);
	//cout << s2 << endl;

	//Non-English letter
	//Student s3("1Vancouver1", lastName, cgpa, researchScore);
	//cout << s3 << endl;

	//First letter is not a uppercase
	//Student s4("vancouver", lastName, cgpa, researchScore);
	//cout << s4 << endl;

	//One of the remaining letters is not a lowercase
	//Student s5("VancouveR", lastName, cgpa, researchScore);
	//cout << s5 << endl;

	//Test the Last Name
	//Empty name
	//Student s6(firstName, "", cgpa, researchScore);
	//cout << s6 << endl;

	//Non-English letter
	//Student s7(firstName, "Burnaby1", cgpa, researchScore);
	//cout << s7 << endl;

	//First letter is not a uppercase
	//Student s8(firstName, "burnaby", cgpa, researchScore);
	//cout << s8 << endl;

	//One of the remaining letters is not a lowercase
	//Student s9(firstName, "BurnabY", cgpa, researchScore);
	//cout << s9 << endl;

	//Test CGPA
	//Out of the upper range
	//Student s10(firstName, lastName, 4.4, researchScore);
	//cout << s10 << endl;

	//Out of the lower range
	//Student s11(firstName, lastName, -1, researchScore);
	//cout << s11 << endl;

	//Test Research Score
	//Out of the upper range
	//Student s12(firstName, lastName, cgpa, 101);
	//cout << s12 << endl;

	//Out of the lower range
	//Student s13(firstName, lastName, cgpa, -1);
	//cout << s13 << endl;
	*/



	/*
	//DomesticStudent Class
	//Normal Case
	//DomesticStudent d1(firstName, lastName, cgpa, researchScore, province);
	//cout << d1 << endl;

	//Invalid province name
	//DomesticStudent d2(firstName, lastName, cgpa, researchScore, "AC");
	//cout << d2 << endl;
	*/



	/*
	//ToeflScore Class
	//Normal Case
	//ToeflScore t1(reading, listening, speaking, writing);
	//cout << t1 << endl;

	//Invalid reading score
	//ToeflScore t2(31, listening, speaking, writing);
	//cout << t2 << endl;

	//Invalid listening score
	//ToeflScore t3(reading, 31, speaking, writing);
	//cout << t3 << endl;

	//Invalid speaking score
	//ToeflScore t4(reading, listening, -1, writing);
	//cout << t4 << endl;

	//Invalid writing score
	//ToeflScore t5(reading, listening, speaking, -1);
	//cout << t5 << endl;
	*/



	/*
	//InternationalStudent Class
	//Normal Case
	//InternationalStudent i1(firstName, lastName, cgpa, researchScore, country, reading, listening, speaking, writing);
	//cout << i1 << endl;

	//Invalid country name
	//InternationalStudent i2(firstName, lastName, cgpa, researchScore, "ABC", reading, listening, speaking, writing);
	//cout << i2 << endl;

	//Invalid country name (Idian)
	//InternationalStudent i3(firstName, lastName, cgpa, researchScore, "Idian", reading, listening, speaking, writing);
	//cout << i3 << endl;
	*/

	system("Pause");
	return 0;
}