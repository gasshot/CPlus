#include <iostream>

class Marine {
    int hp;
	int coord_x, coord_y;

	bool is_dead;

	const int default_damage;
public:
	Marine(); // 생성자 선언
	Marine(int x, int y); // x, y 좌표에 마린 생성
	Marine(int x, int y, int default_damage); // x, y 좌표에 마린 생성

	int attack(); // 공격
	void be_attacked(int damage_earn); // 공격 당함
	void move(int x, int y); // 위치 이동

	void show_status(); // 상태 출력
};

// 초기화 리스트 (initializer list) 라고 부르며, 생성자 호출과 동시에 멤버 변수들을 초기화
Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}
Marine::Marine(int x, int y) : hp(50), coord_x(x), coord_y(y), default_damage(5), is_dead(false) {}
Marine::Marine(int x, int y, int default_damage) : hp(50), coord_x(x), coord_y(y), default_damage(default_damage), is_dead(false) {}

void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}

int Marine::attack() {
	return default_damage;
}

void Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) {
		is_dead = true;
	}
}

void Marine::show_status() {
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : (" << coord_x << ", " << coord_y << ")" << std::endl;
	std::cout << " HP : " << hp << std::endl;
}


int main()
{
	Marine marine1(2, 3, 10);
	Marine marine2(3, 5, 10);

	marine1.show_status();
	marine2.show_status();


	std::cout << std::endl << "마린 1이 마린 2를 공격!" << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();

	return 0;
}

