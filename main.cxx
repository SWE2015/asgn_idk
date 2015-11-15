#include "List.hxx"
#include <iostream>
#include <string>
#include <cstring>

struct Student
{
	char name[20];
	int id;
	int year, month, date; //of birth

	Student& operator=(const Student& other) // copy assignment
	{
		memcpy(name, other.name, 20);
		id = other.id;
		year = other.year;
		month = other.month;
		date = other.date;
	}

};

Student MakeStudent(
	char* name,
	int id,
	int year, int month, int date)
{
	Student s;
	memcpy(s.name, name, 20);
	s.id = id;
	s.year = year;
	s.month = month;
	s.date = date;
	return s;
}

using namespace std;
int main(int argc, char const *argv[])
{
	List<Student> l;
	cout << "Size of l: " << l.getsize() << endl;
	cout << "Storage size: " << l.getbufsize() << endl;

	l << MakeStudent("John Doe", 201512345, 1990, 10, 1) <<
		MakeStudent("Beth Ruh", 120243434, 1980, 3, 27) <<
		MakeStudent("Martin Wise", 120243434, 1980, 3, 27) <<
		MakeStudent("Bowden Graham", 120243434, 1980, 3, 27) <<
		MakeStudent("James Immelt", 122448776, 1988, 8, 7);

	cout << "Size of l: " << l.getsize() << endl;
	cout << "Storage size: " << l.getbufsize() << endl;
	cout << "Name of 2nd student is : (" << l[1].name << ")." << endl;

	int i = 5;
	while (i-->0)
	{
		l.remove(0);
		cout << "Removed first student. Size of l: " << l.getsize() << endl;
		cout << "Storage size: " << l.getbufsize() << endl;
		cout << "Name of first student is : (" << l[0].name << ")." << endl;

	}
	return 0;
}