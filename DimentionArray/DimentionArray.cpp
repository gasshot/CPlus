#include <iostream>

class DimensionArray {
    int* arrayAddress;
    int size;

public:
    DimensionArray(int array[], int length) {
        if (length % 2 != 0) {
            return;
        }

        int length = sizeof(array) / sizeof(array[0]);
        arrayAddress = array;
        size = length;

        for (int i = 0; i < size; i++) {
            std::cout << array[i] << std::endl;
        }
    }
};

int main() {
    int array[] = { 1, 2, 3, 4, 5 };
    // sizeof(array)는 main 함수 내에서는 실제 배열 크기를 반환합니다.
    int length = sizeof(array) / sizeof(array[0]);

    DimensionArray da(array, length);
}

