#include <iostream>

class MyString {
    

public:
    MyString() {};
    void createString(char one);
    void createString(char* sentence);
    int showLength(char* sentence);
    char* assembleSentence(char* fisrt, char* second);
};

void MyString::createString(char one) {


}

void MyString::createString(char* sentence) {


}

int MyString::showLength(char* strPtr) {
    
    int count = 0;
    char* check = strPtr;

    while (1)
    {
        //std::cout << *check << std::endl;
        if (*check == '\0')
        {
            return count + 1;
        }
        check++;
        count++;
    }
}

char* MyString::assembleSentence(char* fisrt, char* second) {
    
    int count = 0;
    char* check1 = fisrt;

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

    char* firstAdress = newSentence;
    char* check3 = fisrt;
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

    return firstAdress;
}


int main()
{
    char test1[] = "Hello";
    char test2[] = "World!";


    MyString ms;

   int length = ms.showLength(test1);

   std::cout << "문자열의 크기 : " << length << std::endl;

   char* tata = ms.assembleSentence(test1, test2);
   char* startPtr = tata;
   while (1)
   {
       std::cout << *tata;
       if (*tata == '\0')
       {
           break;
       }
       tata++;
   }
   std::cout << std::endl;

   delete[] startPtr;

   return 0;
}
