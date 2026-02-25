#include <iostream>

class MyString {
    
    char* text;
    int capacity;

public:
    MyString();
    MyString(char one);
    MyString(const char* str);
    MyString(const MyString& ms);
    char* returnText();
    void showText();
    int showLength();
    char* append(char* second);
    MyString& assign(const char* replace);
    ~MyString();
};
MyString::MyString() {

    text = nullptr;
    capacity = 0;
}

MyString::MyString(char one) {

    // 널 포인터가 들어올 경우 빈 문자열로 처리
    if (one == '\0') {
        text = new char[1];
        text[0] = one;
        capacity = 1;
        return;
    }

    text = new char[2];
    text[0] = one;
    text[1] = '\0';
    capacity = 2;
}

MyString::MyString(const char* str) {
    // 널 포인터가 들어올 경우 빈 문자열로 처리
    if (str == nullptr) {
        text = new char[1];
        text[0] = '\0';
        capacity = 1;
        return;
    }

    int count = 0;
    const char* check = str;

    // 길이 계산 (널 문자 포함)
    while (true) {
        if (*check == '\0') {
            count++;
            break;
        }
        check++;
        count++;
    }

    // 메모리 할당 및 복사
    text = new char[count];
    capacity = count;
    const char* firstAddress = str;

    for (int i = 0; i < count; i++) {
        *(text + i) = *firstAddress;
        firstAddress++;
    }
}

MyString::MyString(const MyString& ms) {

    // 널 포인터가 들어올 경우 빈 문자열로 처리
    if (ms.text == nullptr) {
        text = new char[1];
        text[0] = '\0';
        capacity = 1;
        return;
    }

    int count = 0;
    const char* check = ms.text;

    // 길이 계산 (널 문자 포함)
    while (true) {
        if (*check == '\0') {
            count++;
            break;
        }
        check++;
        count++;
    }

    // 메모리 할당 및 복사
    text = new char[count];
    capacity = count;
    const char* firstAddress = ms.text;

    for (int i = 0; i < count; i++) {
        *(text + i) = *firstAddress;
        firstAddress++;
    }
}

MyString::~MyString() {

    delete[] text;
    text = nullptr; // 지우고 나서 비우는 건 안전하고 좋은 습관입니다!
}

char* MyString::returnText() {
    return text;
}

void MyString::showText() {

    char* check = text;

    while (1)
    {

        if (*check == '\0')
        {

            return;
        }
        std::cout << *check;
        check++;
    }
}

int MyString::showLength() {
    
    int count = 0;
    char* check = text;

    while (1)
    {
        if (*check == '\0')
        {
            std::cout << std::endl;
            std::cout << "문자열 길이 : " << ++count << std::endl;
            std::cout << "메모리 할당량 : " << capacity << std::endl;
            return count;
        }
        check++;
        count++;
    }
}

char* MyString::append(char* second) {
    
    int count = 0;
    char* check1 = text;

    while (1)
    {
        if (*check1 == '\0')
        {
            break;
        }
        check1++;
        count++;
    }
    char* check2 = second;

    while (1)
    {
        if (*check2 == '\0')
        {
            break;
        }
        check2++;
        count++;
    }

    char* newSentence = new char[count + 1];
    capacity = count + 1;

    char* firstAdress = newSentence;
    char* check3 = text;
    while (1)
    {
        if (*check3 == '\0')
        {
            break;
        }
        *newSentence = *check3;
        newSentence++;
        check3++;
    }

    char* check4 = second;

    while (1)
    {
        if (*check4 == '\0')
        {
            break;
        }
        *newSentence = *check4;
        newSentence++;
        check4++;
    }
    *newSentence = '\0';

    // 1. 기존에 내가 살던 낡은 집(메모리) 허물기
    delete[] text;

    // 2. 내 문패(text)를 새롭게 완성된 크고 좋은 집(firstAdress)으로 바꿔 달기!

    text = firstAdress;
    return text;
}

// 매개변수를 const로 변경하고, 반환형을 MyString&로 변경 (선택 사항)
MyString& MyString::assign(const char* replace) {
    // 1. 널 포인터 방어
    if (replace == nullptr) {
        return *this; // 또는 빈 문자열 처리
    }

    // 2. 자기 자신 대입 방지 (입력받은 주소가 내 text 주소와 같다면 복사할 필요 없음)
    if (this->text == replace) {
        return *this;
    }

    // 길이 계산
    int count = 0;
    const char* check = replace;

    while (true) {
        if (*check == '\0') {
            count++;
            break;
        }
        check++;
        count++;
    }

    // 3. 용량 확인 및 재할당 로직 (작성하신 훌륭한 로직 그대로 유지)
    if (count > capacity) {
        delete[] text;
        text = nullptr;
        text = new char[count];
        capacity = count; // 용량 갱신
    }

    // 4. 데이터 복사
    for (int i = 0; i < count; i++) {
        *(text + i) = *(replace + i);
    }

    // 메소드 체이닝을 위해 자기 자신(*this)을 참조로 반환
    return *this;

int main()
{
    char test1[] = "Hello";
    char test2[] = "World!";
    char test3[] = "short";


    MyString ms1(test1);
    MyString ms2(test2);

   ms1.showLength();

   ms1.append(ms2.returnText());
   ms1.showText();
   ms1.showLength();

   ms1.assign(test3);

   ms1.showText();
   ms1.showLength();

   return 0;
}
