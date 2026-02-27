#include <iostream>

class Immutable {
    int data_;

public:
    Immutable(int data) : data_(data) {}
    void DoSomething(int x) const {
        //data_ = x;  // 불가능!
        // const가 달린 함수는 해당 객체의 상태를 수정할 수없다
    }

    void PrintData() const { std::cout << "Immutable data: " << data_ << std::endl; }
};

class Mutable {
    mutable int data_;

public:
    Mutable(int data) : data_(data) {}
    void DoSomething(int x) const {
        data_ = x;  // 가능!
    }

    void PrintData() const { std::cout << "Mutable data: " << data_ << std::endl; }
};



int main()
{
    Immutable im(10);
    im.DoSomething(3);
    im.PrintData();

    Mutable m(10);
    m.DoSomething(3);
    m.PrintData();

    return 0;
}
