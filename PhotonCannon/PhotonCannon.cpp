// 포토캐논(복사생성자)
#include <string.h>
#include <iostream>

class Photon_Cannon {
    int hp, shield;
	int coord_x, coord_y;
	int damage;

public:
	Photon_Cannon(int x, int y); // 생성자 선언
	Photon_Cannon(const Photon_Cannon& pc); // 생성자 선언

	void show_status(); // 상태 출력
};

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
	std::cout << "복사 생성자 호출!" << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;
}

Photon_Cannon::Photon_Cannon(int x, int y) // 생성자 재정의
{
	std::cout << "생성자 호출!" << std::endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
}

void Photon_Cannon::show_status() {
	std::cout << "Photon Cannon" << std::endl;
	std::cout << " Location : (" << coord_x << ", " << coord_y << ")" << std::endl;
	std::cout << "Hp : " << std::endl;
}


int main()
{
	Photon_Cannon pc1(3, 3); // 생성자 호출
	Photon_Cannon pc2(pc1); // 복사 생성자 호출
	Photon_Cannon pc3 = pc2; // 복사 생성자 호출

	pc1.show_status();
	pc2.show_status();
}

//const Photon_Cannon& pc = pc1;

//이건 이런 의미다 :
//
//pc1이라는 객체가 있다
//
//pc라는 새로운 “접근 경로”를 만든다
//
//하지만 그 경로는 읽기 전용이다
