#include <iostream>
#include <stdexcept> // std::out_of_range 사용
#include <array>     // std::array 활용 (선택 사항이나 권장됨)

// 1. ArrayView: 다차원 배열의 '부분'을 가리키는 창문 역할
template<typename T, int Dim>
class ArrayView {
    T* data;
    int* stride;
    int* shape;

public:
    ArrayView(T* d, int* s, int* sh)
        : data(d), stride(s), shape(sh) {
    }

    // 다음 차원의 View를 반환 (차원 하나 감소)
    auto operator[](int idx) {
        if (idx < 0 || idx >= shape[0]) {
            throw std::out_of_range("Index out of bounds!");
        }
        return ArrayView<T, Dim - 1>(data + (idx * stride[0]), stride + 1, shape + 1);
    }
};

// 2. ArrayView 특수화: 마지막 1차원일 때 실제 데이터 참조를 반환 (재귀 탈출)
template<typename T>
class ArrayView<T, 1> {
    T* data;
    int size;

public:
    ArrayView(T* d, int* s, int* sh)
        : data(d), size(sh[0]) {
    }

    T& operator[](int idx) {
        if (idx < 0 || idx >= size) {
            throw std::out_of_range("Index out of bounds!");
        }
        return data[idx];
    }
};

// 3. NDArray: 전체 메모리와 구조를 관리하는 메인 클래스
template<typename T, int Dim>
class NDArray {
    T* data;
    int stride[Dim];
    int shape[Dim];

public:
    // 가변 인자 템플릿 생성자: 각 차원의 크기를 직접 받음
    template<typename... Args>
    NDArray(Args... args) {
        // 차원 수와 입력된 인자의 개수가 맞는지 검사
        static_assert(sizeof...(args) == Dim, "The number of arguments must match Dim!");

        int sizes[] = { static_cast<int>(args)... };
        int total = 1;

        // 뒤에서부터 보폭(stride) 계산 (Row-Major Order)
        for (int i = Dim - 1; i >= 0; i--) {
            shape[i] = sizes[i];
            stride[i] = total;
            total *= sizes[i];
        }

        data = new T[total];
    }

    // 소멸자: 메모리 해제
    ~NDArray() {
        delete[] data;
    }

    // 첫 번째 차원의 인덱싱 시작
    auto operator[](int idx) {
        if (idx < 0 || idx >= shape[0]) {
            throw std::out_of_range("Index out of bounds!");
        }
        return ArrayView<T, Dim - 1>(data + (idx * stride[0]), stride + 1, shape + 1);
    }

    // (선택) 복사 방지: 깊은 복사를 구현하지 않을 경우 실수를 막기 위해 금지함
    NDArray(const NDArray&) = delete;
    NDArray& operator=(const NDArray&) = delete;
};

// --- 사용 예시 ---
int main() {
    try {
        // 3차원 배열 선언 (2x3x2 크기)
        NDArray<int, 3> arr(2, 3, 2);

        // 데이터 삽입
        arr[1][2][0] = 10;
        arr[0][1][1] = 5;

        std::cout << "arr[1][2][0] : " << arr[1][2][0] << std::endl;
        std::cout << "arr[0][1][1] : " << arr[0][1][1] << std::endl;

        // 경계 검사 테스트 (에러 발생)
        // std::cout << arr[1][5][0] << std::endl; 

    }
    catch (const std::out_of_range& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;
    }

    return 0;
}