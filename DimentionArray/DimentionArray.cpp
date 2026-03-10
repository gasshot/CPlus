#include <iostream>

class DimensionArray {
    int* arrayAddress;
    int firstDimension;
    int secondDimension;
    int thirdDimension;

public:
    DimensionArray(int x1, int x2, int x3) {

        int length = x1 * x2 * x3;

        arrayAddress = new int[length];
        firstDimension = x1;
        secondDimension = x2;
        thirdDimension = x3;
    }

    int* operator[](int idx){
        if (idx >= firstDimension || idx < 0) {
            return nullptr;
        }

        return (arrayAddress + idx);
    }
};

int main() {

    return 0;
}

