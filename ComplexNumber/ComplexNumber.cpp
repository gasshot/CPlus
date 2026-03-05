#include <iostream>
#include <cmath>
#include <iomanip> // 출력 정밀도 확인용

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
    // 1. 순수 문자열 길이 구하기 (널 문자 제외)
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    // 2. 소수점('.') 위치 찾기
    int pointPos = -1;
    for (int i = 0; i < length; i++) {
        if (str[i] == '.') {
            pointPos = i;
            break;
        }
    }

    double sum = 0;

    // 3. 실수 파싱 로직
    if (pointPos == -1) {
        // Case A: 정수만 있는 경우 (예: "536")
        for (int i = 0; i < length; i++) {
            sum = sum * 10 + (str[i] - '0');
        }
    }
    else {
        // Case B: 소수점이 있는 경우 (예: "53.689")

        // 정수부 계산 (소수점 이전까지)
        for (int i = 0; i < pointPos; i++) {
            sum = sum * 10 + (str[i] - '0');
        }

        // 소수부 계산 (소수점 이후부터 끝까지)
        double decimalWeight = 0.1;
        for (int i = pointPos + 1; i < length; i++) {
            sum += (str[i] - '0') * decimalWeight;
            decimalWeight /= 10.0; // 자릿수가 넘어갈 때마다 0.1, 0.01... 로 감소
        }
    }

    // 4. 결과 출력 (정밀도를 높여서 확인)
    std::cout << "입력 문자열: " << str << std::endl;
    std::cout << "계산된 실수(sum): " << std::fixed << std::setprecision(10) << sum << std::endl;
}


int main() {
    Complex a(1.0, 2.0);
    //Complex b(3.0, -2.0);
    //Complex c(0.0, 0.0);
    //c = a * b + a / b + a + b;
    //c.println();

    a + "536";
}

