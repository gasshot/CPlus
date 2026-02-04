#include<iostream>

int change_val(int* p) 
{
	*p = 3;

	return 0;
}


// 참조자(Reference)

// 레퍼런스는 반드시 처음에 누구의 별명이 될 것인지 지정해야 합니다.
// int& another_b; 선언만 하는 것은 불가능



int main() 
{
	//int number = 5;

	//std::cout << number << std::endl;
	//change_val(&number);
	//std::cout << number << std::endl;

	int a = 3;
	int& another_a = a;

	another_a = 5;
	std::cout << "a : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;

	return 0;
}