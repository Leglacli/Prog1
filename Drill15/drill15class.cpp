#include <iostream>

using namespace std;


struct Person
{
	Person(){};
	Person(string nm, int x) {name = nm, age = x;}
	string getname() const {return name;}
	int getage() const {return age;}

private:
	string name;
	int age;
};

ostream& operator<<(ostream& os, const Person& p)
{
	os << "Name is " << p.getname() << " and age is " << p.getage() << endl;
	return os;
}

istream& operator>>(istream& is, Person& p)
{
	string name;
	int age;

	is >> name;
	is >> age;

	p = Person(name, age);
	return is;
}

int main()
{
	Person person1 ("Goofy", 63);
	cout << "Name is " << person1.getname() << " and age is " << person1.getage() << endl;
	cout << person1;

	cout << "Enter name and age of a person" << endl;
	Person person2;
	cin >> person2;
	cout << person2;
}