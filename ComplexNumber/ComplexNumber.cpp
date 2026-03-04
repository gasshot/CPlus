#include <iostream>

class Complex {
private:
    double real, img;
    // 실수(real number)
    // 허수(imaginary number) 

public:
    Complex(double real, double img) : real(real), img(img) {}
    Complex(const Complex& c) { real = c.real; img = c.img; }

    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;
    Complex& operator=(const Complex& c);

    void operator+(const char* str);

    void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }
};

Complex Complex::operator+(const Complex& c) const {
    Complex temp(real + c.real , img + c.img);
    return temp;
}

Complex Complex::operator-(const Complex& c) const {
    Complex temp(real - c.real, img - c.img);
    return temp;
}

Complex Complex::operator*(const Complex& c) const {
    Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
    return temp;
}

Complex Complex::operator/(const Complex& c) const {
    Complex temp(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
        (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;
}

Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    img = c.img;
    return *this;
}

void Complex::operator+(const char* str) {
    int length = 0;
    const char* firstAdress = str;
    while (1) {
    
        if (*firstAdress == '\0') 
        {
            length++;
            break;
        }
        length++;
        firstAdress++; 
    }
    // 2-3i\0
    // 0123 4

    // 3i
    // 01
    std::cout << "길이 : " << length << std::endl;
    int pos = -1;

    for (int i = 0; i < length; i++) {
        
        if (*(str + i) == 'i') 
        {
            pos = i;
            break;
        }
    }
    
    
    int sum = 0;
    // 허수부분이 없습니다.
    if (pos == -1) {
        std::cout << "실수만 존재 : true" << std::endl;

        int pointPos = -1;

        for (int i = 0; i < length; i++) {
            if (*(str + i) == '.') {
                pos = pointPos;
                break;
            }
        }

        if (pointPos == -1) { // 정수다(예 53689)
            std::cout << "정수 : true" << std::endl;
            for (int j = 0; j < length - 1; j++)
            {
                int temp = (int)(*(str + j)) - '0';
                std::cout << "10의 " << length - 1 - (j + 1) << "승 : " << temp << std::endl;
                
                // j = 0일 때
                sum += temp * (int)pow(10, length - 1 - (j + 1));
            }
        }
        else { // 소수점이 있다.

        
        }
    }

    std::cout << "테스트 : " << sum << std::endl;

    //Complex temp;
    //return null;
}

int main() {
    Complex a(1.0, 2.0);
    //Complex b(3.0, -2.0);
    //Complex c(0.0, 0.0);
    //c = a * b + a / b + a + b;
    //c.println();

    a + "53689";
}

