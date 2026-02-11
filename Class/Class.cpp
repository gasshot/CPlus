#include<iostream>
#include "Class.h"

class Animal {
private: // 접근	제한(지정)자
	int food; // 멤버 변수
	int weight;

public:
	// 멤버	함수
	void set_animal(int _food, int _weight) {
		food = _food;
		weight = _weight;
	}
	void increase_food(int inc) {
		food += inc;
		weight += (inc / 3);
	}
	void view_stat() {
		std::cout << "이 동물의 food : " << food << std::endl;
		std::cout << "이 동물의 weight : " << weight << std::endl;
	}
};

struct DateInfo {
	int mounth;
	int maxday;
};


class Data{
	int year;
	int month;
	int day;

	public:
		bool IsLeapYear() {
			return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		}
		void setDate(int _year, int _month, int _day) 
		{
			year = _year;
			month = _month;
			day = _day;
		};
		void AddDay(int _day) {

			day += _day;

			int maxDay = 31;

			switch (month)
			{
			case 4:
			case 6:
			case 9:
			case 11:
				maxDay = 30;
				break;

			case 2:
				maxDay = IsLeapYear() ? 29 : 28;
				break;
			}

			if (day > maxDay)
			{
				day -= maxDay;
				AddMonth(1);
			}
		}

		void AddMonth(int _month) {

			if (month + _month > 12) 
			{
				AddYear(1);
				month = month + _month - 12;
				return;
			}

			month += _month;
		}
		void AddYear(int _year) {
			year += _year;
		}

		void ShowDate() {
			std::cout << year << "년 " << month << "월 " << day << "일" << std::endl;
		
		}
};

int main() {
	Data date;
	date.setDate(2012, 2, 28);
	date.ShowDate();

	date.AddDay(3);
	date.ShowDate();


	return 0;
	// 자동으로 소멸자 호출
	// 스택메모리 영역에서 사라짐
}

void NewFunction()
{
	Animal animal;
	// 함수 안의 지역 변수
	// 스택에 sizeof(Animal) 크기만큼 메모리 할당
	animal.set_animal(100, 50); // 인스턴스 함수 호출
	animal.increase_food(30);

	animal.view_stat();


	Animal* pAnimal = new Animal();
	(*pAnimal).set_animal(200, 80);
	(*pAnimal).increase_food(60);
	(*pAnimal).view_stat();
	delete pAnimal;
}
