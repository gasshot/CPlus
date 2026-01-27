#include<stdio.h>
#include<iostream>

using namespace std;

class Student 
{
private:
	char* name;
	int age;
	char* hobby;
public:
	void ShowInfo();
	void SetInfo(char* _name, int _age, char* _hobby);
	void Study();
	void Sleep();
};

int main() 
{
	Student s;
	s.SetInfo("Kim", 18, "Game");

	return 0;
}

void Student::ShowInfo() 
{
	cout << "Name: " << name << ", Age: " << age << ", Hobby:" << hobby << std::endl;
}

void Student::SetInfo(char* _name, int _age, char* _hobby)
{
	name = _name;
	age = _age;
	hobby = _hobby;
}

void Student::Study()
{
	cout << "STUDY" << endl;
}

void Student::Sleep()
{
	cout << "SLEEP" << endl;
}