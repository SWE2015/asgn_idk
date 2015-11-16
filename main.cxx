#include "List.hxx"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Student
{
	std::string name;
	int id;
	int year, month, date; //of birth
	Student(std::string name_, int id_, int year_, int month_, int date_) : 
	name(name_), year(year_), month(month_), date(date_) {}
	Student(){};
};

Student* MakeStudent(
	std::string name,
	int id,
	int year, int month, int date)
{
	Student *s = new Student();
	s->name = name;
	s->id = id;
	s->year = year;
	s->month = month;
	s->date = date;
	return s;
}


void testWithString()
{
	List<std::string> l;
	l.push_new("Hello");
	l.push_new("That's a string");
	std::cout << *l[0] << std::endl;
}

void tewstWithStudent()
{
	List<Student> l;
	cout << "Size of l: " << l.getsize() << endl;
	cout << "Storage size: " << l.getbufsize() << endl;

	l.push(MakeStudent(std::string("John Doe"), 201512345, 1990, 10, 1));
	l.push(MakeStudent(std::string("Beth Ruh"), 120243434, 1980, 3, 27));
	l.push(MakeStudent(std::string("James Immelt"), 122448776, 1988, 8, 7));
	l.push_new(std::string("Martin Wise"), 120243434, 1980, 3, 27);
	l.push_new(std::string("Bowden Graham"), 120243434, 1980, 3, 27);

	cout << "Size of l: " << l.getsize() << endl;
	cout << "Storage size: " << l.getbufsize() << endl;
	cout << "Name of 2nd student is : (" <<(*l[1]).name << ")." << endl;

	int i = 5;
	while (i-->0)
	{
		l.remove(0);
		cout << "Removed first student. Size of l: " << l.getsize() << endl;
		cout << "Storage size: " << l.getbufsize() << endl;
		cout << "Name of first student is : (" << (*l[0]).name << ")." << endl;
	}
}

int main(int argc, char const *argv[])
{
	testWithString();
	tewstWithStudent();
	return 0;
}
