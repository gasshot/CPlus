#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>

class Marine 
{
    int hp;
    int coord_x, coord_y;
	int damage;
    bool is_dead;
	char* name;

public:
	Marine(); // 생성자 선언
	Marine(int x, int y, const char* marine_name); // x, y좌표가 있는 생성자 선언
	Marine(int x, int y); // x, y좌표가 있는 생성자 선언
	int attack(); // 공격
	void be_attacked(int damage_earn); // 입은 데미지
	void move(int x, int y); // 이동	

	void show_status(); // 상태 출력
};

Marine::Marine() // 기본 생성자 재정의
{
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
	name = NULL;
}

Marine::Marine(int x, int y) // 매개변수가 있는 생성자 재정의
{
	hp = 50;
	coord_x = x;
	coord_y = y;
	damage = 5;
	is_dead = false;
	name = NULL;
}

Marine::Marine(int x, int y, const char* marine_name) // 매개변수가 있는 생성자 재정의
{
	name = new char[strlen(marine_name) + 1];
	strcpy(name, marine_name);

	hp = 50;
	coord_x = x;
	coord_y = y;
	damage = 5;
	is_dead = false;
}

void Marine::move(int x, int y)
{
	coord_x = x;
	coord_y = y;
}

int Marine::attack()
{
	return damage;
}

void Marine::be_attacked(int damage_earn)
{
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;
}

void Marine::show_status()
{
	std::cout << "*** "<< name <<" *** " << std::endl;
	std::cout << " Location : (" << coord_x << ", " << coord_y << ")" << std::endl;
	std::cout << " HP : " << hp << std::endl;
}
Marine::~Marine() // 소멸자 재정의
{
	std::cout << name << " 의 소멸자 호출!" << std::endl;

	if (name != NULL)
	{
		delete[] name;
	}
}


int main()
{
	Marine* marines[100];

	marines[0] = new Marine(2, 3, "Marine1"); // 기본 생성자 호출
	marines[1] = new Marine(10, 20, "Marine2"); // 매개변수가 있는 생성자 호출

	marines[0]->show_status();
	marines[1]->show_status();

	std::cout << std::endl << "마린1이 마린2를 공격!" << std::endl;
	marines[1]->be_attacked(marines[0]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	int size = sizeof(marines) / sizeof(marines[0]);
	
	// ✔ 타입 문맥이면 → 참조자
	// ✔ 값 앞에 붙으면 → 주소 연산자

	// Marine* ptr = marines[0]; // 주소 연산자 &
	// Marine*& ref = marines[0]; // 참조자 &

	for(auto &m : marines)
	{
		delete m;
		m = nullptr;
	}
}

