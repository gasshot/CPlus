#define _CRT_SECURE_NO_WARNINGS
// C 스타일 입출력 함수 사용을 위한 헤더 (printf 등)
#include <stdio.h>

// C++ 입출력 스트림(cout, cin)을 사용하기 위한 헤더
#include <iostream>

// C 문자열 처리 함수(strlen, strcpy 등)를 사용하기 위한 헤더
#include <cstring>

// std::cout, std::endl 등을 std:: 접두사 없이 쓰기 위해 사용
// (실무에서는 헤더 파일에서 사용 금지, 예제용)
using namespace std;

// Student 클래스 정의
class Student
{
private:
    // 학생 이름을 저장할 C 스타일 문자열 포인터
    // 실제 문자열 데이터는 힙 메모리에 존재
    char* name;

    // 학생 나이
    int age;

    // 학생 취미를 저장할 C 스타일 문자열 포인터
    char* hobby;

public:
    // 기본 생성자
    // name, hobby를 nullptr로 초기화 → delete[] 안전성 확보
    // age는 0으로 초기화
    Student() : name(nullptr), age(0), hobby(nullptr) {};

    // 소멸자
    // 객체가 소멸될 때 동적 할당한 메모리를 해제
    ~Student()
    {
        delete[] name;   // name이 nullptr이어도 delete[]는 안전
        delete[] hobby;  // hobby도 동일
    }

    // 학생 정보 출력 함수
    void ShowInfo();

    // 학생 정보 설정 함수
    // const char* : 문자열을 수정하지 않겠다는 의도
    void SetInfo(const char* _name, int _age, const char* _hobby);

    // 공부 행동 함수 (출력만 수행)
    void Study();

    // 수면 행동 함수 (출력만 수행)
    void Sleep();

    void Action();
};

int main()
{
    // Student 객체 두 개를 스택 영역에 생성
    Student s1, s2;

    // s1 객체의 정보 설정
    s1.SetInfo("Kim", 18, "Game");

    // s2 객체의 정보 설정
    s2.SetInfo("Lee", 15, "Running");

    // Student 객체를 가리킬 포인터 선언
    Student* ptr;

    // ptr이 s1 객체의 주소를 가리키게 함
    ptr = &s1;

    // 포인터를 통해 s1의 멤버 함수 호출
    ptr->ShowInfo();

    ptr->Action();

    // ptr이 s2 객체의 주소를 가리키게 변경
    ptr = &s2;

    // 포인터를 통해 s2의 멤버 함수 호출
    ptr->ShowInfo();

    ptr->Action();
    // 프로그램 정상 종료
    return 0;
}

// Student 클래스의 ShowInfo 멤버 함수 정의
void Student::ShowInfo()
{
    // cout은 std::ostream 타입의 전역 객체
    // << 는 operator<< 로 오버로딩된 함수
    // name, age, hobby 값을 표준 출력(콘솔)에 출력
    cout << "Name: " << name
        << ", Age: " << age
        << ", Hobby:" << hobby
        << std::endl;   // 줄바꿈 + flush
}

// Student 클래스의 SetInfo 멤버 함수 정의
void Student::SetInfo(const char* _name, int _age, const char* _hobby)
{
    // 기존에 할당된 메모리가 있다면 먼저 해제
    // (재설정 시 메모리 누수 방지)
    delete[] name;
    delete[] hobby;

    // 이름 문자열 길이 + 널 문자('\0')를 위한 공간 할당
    name = new char[strlen(_name) + 1];

    // 전달받은 문자열을 동적 메모리에 복사
    strcpy(name, _name);

    // 나이 설정
    age = _age;

    // 취미 문자열 길이 + 널 문자 공간 할당
    hobby = new char[strlen(_hobby) + 1];

    // 취미 문자열 복사
    strcpy(hobby, _hobby);
}

// 공부 행동을 출력하는 함수
void Student::Study()
{
    // endl은 개행 + 버퍼 flush
    cout << "STUDY" << endl;
}

// 수면 행동을 출력하는 함수
void Student::Sleep()
{
    // 문자열 출력 후 줄바꿈
    cout << "SLEEP" << endl;
}

// 수면 행동을 출력하는 함수
void Student::Action()
{
    //cout << "ACTION CALLED\n";  // ← 이거
    if (age >= 18) 
    {
        Study();
    }

    else
    {
        Sleep();
    }
}
