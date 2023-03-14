#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o and Student.o to executable main
main: main.o Student.o DomesticStudent.o InternationalStudent.o ToeflScore.o LinkedList.o
	g++ -g -o main main.o Student.o DomesticStudent.o InternationalStudent.o ToeflScore.o LinkedList.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp

#compile the Student.cpp to Student.o
Student.o: Student.cpp
	g++ -g -c Student.cpp

DomesticStudent.o: DomesticStudent.cpp
	g++ -g -c DomesticStudent.cpp

InternationalStudent.o: InternationalStudent.cpp
	g++ -g -c InternationalStudent.cpp

ToeflScore.o: ToeflScore.cpp
	g++ -g -c ToeflScore.cpp

LinkedList.o: LinkedList.cpp
	g++ -g -c LinkedList.cpp

#remove built files
clean:
	rm -rf main main.o Student.o DomesticStudent.o InternationalStudent.o ToeflScore.o LinkedList.o *~