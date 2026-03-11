#include <iostream>

class DimensionArray {
    int* arrayAddress;
    int* checkDimension;
    int length;

public:
    DimensionArray(int x1) {

        length = x1;
        arrayAddress = new int[length];
        checkDimension = nullptr;

        for (int i = 0; i < length; i++)
        {
            int* ptr = (arrayAddress + i);
            *ptr = i;
            //printf("%p\n", arrayAddress + i);
            printf("%d\n", *ptr);
        }
    }

    DimensionArray(int x1, int x2) {

        length = x1 * x2;

        arrayAddress = new int[length];
        checkDimension = new int[2];
        checkDimension[0] = x1;
        checkDimension[1] = x2;

        for (int i = 0; i < length; i++)
        {
            printf("%p\n", arrayAddress + i);
        }
    }

    int* operator[](int idx){
        if (idx < 0) {
            return nullptr;
        }

        if (checkDimension == nullptr) 
        {
            // 1차원 배열일 때
            if (idx > length - 1) {
                std::cout << "범위를 벗어났습니다." << std::endl;
                return nullptr;
            }
            return (arrayAddress + idx);
        }

        else {
            // 2차원 배열일 때: idx행의 '시작 주소'를 반환
            // (idx * 열의 개수) 위치의 주소를 주면, 
            // 외부에서 [j]를 사용했을 때 그 주소로부터 j만큼 더 이동하게 됨
            int columnCount = checkDimension[1];
            return (arrayAddress + (idx * columnCount));
        }

        // [0][1][2][3][4][5][6][7]
        // [0][0][0] = [0]
        // [0][0][1] = [1]
        // [0][1][0] = [2]
        // [0][1][1] = [3]
        // [1][0][0] = [4]
        // [1][0][1] = [5]
        // [1][1][0] = [6]
        // [1][1][1] = [7]


    }
    ~DimensionArray() {
        delete[] arrayAddress;
        delete[] checkDimension;    
    }
};


int main() {

    //DimensionArray arr(8);
    //std::cout << *(arr[9]) << std::endl;

    DimensionArray arr(2,2);

    return 0;
}

