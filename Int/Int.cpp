#include <iostream>

class Int {
    int data;

public:
    Int(int data) : data(data) {};
    Int(const Int& i) : data(i.data) {};

    operator int() { return data; };
};

class ID_Operator {
    int x;
public:
    ID_Operator(int data) : x(data) {};
    ID_Operator(const ID_Operator& i) : x(i.x) {};

    ID_Operator& operator++() {
        x++;
        std::cout << "전위 증감 연산자" << std::endl;
        return *this;
    }

    ID_Operator operator++(int) {
        ID_Operator temp(*this);
        x++;
        std::cout << "후위 증감 연산자" << std::endl;
        return temp;
    }

    int get_x() const {
        return x;
    }
};

void func(const ID_Operator& t) {
    std::cout << "x : "<< t.get_x() << std::endl;
}

int main()
{
    ID_Operator t(3);

    func(++t); // 4가 출력
    func(t++); // 4가 출력됨
    func(t);
    //std::cout << "x : " << t.get_x() << std::endl;
}


